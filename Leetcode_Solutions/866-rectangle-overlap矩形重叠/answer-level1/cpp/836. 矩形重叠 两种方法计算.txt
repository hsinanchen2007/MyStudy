### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        // 这个方法是算不重合，然后取反就行了,  在左边，在下边，在右边，在上边（注意加等于号，因为边接触不算重叠）
        return !(rec1[2] <= rec2[0] || rec1[3] <= rec2[1] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3]);



        // 这个方法是算重合的

        // if(rec1[0] >= rec2[0])
        // {
        //     if(rec1[1] >= rec2[1])
        //         return rec2[3] > rec1[1] && rec2[2] > rec1[0];
        //     return rec1[3] > rec2[1] && rec2[2] > rec1[0];
        // }
        // if(rec1[1] >= rec2[1])
        //     return rec1[2] > rec2[0] && rec2[3] > rec1[1];
        // return rec1[2] > rec2[0] && rec1[3] > rec2[1];






        // 这些是错误的尝试
        // if(rec1[0] == rec2[0])
        // {
        //     if(rec1[1] <= rec2[1])
        //         return rec1[3] > rec2[1];
        //     return rec2[3] > rec1[1];
        // }
        // if(rec1[1] == rec2[1])
        // {
        //     if(rec1[0] <= rec2[0])
        //         return rec1[2] > rec2[0];
        //     return rec2[2] > rec1[0];
        // }

        // if(rec1[2] == rec2[2])
        // {
        //     if(rec1[3] <= rec2[3])
        //         return rec1[3] > rec2[1];
        //     return rec2[3] > rec1[1];
        // }
        // if(rec1[3] == rec2[3])
        // {
        //     if(rec1[2] <= rec2[2])
        //         return rec1[2] > rec2[0];
        //     return rec1[2] > rec2[0];
        // }
        

        // if(rec1[0] > rec2[0] && rec1[0] < rec2[2] && rec1[1] > rec2[1] && rec1[1] < rec2[3])
        //     return true;
        // if(rec1[2] > rec2[0] && rec1[2] < rec2[2] && rec1[3] > rec2[1] && rec1[3] < rec2[3])
        //     return true;

        // if(rec2[0] > rec1[0] && rec2[0] < rec1[2] && rec2[1] > rec1[1] && rec2[1] < rec1[3])
        //     return true;
        // if(rec2[2] > rec1[0] && rec2[2] < rec1[2] && rec2[3] > rec1[1] && rec2[3] < rec1[3])
        //     return true;

        // return false;
    }
};
```