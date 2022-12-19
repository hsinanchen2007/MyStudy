### 解题思路
判断中心的距离。

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        float x1=(rec1[0]+rec1[2]),x2=(rec2[0]+rec2[2]);
        float y1=(rec1[1]+rec1[3]),y2=(rec2[1]+rec2[3]);
        float w1=abs(rec1[0]-rec1[2]),w2=abs(rec2[0]-rec2[2]);
        float h1=abs(rec1[1]-rec1[3]),h2=abs(rec2[1]-rec2[3]);
        if(abs(x1-x2)-w1<w2&&abs(y1-y2)-h1<h2) return true;
        return false;


}};
```