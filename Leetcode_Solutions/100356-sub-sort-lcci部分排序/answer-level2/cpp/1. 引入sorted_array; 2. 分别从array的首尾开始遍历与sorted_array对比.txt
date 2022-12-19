### 解题思路
执行用时 :176 ms, 在所有 C++ 提交中击败了15.38% 的用户
内存消耗 :22.1 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    vector<int> subSort(vector<int>& array) {
    	vector<int> v_no_match = {-1, -1};
    	if(!array.size()){
    		return v_no_match;
    	}

    	vector<int> v_bound;
    	bool has_met = false;
    	vector<int> sorted_array = array;
    	std::sort(sorted_array.begin(), sorted_array.end());
    	for(size_t i=0;i<array.size();++i){
    		if(array[i] != sorted_array[i]){
    			has_met = true;
    			v_bound.push_back(i);
    			break;
    		}
    	}
    	for(size_t i= (array.size()-1); i>0; --i){
    		if(array[i] != sorted_array[i]){
    			has_met = true;
    			v_bound.push_back(i);
    			break;
    		}
    	}
    	return has_met ? v_bound : v_no_match;
    }
};
```