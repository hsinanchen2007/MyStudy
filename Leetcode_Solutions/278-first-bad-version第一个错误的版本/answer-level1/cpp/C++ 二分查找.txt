### 解题思路
二分查找的经典问题：“寻找有序序列中第一个满足某条件的元素的位置”
时间复杂度：O(logn)。
空间复杂度：O(1)。

### 代码

```cpp
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int pLeft = 1, pRight = n;
		while (pLeft < pRight)
		{
			int mid = pLeft + (pRight - pLeft) / 2;
			if (isBadVersion(mid)) {
				pRight = mid;
			}
			else
			{
				pLeft = mid + 1;
			}
		}
		return pLeft;
	}
};
```