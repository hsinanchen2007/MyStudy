### 解题思路
此处撰写解题思路

### 代码

```cpp
struct Rect{
    int x1;
    int y1;
    int x2;
    int y2;
};

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        Rect r1{rec1[0],rec1[1],rec1[2],rec1[3]};
        Rect r2{rec2[0],rec2[1],rec2[2],rec2[3]};

        if(r1.y1 >= r2.y2 || r1.y2 <= r2.y1){
            return false;    
        }
        if(r1.x1 >= r2.x2 || r1.x2 <= r2.x1){
            return false;    
        }
        return true;
    }
};
```