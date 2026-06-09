![图片1.png](https://pic.leetcode-cn.com/eed33ae3521a8e937166ba706d3d098802385b54952417cc8d8c568b776f62ee-%E5%9B%BE%E7%89%871.png)
```
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];
        int x3 = rec2[0];
        int y3 = rec2[1];
        int x4 = rec2[2];
        int y4 = rec2[3];

        int llx,lly,rsx,rsy;
        //llx: Left Larger X
        //lly: Left Larger Y
        //rsx: Right Smaller X
        //rsy: Right Smaller Y

        llx = x1 >= x3 ? x1 : x3;
        lly = y1 >= y3 ? y1 : y3;        
        rsx = x2 < x4 ? x2 :x4;
        rsy = y2 < y4 ? y2 : y4;

        if(llx < rsx && lly < rsy) return true;
        else return false;   
    }
};
```
