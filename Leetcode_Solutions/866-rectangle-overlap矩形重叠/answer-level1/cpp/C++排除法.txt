排除掉不重合以及只有一边重合的情况即可
```
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[0]>=rec2[2]||rec1[2]<=rec2[0])
        {
            return false;
        }
        else if(rec1[1]>=rec2[3]||rec1[3]<=rec2[1])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
```
