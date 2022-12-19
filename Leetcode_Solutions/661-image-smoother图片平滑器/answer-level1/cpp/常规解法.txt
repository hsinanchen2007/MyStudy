```
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res = M;
        for(int i=0;i<M.size();i++)
        {
            for(int j=0;j<M[0].size();j++)
            {
                int sum = 0, cnt = 0;
                // 自己
                sum += M[i][j];
                cnt++;
                // 左上
                if(i-1 >=0 && j-1 >= 0)
                {
                    sum += M[i-1][j-1];
                    cnt++;
                }
                // 上
                if(i-1 >= 0)
                {
                    sum += M[i-1][j];
                    cnt++;
                }
                // 右上
                if(i-1 >= 0 && j+1 < M[0].size())
                {
                    sum += M[i-1][j+1];
                    cnt++;
                }
                // 右
                if(j+1<M[0].size())
                {
                    sum += M[i][j+1];
                    cnt++;
                }
                // 右下
                if(i+1<M.size() && j+1 < M[0].size())
                {
                    sum += M[i+1][j+1];
                    cnt++;
                }
                // 下
                if(i+1<M.size())
                {
                    sum += M[i+1][j];
                    cnt++;
                }
                // 左下
                if(i+1<M.size() && j-1>=0)
                {
                    sum += M[i+1][j-1];
                    cnt++;
                }
                // 左
                if(j-1>=0)
                {
                    sum += M[i][j-1];
                    cnt++;
                }
                res[i][j] = int(sum / cnt);
            }
        }
        
        return res;
    }
};
```