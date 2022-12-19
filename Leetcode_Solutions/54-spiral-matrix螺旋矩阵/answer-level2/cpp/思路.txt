### 解题思路
看了答案写的，非常巧妙
自己一开始一直就想递归写，坐标的规律还很能找到，哎

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      if(matrix.size() == 0)  return {};
      vector<int> res;
      int up = 0;
      int down = matrix.size() - 1;
      int left = 0;
      int right = matrix[0].size() - 1;

      while(1){
        for(int i = left; i <= right; i++) 
          res.push_back(matrix[up][i]);
        if(++up > down) break;

        for(int i = up; i <= down; i++)  
          res.push_back(matrix[i][right]);
        if(--right < left) break; 

        for(int i = right; i >= left; i--)  
          res.push_back(matrix[down][i]);
        if(--down < up) break; 

        for(int i = down; i >= up; i--) 
          res.push_back(matrix[i][left]);
        if(++left > right) break; 
      }
      
      return res;   
    }
};
```