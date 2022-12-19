# 一、思路
遍历整个m*n，找到当前的地域机器人能否过来
# 二、注意条件
## 1. 判断当前区域是否合法
## 2. 判断当前区域的上面和前面是否已经可以走到
完成上述两个条件后，即可判定当前区域可以走到
```c++
class Solution {
    int get(int x){
        int res = 0;
        for (; x; x /= 10){
            res += x % 10;
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k) {
        if(!k) return 1;
        vector<vector<int> > vis(m, vector<int>(n, 0));
        int ans = 1;
        vis[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0 || get(i) + get(j) > k) continue;
                if(i-1 >= 0) vis[i][j] |= vis[i-1][j];
                if(j-1 >= 0) vis[i][j] |= vis[i][j-1];
                ans += vis[i][j];
            }
        }
        return ans;
    }
};
```
