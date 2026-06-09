### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    	vector<int> vec_sorted;
    	for(auto& row:matrix){
    		for(auto& col:row){
    			vec_sorted.push_back(col);
    		}
    	}
    	std::sort(vec_sorted.begin(), vec_sorted.end());
//    	//for debug
//    	for(auto& iter:vec_sorted){
//    		cout << iter << " ";
//    	}
//    	cout << endl;
    	return vec_sorted[k-1];
    }
};
```