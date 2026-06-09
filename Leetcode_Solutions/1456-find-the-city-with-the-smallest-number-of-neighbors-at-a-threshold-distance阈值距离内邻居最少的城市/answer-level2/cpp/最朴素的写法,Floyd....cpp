### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int d[150][150];
        for (int i =0;i<120;i++){
            for(int j = 0;j<120;j++){
                d[i][j]=99999999;
            }
        }
        for (auto v:edges){
            d[v[0]][v[1]]=v[2];
            d[v[1]][v[0]]=v[2];
        }
        for (int k = 0;k<n;k++){
            for (int i = 0;i<n;i++){
                for (int j = 0;j<n;j++){
                    if(d[i][j]>d[i][k]+d[k][j]){
                        d[i][j]=d[i][k]+d[k][j];
                    }
                }
            }
        }
        int ret = 0;
        int minn = INT_MAX;
        for (int i = 0;i<n;i++){
            int cnt = 0;
            for (int j = 0;j<n;j++){
                if(i==j) continue;
                if(d[i][j]<=distanceThreshold){
                    cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
                    cnt++;
                }
            }
            if (cnt<=minn){
                ret = i;
                minn = cnt;
            }
        }
        return ret;
    }
};
```