搜索地图中节点到某些节点最近的距离，这种算法实际上计算所有的节点的最短距离。这类题首先想到的是通过BFS进行搜索，即：
从某个需要计算的节点开始，对周边4个方向进行搜索，不断的延伸，直到找到一个满足要求的节点，计算出对应的距离即可。因此不断的加入新访问的节点。最终找到最小的距离。这种方法需要对所有的节点进行遍历。修改代码之后通过了大部分用例，但是大规格用例失败，报超时，因此分析是因为遍历大规格节点的过程中导致时间超时。

```
int DistanceBFS(int** grid, int gridSize, int x, int y)
{
	Queue_t *queue = QueueInit(10240);
	if (queue == NULL) {
		return 0;
	}

	int *mark = malloc(sizeof(int) * gridSize * gridSize);
	memset(mark, 0, sizeof(int) * gridSize * gridSize);
	int distance = -1;

	QueuePush(queue, CreateNode(x, y));

	while (!IsQueueEmpty(queue)) {
		Node_t *n = QueueHead(queue);
		QueuePop(queue);
		mark[n->x * gridSize + n->y] = 1;
		if (*(*(grid + n->x) + n->y) == 1) { 
			distance = Distance(x, y, n->x, n->y);
			free(n);
			break;
		}
		if (n->y - 1 >= 0 && mark[n->x * gridSize + n->y - 1] != 1) {
			QueuePush(queue, CreateNode(n->x, n->y - 1));
		}

		if (n->y + 1 < gridSize && mark[n->x * gridSize + n->y + 1] != 1) {
			QueuePush(queue, CreateNode(n->x, n->y + 1));
		}

		if (n->x - 1 >= 0 && mark[(n->x - 1) * gridSize + n->y] != 1) {
			QueuePush(queue, CreateNode(n->x - 1, n->y));
		}

		if (n->x + 1 < gridSize && mark[(n->x + 1) * gridSize + n->y] != 1) {
			QueuePush(queue, CreateNode(n->x + 1, n->y));
		}
		free(n);
	}

	free(mark);
	QueueDestory(queue);

	return distance;
}

int maxDistance(int** grid, int gridSize, int* gridColSize)
{
	if (CheckParam(grid, gridSize, gridColSize)) {
		return -1;
	}

	int max = -1;
	for (int i = 0; i < gridSize; ++i) {
		for (int j = 0; j < gridColSize[i]; ++j) {
			if (*(grid[i] + j) == 0) {
				int distance = DistanceBFS(grid, gridSize, i, j);
				if (distance > max) {
					max = distance;
				}
			}
		}
	}

	return max;
}
```

在遍历过程中会经过其他的节点，记录下当前遍历过程中的上一层节点，然后在找到最短距离的节点之后，通过保存的上一层节点，计算出通过的节点的距离，这样针对较大规模的地图能够提高效率。通过这种方法减少了成立路径的相关节点的二次搜索。通过这个思路修改之后的代码如下：
```
int DistanceBFS(int** grid, int gridSize, int x, int y, int *distances)
{
	Queue_t *queue = QueueInit(1024);
	if (queue == NULL) {
		return 0;
	}

	char *mark = malloc(sizeof(char) * gridSize * gridSize);
	memset(mark, 0, sizeof(char) * gridSize * gridSize);
	Node_t **parent = malloc(sizeof(Node_t *) * gridSize * gridSize);
	memset(parent, 0, sizeof(Node_t *) * gridSize * gridSize);
	int distance = -1;

	QueuePush(queue, CreateNode(x, y));

	while (!IsQueueEmpty(queue)) {
		Node_t *n = QueueHead(queue);
		QueuePop(queue);
		mark[n->x * gridSize + n->y] = 1;
		if (*(*(grid + n->x) + n->y) == 1) { 
			distance = Distance(x, y, n->x, n->y);
			int i = 1;
			Node_t *prev = NULL;
			while (i < distance) {
				prev = parent[n->x * gridSize + n->y];
				distances[prev->x * gridSize + prev->y] = Distance(prev->x, prev->y, n->x, n->y);
				free(n);
				n = prev;
				i++;
			}

			break;
		}
		if (n->y - 1 >= 0 && mark[n->x * gridSize + n->y - 1] != 1) {
			parent[n->x * gridSize + n->y - 1] = n;
			QueuePush(queue, CreateNode(n->x, n->y - 1));
		}

		if (n->y + 1 < gridSize && mark[n->x * gridSize + n->y + 1] != 1) {
			parent[n->x * gridSize + n->y + 1] = n;
			QueuePush(queue, CreateNode(n->x, n->y + 1));
		}

		if (n->x - 1 >= 0 && mark[(n->x - 1) * gridSize + n->y] != 1) {
			parent[(n->x - 1) * gridSize + n->y] = n;
			QueuePush(queue, CreateNode(n->x - 1, n->y));
		}

		if (n->x + 1 < gridSize && mark[(n->x + 1) * gridSize + n->y] != 1) {
			parent[(n->x + 1) * gridSize + n->y] = n;
			QueuePush(queue, CreateNode(n->x + 1, n->y));
		}
	}

	free(mark);
	free(parent);
	QueueDestory(queue);

	return distance;
}

int maxDistance(int** grid, int gridSize, int* gridColSize)
{
	if (CheckParam(grid, gridSize, gridColSize)) {
		return -1;
	}

	int max = -1;
	int *distances = (int *)malloc(sizeof(int) * gridSize * gridSize);
	memset(distances, 0, sizeof(int) * gridSize * gridSize);

	for (int i = 0; i < gridSize; ++i) {
		for (int j = 0; j < gridColSize[i]; ++j) {
			if (*(grid[i] + j) == 0 && distances[gridSize * i + j] == 0) {
				int distance = DistanceBFS(grid, gridSize, i, j, distances);
				if (distance > max) {
					max = distance;
				}
			}
		}
	}

	return max;
}
```

通过上述方法修改之后，有一部分用例能够通过，但是还是无法全部通过，反馈原因内存超限，只能调整对应的思路，在无权重的图中，可以通过广度搜索的方式获取到最短路径，参照基本的思路，如下所示，持续的进行松弛操作，直到所有的节点无法再进行松弛操作即达到了最终的最小距离。

```
BFS(s):
    InitSSSP(s)
    Push(s)
    while the queue is not empty
        u ← Pull( )
        for all edges u->v
            if dist(v) > dist(u) + 1 //如果u->v是松弛的，则直接修改
                dist(v) ← dist(u) + 1
                pred(v) ← u
                push(v)
```
参照这个思路定义陆地自身的路径长度为0，其他非路径单元格的路径长度为正无穷大（或者一个很大的值），然后将所有陆地的节点添加到队列中，然后从队列中取出对应的节点，然后不断的进行松弛操作，由于进行松弛操作之后，还会影响周边的连接节点，因此把进行松弛的节点添加到队列中，反复进行该操作，最终直到无法进行进一步的松弛操作即可完成最终所有节点的最小路径。
```
void InitDIstance(int **grid, int gridSize, Queue_t *queue, int *distance)
{
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            if (*(grid[i] + j) == 1) {
                distance[i * gridSize + j] = 0;
                QueuePush(queue, CreateNode(i, j));
            } else {
                distance[i * gridSize + j] = MAX;
            }
        }
    }
}

void DistanceBFS(int **grid, int gridSize, Queue_t *queue, int *distance)
{
    while (!IsQueueEmpty(queue)) {
        Edge_t *n = QueueTop(queue);
        QueuePop(queue);

        int direction[MAXDIRECTION][MAXSTEP] = {
            { -1, 0 },
            { 1, 0 },
            { 0, 1 },
            { 0, -1 }
        };

        for (int i = 0; i < MAXDIRECTION; i++) {
            int newX = n->x + direction[i][0];
            int newY = n->y + direction[i][1];

            if (newX >= 0 && newX < gridSize && newY >=0 && newY < gridSize) { 
                if (distance[newX * gridSize + newY] > distance[n->x * gridSize + n->y] + 1) { //满足松弛操作
                    distance[newX * gridSize + newY] = distance[n->x * gridSize + n->y] + 1; //执行松弛操作
                    QueuePush(queue, CreateNode(newX, newY)); //添加到队列中
                }
            }
        }

        free(n);
    }
}

int GetMaxDistance(int **grid, int gridSize, int *gridColSize, int *distance)
{
    int max = -1;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[i]; ++j) {
            if (distance[i * gridSize + j] > max) {
                max = distance[i * gridSize + j];
            }
        }
    }

    return max;
}

int maxDistance(int **grid, int gridSize, int *gridColSize)
{
    if (CheckParam(grid, gridSize, gridColSize)) {
        return -1;
    }

    Queue_t *queue = QueueInit(MAXQUEUE);
    if (queue == NULL) {
        return 0;
    }

    int *distance = (int *)malloc(sizeof(int) * gridSize * gridColSize[0]);
    InitDIstance(grid, gridSize, queue, distance);

    if (IsQueueEmpty(queue) || QueueSize(queue) == gridSize * gridColSize[0]) {
        return -1;
    }

    DistanceBFS(grid, gridSize, queue, distance);
    return GetMaxDistance(grid, gridSize, gridColSize, distance);
}
```

