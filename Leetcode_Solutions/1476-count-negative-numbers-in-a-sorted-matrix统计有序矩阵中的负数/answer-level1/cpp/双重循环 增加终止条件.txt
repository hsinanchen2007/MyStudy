### 解题思路
利用题目特性，非递增。对列循环增加终止条件，当出现正数的时候就终止。

### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int h=grid.size();
        int l=grid[0].size();
        int ans=0;
        for (int i=0; i<h ; i++)
            for (int j=l-1;j>=0 ;j--){
                if (grid[i][j]<0)    ans++;
                else break;
            }            
        return ans;
    }
};
```