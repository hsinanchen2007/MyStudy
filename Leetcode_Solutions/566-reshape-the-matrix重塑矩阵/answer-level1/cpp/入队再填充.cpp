### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    	size_t num_eles = nums.size() * nums[0].size();
    	if(static_cast<size_t>(r*c) > num_eles) return nums;

    	list<int> orig_eles;
    	for(auto& row:nums){
    		for(auto& col:row){
    			orig_eles.push_back(col);
    		}
    	}
//    	//for debug
//    	for(auto& iter:orig_eles){
//    		cout << iter << " ";
//    	}
//    	cout << endl;

    	vector<vector<int>> matrix_reshape;
    	for(int i=0;i<r;++i){
    		vector<int> curr_row;
    		for(int j=0;j<c;++j){
    			curr_row.push_back(orig_eles.front());
    			orig_eles.pop_front();
    		}
    		matrix_reshape.push_back(curr_row);
    	}

    	return matrix_reshape;
    }
};
```