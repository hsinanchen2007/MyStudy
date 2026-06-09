```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int up = 0;             //设定初始的上下左右边界
        int down = n-1;
        int left = 0;
        int rig = n-1;
        int count = 1;
        while(1) {             //按上下左右的顺序减小边界，每次减小值为1；当边界冲突时跳出循环
            for(int i = left;i <= rig;i++)  res[up][i] = count++;
            if(++up > down)  break;
            for(int i = up;i <= down;i++)   res[i][rig] = count++;
            if(--rig < left) break;
            for(int i = rig;i >= left;i--)  res[down][i] = count++;
            if(--down < up) break;
            for(int i = down;i >=up;i--)    res[i][left] = count++;
            if(++left > rig) break;
        }
        return res;
    }
};
```
