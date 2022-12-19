### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/7d284c65d841513b3deab015044e73c17482f79a0ba54a01308189faad4f3d5c-%E6%8D%95%E8%8E%B7.PNG)
红色框离矩形的边的距离都是r
只要圆心在红色框的范围内就ok

### 代码

```cpp
class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        bool flag1=0,flag2=0;
        int dis,disx,disy;
        if(xc>=x1&&xc<=x2)
            flag1=1;
        if(yc>=y1&&yc<=y2)
            flag2=1;
        if(flag1&&flag2)
            return 1;
        if(flag1&&!flag2){
            dis=min(abs(yc-y1),abs(yc-y2));
            if(dis>r)
                return 0;
            else
                return 1;
        }
        if(flag2&&!flag1){
            dis=min(abs(xc-x1),abs(xc-x2));
            if(dis>r)
                return 0;
            else
                return 1;
        }
        if(!flag1&&!flag2){
            disx=min(abs(xc-x1),abs(xc-x2));
            disy=min(abs(yc-y1),abs(yc-y2));
            if(r*r>=disx*disx+disy*disy)
                return 1;
            else
                return 0;
        }
        return 0;
    }
};
```