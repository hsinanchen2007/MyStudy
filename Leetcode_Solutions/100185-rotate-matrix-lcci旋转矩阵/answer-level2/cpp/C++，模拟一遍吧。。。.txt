#### 老实说，我就是找了一下规律，然后就求解出来了，不知道是什么具体方法。。。。
```
class Solution {
public:
    void rotate(vector<vector<int>>& ma) {
        int m=ma.size();
        vector<vector<int>>temp=ma;

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                ma[i][j]=temp[m-j-1][i];
            }
        }
    }
};
```
