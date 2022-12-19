两个矩形在X轴的投影有重合，并且在y轴的投影也有重合 => 两个矩形有重叠部分。这样是不是好理解很多。
```
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool x_overlap = (rec1[0] < rec2[2] && rec2[0] < rec1[2]);
        bool y_overlap = (rec1[1] < rec2[3] && rec2[1] < rec1[3]);
        return x_overlap && y_overlap;
    }
};
```
