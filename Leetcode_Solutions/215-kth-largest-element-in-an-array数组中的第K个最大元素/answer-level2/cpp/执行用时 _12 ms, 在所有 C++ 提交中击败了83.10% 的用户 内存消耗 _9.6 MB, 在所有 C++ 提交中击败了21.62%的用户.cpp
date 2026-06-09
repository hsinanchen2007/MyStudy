### 解题思路
执行用时 :12 ms, 在所有 C++ 提交中击败了83.10% 的用户
内存消耗 :9.6 MB, 在所有 C++ 提交中击败了21.62%的用户

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	std::sort(nums.begin(), nums.end(), [](const int& l, const int& r){
    		return l > r;
    	});
//    	//for debug
//    	for(auto& iter:nums){
//    		cout << iter << " ";
//    	}
    	cout << endl;
    	return nums[k-1];
    }
};
```