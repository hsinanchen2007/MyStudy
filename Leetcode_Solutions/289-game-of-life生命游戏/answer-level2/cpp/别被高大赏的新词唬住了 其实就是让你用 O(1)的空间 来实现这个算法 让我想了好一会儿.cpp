### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int nHeight=board.size();
        if(nHeight<=0)
        {
            return ;
        }
        int nCount=0;
        int nWidth=board[0].size();
        for(int i=0;i<nHeight;++i)
        {
            for(int j=0;j<nWidth;++j)
            {
                nCount=0;
                for(int m=(i>0?-1:0);m<(i==nHeight-1?1:2);++m)
                {
                    for(int n=(j>0?-1:0);n<(j==nWidth-1?1:2);++n)
                    {
                        if(m==0&&n==0)
                        {
                            continue;
                        }
                        if((board[i+m][j+n]&1)>0)
                        {
                            nCount++;
                        }
                    }
                }
                //<2 不设置就代表死亡
                //2-3
                if(nCount>=2&&nCount<=3&&board[i][j]>0)
                {
                    board[i][j]+=2;
                }
                if(nCount==3&&board[i][j]==0)
                {
                    board[i][j]+=2;
                }
                //超过3也不处理
            }
        }
        for(int i=0;i<nHeight;++i)
        {
            for(int j=0;j<nWidth;++j)
            {
                board[i][j]=(board[i][j]>>1);
            }
        }
    }
};
```
我就是上来吐槽的 