### 解题思路
因为从某个点到下一个点要不是(x+y,y)要不就是(x,x+y),x+y肯定是大于x和y的，所以由终点可以确定它上一个位置必为
        if(tx>ty)
                上一位置 (tx-ty,ty);
        else     上一位置(tx,ty-tx);
当ty和tx有一个是另一个的好几倍时，可以进一步优化：
        if(tx>ty)
                 上一位置(tx-((tx-sx)/ty>=1?(tx-sx)/ty:1)*ty,ty);
        else     上一位置(tx,ty-((ty-sy)/tx>=1?(ty-sy)/tx:1)*tx);

### 代码

```cpp
class Solution {
public:
    bool dp(int sx,int sy,int tx,int ty){
        if(tx<sx||ty<sy)
        return false;
        if(sx==tx&&sy==ty)
           return true;
        if(tx>ty)
            return dp(sx,sy,tx-((tx-sx)/ty>=1?(tx-sx)/ty:1)*ty,ty);
        else return dp(sx,sy,tx,ty-((ty-sy)/tx>=1?(ty-sy)/tx:1)*tx);
    }
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        return dp(sx,sy,tx,ty);
    }
};
```