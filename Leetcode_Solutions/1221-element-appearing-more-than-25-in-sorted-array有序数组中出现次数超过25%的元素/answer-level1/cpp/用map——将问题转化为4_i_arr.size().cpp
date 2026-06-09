### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
    	map<int, size_t> record;
    	for(size_t i=0;i<arr.size();++i){
    		record[arr[i]]++;
    	}
    	vector<pair<int, size_t>> v_record(record.begin(), record.end());
    	for(auto& iter:v_record){
    		if(4*iter.second > arr.size()) return iter.first;
    	}
    	return -1;
    }
};
```