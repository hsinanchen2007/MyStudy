### 解题思路
环一圈，计算出两段的距离，取小的即可

### 代码

```c
int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
	int dis1 = 0, dis2 = 0;;
	int s;
	s = start;
	while (s != destination) {
		dis1 += distance[s];
		s = (s + 1) % distanceSize;
	}
	while (s != start) {
		dis2 += distance[s];
		s = (s + 1) % distanceSize;
	}
	return dis1 < dis2 ? dis1 : dis2;
}
```