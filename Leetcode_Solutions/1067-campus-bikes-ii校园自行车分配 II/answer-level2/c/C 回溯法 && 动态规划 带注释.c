因为回溯法有固定格式，所以一开始用的回溯法
```
void assignBikesCore(int workersSize, int bikesSize, int* used, int** cost, int result, int cur, int* min);
int Manhattan(int* woker, int* bike);

int assignBikes(int** workers, int workersSize, int* workersColSize, int** bikes, int bikesSize, int* bikesColSize){
	
	int* used = (int*)calloc(bikesSize, sizeof(int));
	
	int min = INT_MAX;
	
	int** cost = (int**)malloc(workersSize * sizeof(int*));
	
	for(int i = 0; i < workersSize; i++)
	{
		cost[i] = (int*)malloc(bikesSize * sizeof(int));
		for(int j = 0; j < bikesSize; j++)
		{
			cost[i][j] = Manhattan(workers[i], bikes[j]);
		}
	}
	
	assignBikesCore(workersSize, bikesSize, used, cost, 0, 0, &min);
	
	free(used);
	free(cost);
	return min;
}



void assignBikesCore(int workersSize, int bikesSize, int* used, int** cost, int result, int cur, int* min)
{
	if(cur == workersSize) //工人计算完了，更新最小值
	{
		(*min) = result; // 进递归之前就应该判断过，所以此时result一定比min 小。
		return; //返回 居然忘了返回
	}
	
	for(int i = 0; i < bikesSize; i++) // 遍历bike；
	{
		if(used[i] == 0)
		{
			int temp = result + cost[cur][i];
			
			if(temp > (*min))  // 如果计算出的temp比（*min）还大，就每必要继续算下去了
			{
				continue;
			}
			
			used[i] = 1;
			assignBikesCore(workersSize, bikesSize, used, cost, temp, cur + 1, min);
			used[i] = 0;
		}
	}
	
	
}


int Manhattan(int* woker, int* bike)
{
	return (abs(woker[0] - bike[0]) + abs(woker[1] - bike[1]));
}
```

但是性能太差， 596ms

学习了c速度第一的答案，重写了一遍。
最后是4ms，

用的dp，思路是，对于workers， 从左到右依次分配（和回溯法一样）。

那么bikes的分配状态就可以描述整个的状态了。
可以使用一个int值的各位描述对应bike的分配状态。
所以有dp[state] = MIN(dp[nextState_j] + cost[j])。（其中j是当前state下可以分配的车）

动态规划应该是先算小后算大，不过因为使用state描述bikes的分配状态，使用循环很难描述出计算的先后顺序。
所以使用了递归，并且用-1标记dp， 当我们需要用到dp[i]时如果它为-1，说明dp[i]还没算过，那么就先算出dp[i]。 

dp 的边界是dp[state中有workersSize 个 1 时] = 0；
但实际程序中并不把dp[state中有workersSize 个 1 时] = 0，放入dp，
而是使用workerLeft 即剩余工人，因为剩余工人 + state中1的个数 = workersSize;
所以程序可以写成workerLeft == 0 时， return 0;
也可以在workerLeft == 1 时 修改求返回值的方式，提前终止递归。



注意车比工人多。

```
define STATEMAX 1024  // bikesSize <= 10, 所以最多十位， 1024
#define MIN(X,Y) (X < Y ? X : Y)

int assignBikesCore(int workerLeft, int state, int* dp, int** cost, int bikesSize);
int getState(int state, int index);
int setState(int state, int index);
int Manhattan(int* woker, int* bike);

int assignBikes(int** workers, int workersSize, int* workersColSize, int** bikes, int bikesSize, int* bikesColSize){
	
	int dp[STATEMAX]; //dp中元素的意义是， 在bike 分配情况为state时，还需要至少多少的曼哈顿距离。 显然，dp[0]即为所求 dp[state中有workersSize 个 1 时] = 0
	
	for(int i = 0; i < STATEMAX; i++)
	{
		dp[i] = -1; //dp[i]是可能为0的。
	}
	
	int** cost = (int**)malloc(workersSize * sizeof(int*));
	
	for(int i = 0; i < workersSize; i++)
	{
		cost[i] = (int*)malloc(bikesSize * sizeof(int));
		for(int j = 0; j < bikesSize; j++)
		{
			cost[i][j] = Manhattan(workers[workersSize - 1 - i], bikes[j]);
		}
	}  // 使用cost，保存Manhattan距离
	
	int state = 0; //表示bike分配情况。

	int ret = assignBikesCore(workersSize, state, dp, cost, bikesSize);

	free(cost);

	return ret;
}

/**
 * workerLeft ： 剩余的工人， 使用剩余的工人只需要一个参数，如果用已经分配了车的工人，需要传入两个参数。
 * state ： bike的分配状态， 因为是按照工人从左到右的顺序分配，所以bike的分配状态，即等于整个的状态。
 * dp ： dp[state] 即为在当前状态state下，还需要多少的距离
 * cost : Manhattan距离， 因为只使用workleft做参数， 所以cost[i][j]并不是Manhattan(workers[i], bikes[j]) 而是 Manhattan(workers[workersSize - i], bikes[j])
 * 返回值： 在workleft，state 状态下， 还至少还需要多少距离
 */


int assignBikesCore(int workerLeft, int state, int* dp, int** cost, int bikesSize) // 
{
    int ret = INT_MAX;

	if(workerLeft == 1) //n <= m 即使只有一位工人，仍然可能有多辆车。仍然需要选择
	{
		for(int j = 0; j < bikesSize; j++)
		{
			if(!getState(state, j)) // getState 返回在第j位的值。
			{
                ret = MIN(ret, cost[workerLeft - 1][j]);
			}
		}
        return ret;
	}
	
	for(int j = 0; j < bikesSize; j++)
	{
		if(!getState(state,j)) //对于没有分配的车
		{
			int newState = setState(state, j); //分配车
			
			if(dp[newState] == - 1) //如果这个状态之前没算过
			{
				dp[newState] = assignBikesCore(workerLeft - 1, newState, dp, cost, bikesSize);
			}

			ret = MIN(ret, dp[newState] + cost[workerLeft - 1][j]);
		}
	}
	
	return ret;
	
}

int getState(int state, int index)
{
	return state & (1 << index);
}

int setState(int state, int index)
{
	return state | (1 << index);
}


int Manhattan(int* woker, int* bike)
{
	return (abs(woker[0] - bike[0]) + abs(woker[1] - bike[1]));
}
```

