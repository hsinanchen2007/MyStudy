### 解题思路
快排，知道找到下标为k的数为止
不要全部排序
开始：nBegin
结束: nSize
如果当前得到的下标 nS大于 k,则排序 nBegin---nS - 1；
如果当前得到的下标 nS小于 k,则排序 nS + 1---nSize；
### 代码

```cpp
class Solution {
public:
   	vector<int> getLeastNumbers(vector<int>& arr, int k)
	{
		int nBegin = 0,
			nSize = arr.size();
		if (nSize < k)
		{
			return vector<int>();
		}
		while (nBegin < nSize - 1)
		{
			int nS = nBegin, nE = nSize - 1;
			int nX = arr[nS];
			while (nS < nE)
			{
				while (nS < nE && arr[nE] >= nX)
				{
					nE--;
				}
				if (nS < nE)
				{
					arr[nS] = arr[nE];
					nS++;
				}
				while (nS < nE && arr[nS] <= nX)
				{
					nS++;
				}
				if (nS < nE)
				{
					arr[nE] = arr[nS];
					nE--;
				}

			}
			arr[nS] = nX;
			if (nS == k - 1)
			{
				break;
			}
			else if (nS < k - 1)
			{
				nBegin = nS + 1;
			}
			else
			{
				nSize = nS;
			}
		}
		
		return vector<int>(arr.begin(), arr.begin() + k);
	}
};
```