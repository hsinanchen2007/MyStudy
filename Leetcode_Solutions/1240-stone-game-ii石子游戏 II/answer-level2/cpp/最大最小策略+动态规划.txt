### 解题思路
思路用注释标出，请看代码。dp_alex[M][start]表示对某个M，alex在piles的vector中从start开始到piles的结束所取得的最大值，dp_lee[M][start]表示对某个M，alex在piles的vector中从start开始到piles的结束所取得的最小值。

### 代码

```cpp
class Solution {
public:
int catchStones(vector<int>&piles, int start, int**dp_alex, int**dp_lee,bool alexTurn,int M,int*sumOfPre,int numOfpile)
{
	if (alexTurn)//这部分为该回合为alex回合所执行的代码。
	{
		if (dp_alex[M][start] != -1)//如果之前已经计算过该状态的结果，直接返回。
			return dp_alex[M][start];
		else
		{
			int re = 0;
			int max = 0;
			if (numOfpile - start <= 2 * M)//如果可以一次取完，就一次取完时，得到最多石头。
			{
				if (start > 0)//以下三行表示求子数组和，即取了剩下所有堆的石子数量和。例如:设sn为和数列，则sj-si为i到j的片段和。
					re = sumOfPre[numOfpile - 1] - sumOfPre[start - 1];//可以类比所举的例子理解。
				else re = sumOfPre[numOfpile - 1];
				max = re;
			}
			else//不能一次取完时
			{
				for (int X = 1; X <= 2 * M; X++)//遍历所有该回合取石头的可能
				{
					if (start > 0)
					{
						re = sumOfPre[X + start - 1] - sumOfPre[start - 1];//求该回合取出的石头数。
					}
					else
					{
						re = sumOfPre[X - 1 + start];
					}
					int m = M > X ? M : X;
					m = m > numOfpile ? numOfpile : m;
					re += catchStones(piles, start+X, dp_alex, dp_lee, !alexTurn, m, sumOfPre, numOfpile);
                    //原来的re为该回合所取石头数，现在再加上lee回合后所能取得石头最大数，在取所有re的最大值，即为从start开始取得/                    //石头最多的数
					if (re >= max)
						max = re;
				}
			}
			dp_alex[M][start] = max;
			return max;
		}
	}
	else//以下为lee的回合的策略，lee回合目标是使lee回合取石头后，接下来的alex回合以后，alex取最小，其余部分可以类比刚才的注释
	{
		if (dp_lee[M][start] != -1)
			return dp_lee[M][start];
		else
		{
			int re = 0;
			int min = sumOfPre[numOfpile - 1];
			if (numOfpile - start <= 2 * M)
			{
				min = 0;//如果一次能取完，那么就取完，让接下来alex取不了。
			}
			else
			{
				for (int X = 1; X <= 2 * M; X++)
				{
					int m = M > X ? M : X;
					m = m > numOfpile ? numOfpile : m;
					re = catchStones(piles, start + X, dp_alex, dp_lee, !alexTurn, m, sumOfPre, numOfpile);
                    //该循环中遍历所有取石头的可能所对应的接下来的局势，alex所取石头的最大值，取最大值的最小从而为自己增添胜算
					if (re <min)
						min = re;
				}
			}
			dp_lee[M][start] = min;//保存该状态结果以备下一次需要。
			return min;
		}
	}
}
    int stoneGameII(vector<int>& piles) {
    if(piles.size()==0)
    return 0;
    if(piles.size()==1)
    return piles[0];
    int size = piles.size();
	int**dp_alex = new int*[size];
	int**dp_lee = new int*[size];
	int*sumOfPre = new int[size];
	sumOfPre[0] = piles[0];
	for (int i = 1; i < size; i++)
		sumOfPre[i] = piles[i] + sumOfPre[i - 1];
	for (int i = 0; i < size; i++)
	{
		dp_alex[i] = new int[size];
		dp_lee[i] = new int[size];
		for (int j = 0; j < size; j++)
			dp_alex[i][j] = dp_lee[i][j] = -1;
	}
	int re = catchStones(piles, 0, dp_alex, dp_lee, true, 1, sumOfPre, size);
	return re;
    }
};
```