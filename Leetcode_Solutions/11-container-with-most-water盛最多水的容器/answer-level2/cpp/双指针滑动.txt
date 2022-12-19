### 解题思路
双指针，水的总量取决于双指针中的小值，所以每次循环只需要移动较小值的指针即可

### 代码

```cpp
class Solution {
public:
	int maxArea(vector<int>& height) {
		vector<int>::iterator itBegin = height.begin();
		vector<int>::iterator itEnd = height.end();
		itEnd--;
		int maxWater = 0;
		while (itBegin != itEnd) {
			int maxTemp = min(*itBegin, *itEnd) * (itEnd - itBegin);
			if (maxTemp > maxWater) {
				maxWater = maxTemp;
			}
			if (*itBegin <= *itEnd) {
				itBegin++;
			}else{
				itEnd--;
			}
		}
		return maxWater;

	}
};
```