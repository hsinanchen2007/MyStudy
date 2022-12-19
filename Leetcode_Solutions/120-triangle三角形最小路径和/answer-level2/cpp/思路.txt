### 解题思路
比较简单的动态规划，比较好想到

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      //防止只有一行的情况，那就直接返回第一个数字
      int res = triangle[0][0];
      vector<int> minSum(triangle.size(), 0);

      minSum[0] = triangle[0][0];
      for(int i = 1; i < triangle.size(); i++){
        //其实只在乎最后一行的值，所以每次都reset值，没有必要再去遍历一遍minSum数组
        res = INT_MAX;
        for(int j = triangle[i].size() - 1; j >= 0; j--){
          //最右边
          if(j == triangle[i].size() - 1)
            minSum[j] = minSum[j - 1] + triangle[i][j];
          //最左边
          else if(j == 0)
            minSum[j] = minSum[j] + triangle[i][j];
          else
            minSum[j] = min(minSum[j], minSum[j - 1]) + triangle[i][j];

          res = min(res, minSum[j]);
        }
      }

      return res;
    }
};
```