### 解题思路
dijkstr经典算法，求最短路径，可以参考链接：https://www.cnblogs.com/skywang12345/p/3711512.html#anchor2，大佬讲的很详细。

### 代码

```c
#define MAX_NODE_LEN 101
#define MAXVALUE 65535

int g_matirxGrap[MAX_NODE_LEN][MAX_NODE_LEN];

int Dijkstra(int **times, int timesSize, int vs, int N)
{
	int i, j, k;
	int flag[MAX_NODE_LEN];
	int dist[MAX_NODE_LEN];

	for (i = 1; i <= N; i++) {
		dist[i] = MAXVALUE;
        flag[i] = 0;
	}

	flag[vs] = 1;
	dist[vs] = 0;
    
    for (i = 1; i <= N; i++) {
        if (g_matirxGrap[vs][i] != MAXVALUE) {
            dist[i] = g_matirxGrap[vs][i];
        }
    }

	for (i = 1; i <= N; i++) {
		int min = MAXVALUE;
		for (j = 1; j <= N; j++) {
			if (flag[j] == 0 && dist[j] < min) {
				min = dist[j];
				k = j;
			}
		}
		flag[k] = 1;
		for (int j = 1; j <= N; j++) {
			int tmp = (g_matirxGrap[k][j] == MAXVALUE ? MAXVALUE : (min + g_matirxGrap[k][j]));
			if (flag[j] == 0 && tmp < dist[j]) {
				dist[j] = tmp;
			}
		}
	}

	int maxVal = -1;
	for (i = 1; i <= N; i++) {
		if (flag[i] == 0){
			return -1;
		}
		else {
			maxVal = maxVal < dist[i] ? dist[i] : maxVal;
		}
	}
	return maxVal;
}

int networkDelayTime(int **times, int timesSize, int* timesColSize, int N, int K){
	if (times == NULL || timesSize <= 0 || *timesColSize <= 0) {
		return 0;
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			g_matirxGrap[i][j] = MAXVALUE;
		}
	}

	for (int k = 0; k < timesSize; k++) {
		int i = times[k][0];
		int j = times[k][1];
		g_matirxGrap[i][j] = times[k][2];
	}

	return Dijkstra(times, timesSize, K, N);
}

```