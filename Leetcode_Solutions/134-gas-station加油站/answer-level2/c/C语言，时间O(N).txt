### 解题思路
先判断油量和花费的大小关系
如果油量大于等于花费，那么说明必定有一个加油站满足条件
从某个加油站a出发，如果无法到达某个加油站b，那么起点换为加油站b（如果从a出发无法到达b的话，那么a和b之间
的加油站都无法到达b)

### 代码

```c
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
	int gassum = 0;
	int costsum = 0;
    //判断油量是否大于等于花费，如果小于，则直接返回-1
	for (int i = 0; i < gasSize; i++) {
		gassum += gas[i];
		costsum += cost[i];
	}
	if (gassum < costsum)
		return -1;

	int index = 0;//用于遍历数组的变量
	int start = 0;//标记起点位置
	int size = gasSize;//总共需要走过的加油站数量
	gassum = 0;
	costsum = 0;
	while (size != 0) {//如果从起点出发能走完所有加油站，那么该起点符合题意
		size--;
		gassum += gas[index];
		costsum += cost[index];
		if (gassum < costsum) {//如果油量不足以到达下一个 加油站b，那么起点变为 加油站b
			index = (index + 1) % gasSize;
			start = index;
			size = gasSize;
			gassum = 0;
			costsum = 0;
		}
		else {
			index = (index + 1) % gasSize;
		}
	}
	return start;
}
```