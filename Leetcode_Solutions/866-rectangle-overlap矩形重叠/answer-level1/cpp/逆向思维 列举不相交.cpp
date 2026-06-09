// ### 解题思路
// 矩形重叠的情况太多，难以处理，所以转而思考矩形不重叠的情况。
// 两个矩形不重叠，一个矩形必定在另一个矩形的四周。
// 上：rec1[1]>=rec2[3]
// 下：rec1[3]<=rec2[1]
// 左：rec1[2]<=rec2[0]
// 右：rec1[0]>=rec2[2])

// 如果感觉有启发，欢迎点赞或评论😄

// ### 代码

// ```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[1]>=rec2[3] || rec1[3]<=rec2[1] || rec1[2]<=rec2[0] || rec1[0]>=rec2[2])
            return false;
        return true;
    }
};
// ```