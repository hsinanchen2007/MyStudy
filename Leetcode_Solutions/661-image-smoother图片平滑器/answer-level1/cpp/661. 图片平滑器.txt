## 提前找好上下限
```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int r0 = M.size(), c0 = M[0].size();
        vector<vector<int>> ans(r0, vector<int>(c0));
        int cnt, sum;
        for(int i=0; i<r0; i++){
            for(int j=0; j<c0; j++){
                int x1 = i, x2 = i, y1 = j, y2 = j;
                if(i - 1 >= 0) x1 = i - 1; //上限
                if(i + 1 < r0) x2 = i + 1; //下限
                if(j - 1 >= 0) y1 = j - 1; //左限
                if(j + 1 < c0) y2 = j + 1; //右限
                int sum=0, cnt=0;
                for(int i = x1; i <= x2; i++)
                    for(int j = y1; j <= y2; j++)
                        sum += M[i][j];
                cnt = (x2 - x1 + 1)*(y2 - y1 + 1);
                ans[i][j] = sum/cnt;
            }
        }
        return ans;
    }
};
```
## 边判断上下限边操作
```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int a[9][2] = {{1,-1}, {1,0}, {1,1}, {0,-1}, {0,0}, {0,1}, {-1,-1}, {-1,0}, {-1,1}};
        int r0 = M.size(), c0 = M[0].size();
        vector<vector<int>> ans(r0, vector<int>(c0));
        int cnt, sum;
        for(int i=0; i<r0; i++){
            for(int j=0; j<c0; j++){
                cnt = 0, sum = 0;
                for(int k=0; k<9; k++){
                    int ii = i+a[k][0], jj = j+a[k][1];
                    if(ii>=0 && ii<r0 && jj>=0 && jj<c0){ //如果没有越界
                        cnt++;
                        sum += M[ii][jj];
                    }
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};
```