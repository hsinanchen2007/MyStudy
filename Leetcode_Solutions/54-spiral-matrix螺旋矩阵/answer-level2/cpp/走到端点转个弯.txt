### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
    int up;
    int down;
    int left;
    int right;
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        if (matrix.empty() || matrix[0].empty())
            return ret;
        
        up = 0;
        down = matrix.size() - 1;
        left = 0;
        right = matrix[0].size() - 1;
        
        while (1) {
            for (int i = left; i <= right; i++)
                ret.push_back(matrix[up][i]);           
            /* turn to down */
            up += 1;
            if (up > down)
                break;
            
            for (int i = up; i <= down; i++)
                ret.push_back(matrix[i][right]);       
            /* turn to left */
            right -= 1;
            if (left > right)
                break;
            
            for (int i = right; i >= left; i--)
                ret.push_back(matrix[down][i]);      
            /* turn to up */
            down -= 1;
            if (up > down)
                break;
            
            for (int i = down; i >= up; i--)
                ret.push_back(matrix[i][left]); 
            /* turn to right */
            left += 1;
            if (left > right)
                break;
        }
        
        return ret;
    }
};
```