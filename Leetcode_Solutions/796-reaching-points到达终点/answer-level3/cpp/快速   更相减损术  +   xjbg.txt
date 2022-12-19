### 解题思路
此处撰写解题思路
更相减损术，减的过程用取余代替，然后一些特殊情况的判断，，，辗转相除不会。。。。

### 代码

```cpp
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx<sx||ty<sy)
                return false;
        while(1){
            if(tx==sx||ty==sy){
                if(tx==sx){
                    if(sy%tx==ty%tx)
                        return true;
                }
                if(ty==sy){
                    if(sx%ty==tx%ty)
                        return true;
                }
                return false;
            }
            if(tx<sx||ty<sy)
                return false;
            /*if(tx<sx||ty<sy){
                if(tx<sx){
                    if(tx+ty==sx&&ty==sy)
                        return true;
                }
                if(ty<sy){
                    if(tx+ty==sx&&ty==sy)
                        return true;
                }
            }             
                return false;*/
            if(sx==tx&&sy==ty)
                return true;
            int t=ty;
            int t1=tx;
            if(tx<ty)
                ty=ty%tx;
            else
                tx=tx%ty;
            //if((t%tx!=0&&ty==t)||(t1%ty!=0&&tx==t1))
            //    return false;
            //if(ty==0)
            //   ty+=tx;
            //if(tx==0)
            //    tx+=ty;
        }
        return false;
    }
};
```