分类讨论：
1. 矩形4个顶点在圆内
get_sum_of_square(x_center, y_center, x1, y1) <= r_square
|| get_sum_of_square(x_center, y_center, x1, y2) <= r_square
|| get_sum_of_square(x_center, y_center, x2, y1) <= r_square
|| get_sum_of_square(x_center, y_center, x2, y2) <= r_square

2. 矩形的某条边切割圆
|| is_cut(r, x_center, y_center, x1, y1, y2)
|| is_cut(r, x_center, y_center, x2, y1, y2)
|| is_cut(r, y_center, x_center, y1, x1, x2)
|| is_cut(r, y_center, x_center, y2, x1, x2)

3. 圆心在矩形内
|| (x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2)
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int r = radius;
        long long r_square = radius;
        r_square = r_square * r_square;

        return get_sum_of_square(x_center, y_center, x1, y1) <= r_square
        || get_sum_of_square(x_center, y_center, x1, y2) <= r_square
        || get_sum_of_square(x_center, y_center, x2, y1) <= r_square
        || get_sum_of_square(x_center, y_center, x2, y2) <= r_square
        || is_cut(r, x_center, y_center, x1, y1, y2)
        || is_cut(r, x_center, y_center, x2, y1, y2)
        || is_cut(r, y_center, x_center, y1, x1, x2)
        || is_cut(r, y_center, x_center, y2, x1, x2)
        || (x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2);

    }

    bool is_cut(int r, int x_center, int y_center, int x1, int y1, int y2){
        return (abs(x_center - x1) <= r) 
            && (
                (y_center <= y1 && y_center >= y2)
                 || 
                (y_center >= y1 && y_center <= y2)
            );
    }

    int abs(int x){
        return x > 0 ? x : - x;

    }

    long long get_sum_of_square(long long  x1, long long  y1, long long  x2, long long  y2){
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    }
};