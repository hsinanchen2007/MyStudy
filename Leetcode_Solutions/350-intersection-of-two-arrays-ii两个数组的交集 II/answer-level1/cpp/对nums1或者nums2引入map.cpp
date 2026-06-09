### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	map<int, int> GetNumRecord(vector<int>& nums){
		map<int, int> num_record;
    	for(size_t i=0;i<nums.size();++i){
    		num_record[nums[i]]++;
    	}
    	return num_record;
	}
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> vec_intersect;
    	map<int, int> nums1_record = GetNumRecord(nums1);
    	for(auto& iter:nums2){
    		if(nums1_record[iter]){
    			vec_intersect.push_back(iter);
    			nums1_record[iter]--;
    		}
    	}
    	return vec_intersect;
    }
};
```