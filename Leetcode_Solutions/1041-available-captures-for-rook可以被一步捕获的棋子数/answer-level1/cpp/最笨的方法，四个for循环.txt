### 解题思路
方向数组啥的都见鬼去吧。但是为什么这样就能双百呢？
![image.png](https://pic.leetcode-cn.com/72d7053e7e38205aa6c37300996dc61301cb28de83c54a08f7cbcec97f57ac3c-image.png)

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int row=0,vol=0,r1=0,v1=0,sum=0;
        for(row=0;row<=7;row++)
        {                
            for(vol=0;vol<=7;vol++)
            {
                if(board[row][vol]=='R')
                 {
                    //right
                    for(v1=vol+1;v1<=7;v1++)
                    {
                        if(board[row][v1]!='.')
                        {
                            if(board[row][v1]=='p')
                            {
                                sum++;
                            }
                            break;
                        }
                    }
                    //left
                    for(v1=vol-1;v1>=0;v1--)
                    {
                        if(board[row][v1]!='.')
                        {
                            if(board[row][v1]=='p')
                            {
                                sum++;
                            }
                            break;
                        }
                    }
                    //up
                    for(r1=row-1;r1>=0;r1--)
                    {
                        if(board[r1][vol]!='.')
                        {
                            if(board[r1][vol]=='p')
                            {
                                sum++;
                            }
                            break;
                        }
                    }
                    //down
                    for(r1=row+1;r1<=7;r1++)
                    {
                        if(board[r1][vol]!='.')
                        {
                            if(board[r1][vol]=='p')
                            {
                                sum++;
                            }
                            break;
                        }
                    }
                }
            }
        }
        
        return sum;


    }
};
```