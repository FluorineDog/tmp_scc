#include <iostream>
#include "graph.h"
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
int main(){
	int vertex_size;
	cin >> vertex_size;
	Graph graph(vertex_size);
	int from, to;
	while(cin>>from>>to){
		add_edge(graph, from, to);
		//add_edge(graph, to, from);
	}
	//cerr << "hehe " << graph[3].edges<< endl;
	//auto temp = transpose(graph);
	depth_first_search(graph);
	breath_first_search(graph, 2);
	// auto vec = topological_sort(graph);
	auto pp = strong_connected_component(graph);
	auto vec = topological_sort(pp.first);
	for(auto vertex: pp.first){ 
		cout<< vertex.parent << '-' << vertex.discover_time
			<< '-' <<vertex.finish_time<<'\t';
	}
	std::cout << endl << endl;
	
	for(auto vertex:pp.first){
		FOR_EDGE(edge, vertex){
			cout << vertex.from << "->" << edge->to << endl;
		}
	}
	std::cout << endl << endl;
	
	for(auto x: vec){
		cout << x << '\t';
	}
	std::cout << endl << endl;
	
	int temp= 0;
	for(auto x: pp.second){
		cout << temp++ << '-'<< x << "\t";
	}
	cout << endl;
	
    return 0;
}