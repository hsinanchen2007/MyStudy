似乎只能用if语句列举条件
左下与右上关系固定，左上与右下关系相对固定。
```
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if((rec1[0]<rec2[2])&&(rec1[1]<rec2[3])&&(rec1[2]>rec2[0])&&(rec1[3]>rec2[1])) return true;
        return false;
    }
};
```
