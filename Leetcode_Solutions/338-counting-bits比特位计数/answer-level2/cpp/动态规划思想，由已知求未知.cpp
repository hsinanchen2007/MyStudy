### 解题思路
动态规划思想，由已知求未知，打败99%

### 代码

```cpp
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> result = { 0 };
		int highLevelNum;

		for (int i = 1; i <= num; i++)
		{
			if (result[i - 1] & 1 == 0)
			{
				result.push_back(result[i - 1] + 1);
			}
			else 
			{
				//从右到左，首个0往右的低位1过滤掉，留下highLevelNum
				highLevelNum = i - 1 & i;
				//若highLevelNum是0，即i-1==(2^n)-1，则由于进位result[i]=1
				//若highLevelNum非0，则结果是highLevelNum中1的个数+1，hightLevelNum小于i，其result已知
				result.push_back(highLevelNum == 0 ? 1 : result[highLevelNum] + 1);
			}
		}

		return result;
	}
};
```