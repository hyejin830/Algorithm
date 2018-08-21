#include <iostream>
#include <queue>
using namespace std;

int Graph[1001][1001] = { 0 };
int DFSvisit[1001] = { 0 };
int BFSvisit[1001] = { 0 };


void bfs(int v, int N) {
	queue<int> q;
	q.push(v);
	BFSvisit[v] = 1;
	while (!q.empty()) {
		v = q.front();
		cout << q.front() << ' ';
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (Graph[v][i] == 1 && BFSvisit[i] == 0) {
				q.push(i);
				BFSvisit[i] = 1;
			}
		}
	}

}

int main() {

	// N : 정점의 개수 M : 간선의 개수
	int N, M, Start;
	cin >> N >> M >> Start;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		//양 방향 간선 연결, 인접행렬 
		Graph[x][y] = 1;
		Graph[y][x] = 1;
	}


	cout << endl;
	bfs(Start, N);

	return 0;
}