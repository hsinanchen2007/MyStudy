### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // bool isIn(int x, int y, vector<int>& rec2){
    //     if(x > rec2[0] && x < rec2[2] && y > rec2[1] && y < rec2[3]) return true;
    //     else return false;
    // }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];
        // if(isIn(x1, y1, rec2)) return true;
        // if(isIn(x2, y2, rec2)) return true;
        // if(isIn(x1, y2, rec2)) return true;
        // if(isIn(x2, y1, rec2)) return true;
        if(y1 >= rec2[3]) return false;
        if(y2 <= rec2[1]) return false;
        if(x1 >= rec2[2]) return false;
        if(x2 <= rec2[0]) return false;
        return true;

    }
};
```