### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	if(!nums.size()) return -1;
    	size_t size = nums.size();
    	map<int, int> record;
    	for(size_t i=0;i<size;++i){
    		record[nums[i]]++;
    	}
    	vector<pair<int, size_t>> v_record(record.begin(), record.end());
    	std::sort(v_record.begin(), v_record.end(), [](const pair<int, size_t>& l, const pair<int, size_t>& r){
    		return l.second > r.second;
    	});
    	if(v_record[0].second > size/2){
    		return v_record[0].first;
    	}
    	else {
    		return -1;
    	}
    }
};
```