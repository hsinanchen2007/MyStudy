### 解题思路
从角落开始写即可（左下|右上），然后依次判断即可，注意当输入为空的时候的NULL错误

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)return false;
        int w=matrix[0].size();
        int h=matrix.size();

        for(int i=h-1,j=0;i>=0&&j<w;){
            
                if(matrix[i][j]<target){
                    j++;
                }
                else if(matrix[i][j]>target){
                    i--;
                }
                else return true;//found
            
        }
        return false;
    }
};
```