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
		add_edge(graph, to, from);
	}
	cerr << "hehe " << graph[3].edges<< endl;
	auto temp = transpose(graph);
	breath_first_search(temp, 2);
	for(auto vertex: temp){ 
		cout<<vertex.parent << '-' << vertex.discover_time<<'\t';
	}
	cout << std::endl;
    return 0;
}