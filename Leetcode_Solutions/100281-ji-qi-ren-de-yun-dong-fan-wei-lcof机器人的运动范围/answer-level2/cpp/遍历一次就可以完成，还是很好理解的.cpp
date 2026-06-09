### 解题思路
这道题只要求其范围，从0，0出发把其周为都点亮然后把没点亮的看作退出条件就可以，就可以只要遍历一遍题目就可以完成了

### 代码

```cpp
class Solution {
    int get(int x) {
        int res=0;
        for (; x; x /= 10){
            res += x % 10;
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        vector<vector<int> > vis(m, vector<int>(n, 0));
        int ans = 0;
        vis[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ( get(i) + get(j) >k||vis[i][j]==0) 
				continue;//退出条件 
                //将ij的周为都点亮 
                if(i+1<m)
                vis[i+1][j]=1;
                if(j+1<n)
                vis[i][j+1]=1;
                ans++;
            }
        }
        return ans;
    }
};
```