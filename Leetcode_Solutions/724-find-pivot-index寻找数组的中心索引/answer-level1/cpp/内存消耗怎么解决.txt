### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
		int Length = nums.size();		
		if(Length == 0)
			return -1;

		int Index = 0;
		int RightSum = 0;
        int LeftSum = 0;

		for(vector<int>::iterator iRight = nums.begin(); iRight != nums.end(); iRight++)
		{
			RightSum += *iRight;
		}

		for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			LeftSum += *it;
			if(LeftSum == RightSum)
				break;
			else
			{
				RightSum -= *it;
				Index++;
			}
		}

		if(Index<Length)
			return Index;
		return -1;
    }
};
```