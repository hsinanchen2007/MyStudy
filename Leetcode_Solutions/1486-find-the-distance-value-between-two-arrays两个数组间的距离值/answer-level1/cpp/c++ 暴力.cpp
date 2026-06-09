### 解题思路
模拟一下题目就行了

### 代码

```cpp
class Solution {
public:
	int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		int ans = arr1.size();
		for (int a1 : arr1) {
			for (int a2 : arr2) {
				if (abs(a1 - a2) <= d) {
					--ans;
					break;
				}
			}
		}
		return ans;
	}
};
```