### 解题思路
按照规则模拟游戏，根据找到x的次数count来判断最终谁输谁赢：count为奇数则true，为偶数则false

### 代码

```cpp
class Solution 
{
public:
	bool divisorGame(int N) 
	{
		int count = 0;
		game(N, count);
		return (count % 2 == 1) ? true : false;
	}

	void game(int N, int &count)
	{
		if (N != 0)
		{
			for (int i = 1; i < N; ++i)
			{
				if (N % i == 0)
				{
					count++;
					return game(N - i, count);
				}
			}
		}
	}
};
```