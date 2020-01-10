// Dijkstra알고리즘의 최단 경로 탐색 기능이 추가된 그래프
#include <stdio.h>
#include "WGraph.h"

class WGraphDijkstra : public WGraph {
	int path[MAX_VTXS];     
    int	dist[MAX_VTXS];	// 시작노드로부터의 최단경로 거리
    int found[MAX_VTXS];	// 방문한 정점 표시
public:
	WGraphDijkstra(void) { }
    ~WGraphDijkstra(void){ }

    int chooseVertex() {   // 가장 비용 적은 미방문 정점을 반환
		int min = INF;
		int minpos = -1;

		for( int i=0 ; i<size ; i++ )
			if( dist[i]< min && !found[i] ){
				min = dist[i];
				minpos = i;
		}
		return minpos;
    }

    void printDistance() { // dist[] 값을 출력하는 함수
		for( int i=0 ; i<size ; i++)
			printf("%5d", dist[i]);
		printf("\n");
    }

	// Dijkstra의 최단 경로 알고리즘: start 정점에서 시작함.
    void ShortestPath( int start ) {
		for( int i=0 ; i<size ; i++) {  //초기화: dist[], found[]
			dist[i] = getEdge(start,i);
			found[i] = false;
			path[i] = -1;
		}

		found[start] = true;	// 시작노드 방문 표시(녹색)
		dist[start] = 0;      // 최초 거리

		for( int i=0 ; i<size ; i++ ){
			printf("Step%2d:", i+1);
			printDistance();        // 모든 dist[] 값 출력
			int u = chooseVertex(); // 비용 가작 작은 정점 반환
			found[u] = true;        // ‘방문’으로 표기
			for( int w=0 ; w<size ; w++) {
				if( found[w] == false ) // 방문안한 노드 중에
					if( dist[u] + getEdge(u,w) < dist[w] ){
						dist[w] = dist[u] + getEdge(u,w);
						path[w] = u;
					}
						
			}       // u를 거쳐가는 것이 최단 거리이면 dist[] 갱신
		}
    }

	void PrintDistance() {
		for( int i=0 ; i<size ; i++)
			printf("%5d", dist[i]);
		printf("\n");
    }

	void PrintPath( int start, int end ) {  
		printf("[최단경로 : %c<-%c] %c", getVertex(start), 	getVertex(end), getVertex(end));
		while (path[end] != start) {
		  if(path[end] != -1)
			printf("-%c", getVertex(path[end]));
		  end = path[end];
		}
		printf("-%c\n", getVertex(path[end]));
	}
};