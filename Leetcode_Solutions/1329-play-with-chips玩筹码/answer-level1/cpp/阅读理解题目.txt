### 解题思路
这个题目就是题目难的读懂，简单说就是chips里面存的是筹码在数轴上的位置，然后需要把所有的筹码都移动到同一个位置。至于为什么是比较奇数和偶数的个数，进行一下预处理就很好理解了，偶数移动偶数步一定可以移动到位置0，奇数移动偶数步一定可以移动到位置1，然后就很简单了，比较是位置0上的数（偶数）少还是位置1上的数（奇数）少就行了

### 代码

```cpp
class Solution {
public:
	int minCostToMoveChips(vector<int> & chips) {
		int nEvenCount = 0;
		int nOddCount = 0;
		int nSize = chips.size();
		for (int i = 0; i < nSize; ++i) {
			if (chips[i] & 1) {
				nOddCount++;
			}
			else {
				nEvenCount++;
			}
		}
		return min(nEvenCount, nOddCount);
	}
};
```