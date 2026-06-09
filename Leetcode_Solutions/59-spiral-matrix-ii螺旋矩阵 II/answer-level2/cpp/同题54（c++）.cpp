思路同54题一致
```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int up = 0,left = 0;
        int down = n-1, right = n-1;
        int count = 1;
        while(true){
            for(int i=left;i<=right;++i)    res[up][i] = count++;
            if(++up>down)   break;
            for(int i=up;i<=down;++i)   res[i][right] = count++;
            if(--right<left)    break;
            for(int i=right;i>=left;--i)    res[down][i] = count++;
            if(--down<up)   break;
            for(int i=down;i>=up;--i)   res[i][left] = count++;
            if(++left>right)    break;
        }
        return res;
    }
};
```
