```
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int total_area1 = (C - A) * (D - B);
        int total_area2 = (G - E) * (H - F);

        // 两个矩形完全互相覆盖
        if (B == F && E == A && D == H && G == C) {
            return total_area1;
        }
        
        int width = 0, height = 0;
        // 计算叠加矩形面积
        if (caculateSuPoArea(A, B, C, D, E, F, G, H, width, height) == 0) {
            caculateSuPoArea(E, F, G, H, A, B, C, D, width, height);
        }

        return total_area2 + total_area1 - width * height;
    }

    int caculateSuPoArea(const int A, const int B, const int C, const int D,
                         const int E, const int F, const int G, const int H,
                         int& width, int& height)
    {
        // 判断第一个矩形的哪个点在另一个矩形内部，以此来计算叠加矩形的长宽
        int left_top_point = (E >= A && E <= C) && (H <= D && H >= B) == true ? 1 : 0;
        int left_bottom_point = (E >= A && E <= C) && (F <= D && F >= B) == true ? 2 : 0;
        int right_top_point =  (H <= D && H >= B) && (G >= A && G <= C) == true ? 4 : 0;
        int right_bottom_point = (F <= D && F >= B) && (G >= A && G <= C) == true ? 8 : 0;
        int total = left_top_point | left_bottom_point | right_top_point | right_bottom_point;
        switch (total) {
            case 1:
            // 左上角点在另一个矩形里面
                width = C - E;
                height = H - B;
                break;
            case 2:
            // 左下角点在另一个矩形里面
                width = C - E;
                height = D - F;
                break;
            case 4:
            // 右上角点在另一个矩形里面
                width = G - A;
                height = H - B;
                break;
            case 8:
            // 右下角点在另一个矩形里面
                width = G - A;
                height = D - F;
                break;
            case 15:
            // 一个矩形被另一个完全包围
                width = G - E;
                height = H - F;
                break;
            case 5:
            // 一个矩形的上边两个点在另一个矩形里面
                width = G - E;
                height = H - B;
                break;
            case 10:
            // 一个矩形的下边两个点在另一个矩形里面
                width = G - E;
                height = D - F;
                break;
            case 3:
            // 一个矩形的左边两个点在另一个矩形里面
                width = C - E;
                height = H - F;
                break;
            case 12:
            // 一个矩形的右边两个点在另一个矩形里面
                width = G - A;
                height = H - F;
                break;
            default: break;
        }
        // 一个矩形的所有点都不在另一个里面，但是两个矩形有相交的地方
        if (E >= A && E <= C && H >= D && F <= B && G >= A && G <= C) {
            width = G - E;
            height = D - B;
        }
        return total;
    }
};
```
