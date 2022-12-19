### 解题思路
执行用时 :76 ms, 在所有 C++ 提交中击败了33.33% 的用户
内存消耗 :13.9 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
    	map<int, int> nums_record;
    	for(size_t i=0;i<nums.size();++i){
    		nums_record[nums[i]]++;
    		if(nums_record[nums[i]] > 1){
    			nums_record.erase(nums[i]);
    		}
    	}
    	vector<pair<int,int>> v_nums_record(nums_record.begin(), nums_record.end());
    	vector<int> v_single_nums;
    	for(size_t i=0;i<v_nums_record.size();++i){
    		v_single_nums.push_back(v_nums_record[i].first);
    	}
    	return v_single_nums;
    }
};
```