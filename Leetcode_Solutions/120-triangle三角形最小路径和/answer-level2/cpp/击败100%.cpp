### 解题思路
![U1S6NBWL6HCJFSFX_(V7F\[A.png](https://pic.leetcode-cn.com/a74228e1e5dcfd2f9960a0363ab83e9a090230d69dc7227202330d847e74a184-U1S6NBWL6HCJFSFX_\(V7F%5BA.png)

+ 从底层向上遍历，利用原有的空间，遍历第i层某个值时时，从i+1层的对应两个值中，选小的加上去即可。
### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)
            return 0;
        for(int i = triangle.size()-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
        }
        return triangle[0][0];
    }
};
```