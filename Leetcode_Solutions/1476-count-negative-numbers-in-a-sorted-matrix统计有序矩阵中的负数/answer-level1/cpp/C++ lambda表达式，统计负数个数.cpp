C++ lambda表达式，统计负数个数。
```
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            res += count_if(grid[i].begin(),grid[i].end(),[](int x){return x < 0;});
        }

        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/370731c5d9f6b92f900b281222f1cbdf8969b210604f7e1c11896310165ff933-image.png)
