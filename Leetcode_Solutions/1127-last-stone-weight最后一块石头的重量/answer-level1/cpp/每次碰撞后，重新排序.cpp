### 解题思路
每次碰撞后，重新排序

### 代码

```cpp
class Solution {
public:
	int lastStoneWeight(vector<int>& stones)
	{	//ab
		if (stones.size() <= 0)
			return 0;
		if (stones.size() == 1)
			return stones[0];
		int num = stones.size();
		sort(stones.begin(), stones.end());
		
		while (stones[num - 2] > 0)
		{
		
			stones[num - 1] = stones[num - 1] - stones[num - 2];
			stones[num - 2] = 0;
			
			sort(stones.begin(), stones.end());	
		}
		return stones[num -1];
	}
};
```