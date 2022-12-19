### 解题思路
子串、子数组个数问题，选择用滑窗。
模拟一下整个过程，
第一次往前遍历，直到滑窗里面的不同数个数为K;当然这个时候不能继续向前，需要把该数组的**子数组**找出来；
利用双指针，startIndex保存开始坐标，endIndex不断往后移，直到该指针和当前指针构成的子数组刚好不满足要求；那么当前环境下就是子数组数目就是endindex - startIndex + 1;
然后继续往前走，如果当前数组仍然满足条件，就把endIndex往后移，当然它的子数组数目应该是endindex - startIndex + 1;
如果不满足了，就需要刷新startIndex，到刚好满足的位置。

### 代码

```cpp
class Solution {
public:
	void DeleteMapNum(map<int, int>& numCount, int value)
	{
		if (numCount[value] == 1) {
			numCount.erase(numCount.find(value));
		} else {
			numCount[value]--;
		}
	}
	int RefreshPreIndex(vector<int>& A, map<int, int>& numCount, int& preEndIndex, int K)
	{
		while(numCount.size() == K) {
			DeleteMapNum(numCount, A[preEndIndex]);
			preEndIndex++;
		}
		preEndIndex--;
		numCount[A[preEndIndex]] = 1;
        return preEndIndex;
	}
    int subarraysWithKDistinct(vector<int>& A, int K) {
		map<int, int> numCount;
		int curIndex = 0;
        int preStartIndex = 0, preEndIndex = 0;
		int ans = 0;
		while(curIndex < A.size()) {
			if (numCount.find(A[curIndex]) == numCount.end()) {
				numCount[A[curIndex]] = 1;
			} else {
				numCount[A[curIndex]]++;
			}
			if (numCount.size() == K) {
				RefreshPreIndex(A, numCount, preEndIndex, K);
				ans += (preEndIndex - preStartIndex + 1);
			} else if (numCount.size() > K) {
				while(numCount.size() != K) {
					DeleteMapNum(numCount, A[preEndIndex]);
					preEndIndex++;
				}
				preStartIndex = preEndIndex;
				RefreshPreIndex(A, numCount, preEndIndex, K);
				ans += (preEndIndex - preStartIndex + 1);
			}
			curIndex++;
		}
		return ans;
    }
};
```