
叠加法 Area = Area(rect1) + Area(rect2) - Area(rect1^rect2)

class Solution {
public:
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area_one = rectArea(A,B,C,D);
        int area_two = rectArea(E,F,G,H);

        int lft_x = max(A,E);
        int lft_y = max(B,F);
        int rht_x = min(C,G);
        int rht_y = min(D,H);

        int area_intersect = rectArea(lft_x,lft_y,rht_x,rht_y);
        return area_one - area_intersect + area_two;    // 调换顺序避免溢出
    }

    int rectArea(const int lft_x, const int lft_y, const int rht_x, const int rht_y) {
        if(lft_x>=rht_x || lft_y>=rht_y) return 0;  // 注意此时构不成有效矩形

        return (rht_x - lft_x)*(rht_y - lft_y);
    }
};