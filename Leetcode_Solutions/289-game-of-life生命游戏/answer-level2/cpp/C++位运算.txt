### 解题思路
看完题解改进的，末位表示旧的状态，第二位表示新的状态。故有00，01，10，11四种状态
![image.png](https://pic.leetcode-cn.com/3d49afaedfb67cc4bd3e85985329d155c293a5d227fc8856f9bb998264c2dac2-image.png)

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,1,-1,-1,0,1};
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                int num=0;
                for(int k=0;k<8;k++){
                    int kx=i+dx[k],ky=j+dy[k];
                    if(kx>=0&&ky>=0&&kx<m&&ky<n)num+=board[kx][ky]&1;
                }
                if(num==2)board[i][j]*=3;
                if(num==3)board[i][j]+=2;
            }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)board[i][j]>>=1;
    }
};
```