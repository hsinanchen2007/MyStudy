### 解题思路
本来想到的是用那个精选第二种方法，不过INT_MAX测试用例有，换个奇怪的数字也是可以pass

第三种方法，显然复杂度比较低一些，不过确实很难想到吧，只能死记住好了

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      if(matrix.size() == 0 || matrix[0].size() == 0) return;

      bool firstColZore = false, firstRowZore = false;
      for(int i = 0; i < matrix.size(); i++){
        if(matrix[i][0] == 0) 
          firstColZore = true;
      }

      for(int i = 0; i < matrix[0].size(); i++){
        if(matrix[0][i] == 0) 
          firstRowZore = true;
      }


      for(int i = 1; i < matrix.size(); i++){
        for(int j = 1; j < matrix[0].size(); j++){
          if(matrix[i][j] == 0){
            matrix[0][j] = 0;
            matrix[i][0] = 0;
          }
        }
      }

      for(int i = 1; i < matrix.size(); i++){
        if(matrix[i][0] == 0) {
          for(int j = 1; j < matrix[0].size(); j++)
            matrix[i][j] = 0;
        }
      }

      for(int i = 0; i < matrix[0].size(); i++){
        if(matrix[0][i] == 0) {
          for(int j = 1; j < matrix.size(); j++)
            matrix[j][i] = 0;
        }
      }


      if(firstRowZore == true){
        for(int i = 0; i < matrix[0].size(); i++)
          matrix[0][i] = 0;
      }

      if(firstColZore == true){
        for(int i = 0; i < matrix.size(); i++)
          matrix[i][0] = 0;
      }

      return;
    }
};
```