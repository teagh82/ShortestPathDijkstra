// Dijkstra�˰����� �ִ� ��� Ž�� ����� �߰��� �׷���
#include <stdio.h>
#include "WGraph.h"

class WGraphDijkstra : public WGraph {
	int path[MAX_VTXS];     
    int	dist[MAX_VTXS];	// ���۳��κ����� �ִܰ�� �Ÿ�
    int found[MAX_VTXS];	// �湮�� ���� ǥ��
public:
	WGraphDijkstra(void) { }
    ~WGraphDijkstra(void){ }

    int chooseVertex() {   // ���� ��� ���� �̹湮 ������ ��ȯ
		int min = INF;
		int minpos = -1;

		for( int i=0 ; i<size ; i++ )
			if( dist[i]< min && !found[i] ){
				min = dist[i];
				minpos = i;
		}
		return minpos;
    }

    void printDistance() { // dist[] ���� ����ϴ� �Լ�
		for( int i=0 ; i<size ; i++)
			printf("%5d", dist[i]);
		printf("\n");
    }

	// Dijkstra�� �ִ� ��� �˰���: start �������� ������.
    void ShortestPath( int start ) {
		for( int i=0 ; i<size ; i++) {  //�ʱ�ȭ: dist[], found[]
			dist[i] = getEdge(start,i);
			found[i] = false;
			path[i] = -1;
		}

		found[start] = true;	// ���۳�� �湮 ǥ��(���)
		dist[start] = 0;      // ���� �Ÿ�

		for( int i=0 ; i<size ; i++ ){
			printf("Step%2d:", i+1);
			printDistance();        // ��� dist[] �� ���
			int u = chooseVertex(); // ��� ���� ���� ���� ��ȯ
			found[u] = true;        // ���湮������ ǥ��
			for( int w=0 ; w<size ; w++) {
				if( found[w] == false ) // �湮���� ��� �߿�
					if( dist[u] + getEdge(u,w) < dist[w] ){
						dist[w] = dist[u] + getEdge(u,w);
						path[w] = u;
					}
						
			}       // u�� ���İ��� ���� �ִ� �Ÿ��̸� dist[] ����
		}
    }

	void PrintDistance() {
		for( int i=0 ; i<size ; i++)
			printf("%5d", dist[i]);
		printf("\n");
    }

	void PrintPath( int start, int end ) {  
		printf("[�ִܰ�� : %c<-%c] %c", getVertex(start), 	getVertex(end), getVertex(end));
		while (path[end] != start) {
		  if(path[end] != -1)
			printf("-%c", getVertex(path[end]));
		  end = path[end];
		}
		printf("-%c\n", getVertex(path[end]));
	}
};