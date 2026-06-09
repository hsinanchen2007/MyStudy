确定每次循环的边界。


### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty())  return res;
        int left = 0,right = matrix[0].size()-1;
        int top = 0,down = matrix.size()-1;
        int i = top,j = left;
        while(top<=down && left<=right)
        {
            //向右走
		    for (j = left; j <= right && top<=down; ++j)
			    res.push_back(matrix[i][j]);
    		top++;
	    	j--;
		    //向下走
    		for (i = top; i <= down && left <= right; ++i)
	    		res.push_back(matrix[i][j]);
		    right--;
		    i--;
    		//向左走
	    	for (j = right; j >= left && top <= down; --j)
		    	res.push_back(matrix[i][j]);
    		down--;
	    	j++;
		    //向上走
    		for (i = down; i >= top && left <= right; --i)
	    		res.push_back(matrix[i][j]);
		    left++;
		    i++;
        }
        return res;
    }
};
```