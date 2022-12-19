### 解题思路
前一行的每个点到当前行都有两条不同路径，也就是说当前行的每个点，除了边界点以外，其他点都和上一行两个相邻点相连，即有两条不同的路径。
但这两条路径只需要保留最小的路径即可，因为从该点继续出发，它的最小路径和肯定是基于上一行到该点最小路径和。
也就是说我们基于前一行的每个点的最小路径和求得当前行的每个点的最小路径和，最后得到最后一行每个点的最小路径和。
然后遍历最后一行每个点，找到到该行的最小路径和

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
            return 0;
        if(triangle.size() == 1)
            return triangle[0][0];
        int sum_min = INT_MAX;
        int H = triangle.size() - 1;
        vector<int> tmp(H + 1, 0);
        tmp[0] = triangle[0][0];
        for(int i = 1; i <= H; ++i){
            int k = 0;
            int W = triangle[i].size() - 1;
            int first = tmp[k];
            for(int j = 0; j <= W; ++j){
                if(k > 0 && k < W){ //判断是否为边界点
                    int second = tmp[k];
                    tmp[k] = min(pre + triangle[i][j], second + triangle[i][j]);
                    first = second;
                }
                else{
                    tmp[k] = first + triangle[i][j];
                }
                // if(i == H && sum_min > tmp[k]){
                //     sum_min = tmp[k];
                // }
                ++k;
            }
        }
        for(int i = 0; i <= H; ++i){
            sum_min = (sum_min <= tmp[i]) ? sum_min : tmp[i];
        }
        return sum_min;
    }
};
```