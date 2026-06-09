### 解题思路
执行用时 :84 ms, 在所有 C++ 提交中击败了14.29% 的用户
内存消耗 :13.3 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	map<int, int> nums_record;
    	for(size_t i=0;i<nums.size();++i){
    		nums_record[nums[i]]++;
    	}
    	vector<pair<int,int>> v_nums_record(nums_record.begin(), nums_record.end());
    	std::sort(v_nums_record.begin(), v_nums_record.end(), [](pair<int,int>& l, pair<int,int>& r){
    		return l.second < r.second;
    	});
    	return v_nums_record[0].first;
    }
};
```