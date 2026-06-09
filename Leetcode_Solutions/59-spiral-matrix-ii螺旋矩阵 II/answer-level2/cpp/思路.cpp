### 解题思路
和54题很类似，写法基本一样

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> res(n, vector<int>(n, 0));      
      if(n == 0)  return res;

      int up = 0;
      int down = n - 1;
      int left = 0;
      int right = n - 1;
      int cnt = 1;

      while(1){
        for(int i = left; i <= right; i++) 
          res[up][i] = cnt++;
        if(++up > down) break;

        for(int i = up; i <= down; i++)  
          res[i][right] = cnt++;
        if(--right < left) break; 

        for(int i = right; i >= left; i--)  
          res[down][i] = cnt++;
        if(--down < up) break; 

        for(int i = down; i >= up; i--) 
          res[i][left] = cnt++;
        if(++left > right) break; 
      }
      
      return res;    
    }
};
```