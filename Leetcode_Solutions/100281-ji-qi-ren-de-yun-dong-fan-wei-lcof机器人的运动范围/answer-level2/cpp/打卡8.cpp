### 解题思路
 广搜，一步一步走，能走的就加一并且标记一下就ok了。

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(k == 0)return 1;
        queue<pair<int,int>> q;
        vector<vector<int>> v(m , vector<int>(n , 0));
        q.push(make_pair(0,0));
        int d[4][2] = {0,1,0,-1,1,0,-1,0};
        int s = 1;
        v[0][0] = 1;
        while(!q.empty()){
            pair<int,int> t = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int x = t.first + d[i][0];
                int y = t.second + d[i][1];
                if(x < 0 || x >= m || y < 0 || y >= n || v[x][y])continue;
                if( x % 10 + x / 10 + x / 100 + y % 10 + y / 10 + y / 100 <= k){
                    q.push(make_pair(x,y));
                    v[x][y] = 1;
                    s++;
                }
            }
        }
        return s;
    }
};
```