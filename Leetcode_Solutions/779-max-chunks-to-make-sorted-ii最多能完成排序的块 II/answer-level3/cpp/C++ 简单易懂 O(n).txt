对于第i个数 当且仅当i和它前面所有数的最大值 小于 i后面所有数的最小值时 可以把i和它前面的数分出去 结果 + 1 复杂度O(n)

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
	vector<int> mxA(arr.size());
	vector<int> mnA(arr.size());
	int mx = INT_MIN;
	for (int i = 0; i < arr.size(); ++i)
	    mxA[i] = mx = max(mx, arr[i]);
	int mn = INT_MAX;
	for (int i = arr.size() - 1; i >= 0; --i)
	    mnA[i] = mn = min(mn, arr[i]);
	int result = 0;
	for (int i = 0; i < arr.size(); ++i)
	    if (i == arr.size() - 1 || mxA[i] <= mnA[i + 1])
		++result;
	return result;
    }
};
```