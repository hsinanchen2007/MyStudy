希望这个没漏洞。
```
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if(x_center>=x1&&x_center<=x1&&y_center>=y1&&y_center<=y2)return 1;
        if(x_center+radius<x1||x_center-radius>x2||y_center+radius<y1||y_center-radius>y2)return 0;
        int d=radius*radius+1;
        for(int x:{x1,x1,x2,x2}){
            for(int y:{y2,y1,y1,y2}){
                d=min(d,(x_center-x)*(x_center-x)+(y_center-y)*(y_center-y));
            }
        }
        if(d<=radius*radius)return 1;
        if(x_center+radius>=x1&&y_center<y2&&y_center>y1)return 1;
        if(x_center-radius<=x2&&y_center<y2&&y_center>y1)return 1;
        if(y_center+radius>=y1&&x_center<x2&&x_center>x1)return 1;
        if(y_center-radius<=y2&&x_center<x2&&x_center>x1)return 1;
        return 0;
    }
};
```
