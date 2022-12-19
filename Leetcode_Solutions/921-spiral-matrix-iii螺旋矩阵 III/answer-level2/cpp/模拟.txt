```
class Solution {
public://执行用时 :88 ms, 在所有 C++ 提交中击败了83.33%的用户
    int i,j,left,right,up,down,total,r,c;
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        res.push_back(vector<int>{r0,c0}); //首先写入开始结点
        r = R;c = C;total=r*c;//确定总数
        left = c0 - 1;right = c0 + 1;//确定上下左右边界
        up = r0 - 1;down = r0 + 1;
        i = r0;j = c0 + 1;//确定开始位置
        while(res.size()<total) {
            while(i<=down) {
                if(judge(i,j)) res.push_back(vector<int>{i,j});
                i++;
            }
            i--,j--;
            while(j>=left) {
                if(judge(i,j)) res.push_back(vector<int>{i,j});
                j--;
            }
            i--,j++;
            while(i>=up) {
                if(judge(i,j)) res.push_back(vector<int>{i,j});
                i--;
            }
            i++,j++;
            while(j<=right) {
                if(judge(i,j)) res.push_back(vector<int>{i,j});
                j++;
            }
            up--;down++;left--;right++;//边界更新
        }
        return res;
    }
    inline bool judge(int i,int j) {return i>=0&&i<r&&j>=0&&j<c;} //在矩阵内写入坐标
};
```
