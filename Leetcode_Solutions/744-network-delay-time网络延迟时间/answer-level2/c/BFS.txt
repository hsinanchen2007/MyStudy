#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAXLEN 101

int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K) {
	int queue[MAXLEN<<3];  //为简化，开大一点
	int dis[MAXLEN] = { 0 };
	int adj[MAXLEN][MAXLEN] = { 0 };
	int head,rear,u,maxTime,i;

	head = rear = maxTime = 0;
    memset(dis,0x7F,sizeof(dis)); //每个点的初始距离初始化为超大值；
    memset(adj,-1,sizeof(adj)); // 0是有效距离，所以置-1

	for (i = 0; i < timesSize; i++) {
		adj[times[i][0]][times[i][1]] = times[i][2];  //邻接矩阵
	}

	queue[rear++] = K;
	dis[K] = 0;

	while (head != rear) {
		u = queue[head++]; //出队
		for (i = 1; i <= N; i++) {
			if (adj[u][i] >= 0 && adj[u][i]+dis[u] < dis[i]){
                queue[rear++] = i; //入队
                dis[i] = adj[u][i]+dis[u];				
			}
		}
	}

	for (i = 1; i <= N; i++) {
        if( dis[i] == 0x7F7F7F7F ) return -1;
		maxTime = MAX(maxTime, dis[i]);
	}

	return maxTime;
}