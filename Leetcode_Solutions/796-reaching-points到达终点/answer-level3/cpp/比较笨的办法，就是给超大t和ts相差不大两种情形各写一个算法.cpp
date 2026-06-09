### 解题思路
比较笨的办法，就是给超大t和ts相差不大两种情形各写一个算法……
尝试把两种糅合在一起，还是不太行啊，如果递归过程中选择用减或者加的话（s加到够大就换成t减，t减到够大就换成s加），大t情形下依旧栈溢出……可能是我写得不对吧，回头再想想看。

### 代码

```cpp
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(abs(ty-tx)<tx-sx||abs(ty-tx)<ty-sy) return reachingPoints2(sx,sy,tx,ty);
        else return reachingPoints1(sx,sy,tx,ty);
    }
    bool reachingPoints1(int sx, int sy, int tx, int ty) {
        if(sx==tx&&sy==ty) return true;
        if(tx==sx) {
            if((ty-sy)>0&&(ty-sy)%sx==0) return true;
            else return false;
        }
        if(ty==sy) {
            if((tx-sx)>0&&(tx-sx)%sy==0) return true;
            else return false;
        }
        if(sx<=tx&&sy<=ty&&sx+sy<INT_MAX){
            if(reachingPoints1(sx,sx+sy, tx, ty)) return true;
            if(reachingPoints1(sx+sy,sy, tx, ty)) return true;
        }
        return false;
    }
    bool reachingPoints2(int sx, int sy, int tx, int ty) {
        if(sx==tx&&sy==ty) return true;
        if(tx==ty) return false;
        if(tx==sx) {
            if((ty-sy)>0&&(ty-sy)%sx==0) return true;
            else return false;
        }
        if(ty==sy) {
            if((tx-sx)>0&&(tx-sx)%sy==0) return true;
            else return false;
        }
        if(tx>ty&&sy<ty&&tx-ty>=sx){
            if(reachingPoints2(sx,sy, tx-ty, ty)) return true;
        }
        if(tx<ty&&sx<tx&&ty-tx>=sy){
            if(reachingPoints2(sx,sy, tx, ty-tx)) return true;
        }
        return false;
    } //数值大时的方法 abs(ty-tx)<tx-sx||abs(ty-tx)<ty-sy
};
```