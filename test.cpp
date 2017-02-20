#include <iostream>
#include <unordered_map>
#include <sstream>
#include "graph.h"
#include <fstream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main(){
	int vertex_size = 329;
	Graph graph(vertex_size);
	std::string line;
	std::unordered_map<int, int> lookup;
	
	static int count=0;
	auto get_id = [&](int label)
	{
		auto tmp = lookup[label];
		if(tmp == 0){
			lookup[label] = ++count;
			graph[count].label = label;
			return count;
		}
		else return tmp;

	};
	std::ifstream fin("graph.csv");
	int from, to;
	char seperator;
	while(fin>>from>>seperator>>to){
		add_edge(graph, get_id(from), get_id(to));
	}
	//cerr << "hehe " << graph[3].edges<< endl;
	//auto temp = transpose(graph);
	// depth_first_search(graph);
	// breath_first_search(graph, 2);
	// test_skeleton(graph);
	// cout <<endl;
	std::ofstream sccggout("scc_graph.csv");
	std::ofstream scc_count_out("scc_count.txt");
	auto ans = strong_connected_component(graph);
	auto scc_graph = std::move(ans.first);
	auto scc_map = std::move(ans.second);
	for(auto &v:scc_graph){
		FOR_EDGE(e,v){
			sccggout<<v.from<<","<<e->to<<endl;
		}
	}
	
	std::unordered_map<int,std::vector<int>> counter;
	for(auto i= 0 ; i < scc_map.size(); ++i){
		int scc_id = scc_map[i];
		counter[scc_id].push_back(graph[i].label);
	}

	scc_count_out<<"scc_label\tsize\t[raw vertex labels]"<<endl;
	for(auto& it:counter){
		scc_count_out<<it.first<<"\t\t"<<it.second.size()<<"\t[";
		for(auto lab:it.second){
			scc_count_out<<lab<<",";
		}
		scc_count_out<<"]"<<endl;
	}
	
    return 0;
}