#include "WGraphDijkstra.h"
#include <stdlib.h>

void main()
{
         WGraphDijkstra g;
         g.load( "graph.txt" );
         printf("Dijkstra�� �ִܰ�� Ž���� ���� �׷���: graph_sp.txt\n");
         g.display();
		 printf("\n");
         printf("Shortest Path By Dijkstra Algorithm\n");
         g.ShortestPath( 0 );

		 for( int i=1 ; i<7 ; i++ )
			g.PrintPath(0,i);

		 system("pause");
}
