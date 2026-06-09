### 解题思路
此处撰写解题思路
用方向数组dx[]={0,1,0,-1} 和dy[]={1,0-1,0}来表示方向，基本思路是如果到达末端则需要改变方向，否则按顺序依次填数即可，代码简洁易懂。
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));  //存放结果的二维矩阵，初始值均为0
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};   //方向数组 
        int r=0,c=0,di=0;
        for(int i=1;i<=n*n;i++)
        {
            res[r][c]=i;
            int x=r+dx[di];
            int y=c+dy[di];
            if(0<=x&&x<n&&0<=y&&y<n&&res[x][y]==0)   //未到末端且下个位置没有填充数字
            {
                r=x;
                c=y;
            }
            else     //需要调转方向
            {
                di=(di+1)%4;
                r+=dx[di];
                c+=dy[di];
            }
        }
        return res;
    }
};
```