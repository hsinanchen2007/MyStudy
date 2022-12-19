又是不怎么聪明的AC了。。
如果矩形重叠，那么两个矩形所在的最左边和最右边的距离△x 小于 俩矩形长的和，且俩矩形最上边和最下边的距离△y 小于 俩矩形宽的和

```
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // 若有重叠，则两个矩形投影总长度 < 矩形各自长度的和，宽同理
        // 求矩形各自长宽
        long lenx = (long)abs(rec1[2] - rec1[0]) + (long)abs(rec2[2] - rec2[0]);
        long leny = (long)abs(rec1[3] - rec1[1]) + (long)abs(rec2[3] - rec2[1]);
        
        // 求矩形实际总长宽
        int tx1 = abs(rec2[2] - rec1[0]);
        int tx2 = abs(rec1[2] - rec2[0]);
        int tx = max(tx1,tx2);
        int ty1 = abs(rec2[3] - rec1[1]);
        int ty2 = abs(rec1[3] - rec2[1]);
        int ty = max(ty1,ty2);
        // 比较
        long plusx = lenx - (long)tx;
        long plusy = leny - (long)ty;
        
        if( plusx > 0.0 && plusy > 0.0 ){return true;}
        return false;
    }
};
```
