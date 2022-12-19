
![image.png](https://pic.leetcode-cn.com/fcdd9e19c7a99ce744053a9641ea48402afa185a48af3113c6cc45cc44be0b53-image.png)

```
#define UF_MAX 1001
int g_graph[UF_MAX];

int find_head(int num)
{
	if (g_graph[num] != num) {
		g_graph[num] = find_head(g_graph[num]);
		return g_graph[num];
	} else {
		return num;
    }
}

void set_head(int num, int head)
{
	g_graph[num] = head;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
	int i;

	for(i=0; i< UF_MAX; i++) {
		g_graph[i] = i;
	}

	for(i=0; i<edgesSize; i++) {
		int h1 = find_head(edges[i][0]);
		int h2 = find_head(edges[i][1]);
		if (h1 != h2) {
			set_head(h2, h1);
		} else {
			*returnSize = 2;
			return edges[i];
		}
	}
	return NULL;
}
```
