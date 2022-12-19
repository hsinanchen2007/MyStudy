外循环决定填充的方向，内循环决定填充的长度。
```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int p = 1;
        int down = 0, right=-1;
        int opright[]{1,0,-1,0};
        int opdown[]{0,1,0,-1};
        int op;
        for(int i=0; i<2*n-1; i++){
            //cout<<"i="<<i;
            op = i%4;
            for(int j=0; j<n-((i+1)/2); j++){
                down += opdown[op];
                right += opright[op];
                res[down][right] = p++;
                //cout<<"\t("<<down<<","<<right<<")="<<p-1<<endl;
            }
        }
        return res;
    }
};
```
