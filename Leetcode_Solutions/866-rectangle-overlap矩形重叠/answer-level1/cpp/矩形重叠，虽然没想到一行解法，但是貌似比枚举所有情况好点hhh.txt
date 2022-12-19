先求出两个矩形的最小和最大x、y坐标，两个矩形不重叠只需要最大最小坐标直接的距离小于长和宽之和即可。
看到题解里一行解决的方法只想说一句：妙啊！！！
```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        long long xmin = min(rec1[0], rec2[0]); 
        long long xmax = max(rec1[2], rec2[2]);
        long long ymin = min(rec1[1], rec2[1]);
        long long ymax = max(rec1[3], rec2[3]);

        long long l1 = rec1[2] - rec1[0], l2 = rec2[2] - rec2[0];
        long long w1 = rec1[3] - rec1[1], w2 = rec2[3] - rec2[1];

        if(xmax-xmin < l1+l2 && ymax-ymin < w1+w2)
            return true;
        else
            return false;

    }
};
```