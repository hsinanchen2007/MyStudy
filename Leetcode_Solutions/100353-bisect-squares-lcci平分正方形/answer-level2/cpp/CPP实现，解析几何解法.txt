**思路**：如果一条直线可以平分两个正方形，那么这条直线一定过两个正方形的中心。得到目标直线后，与两个正方形求交点即可。
**特殊情况**：如果中心重合，根据题目要求应选平行于Y轴的直线。
**编程技巧**：判断两个浮点数是否相等时需考虑精度问题，详见代码中的EPS。
**用到的C++技巧**：运算符重载，构造函数，vector容器的 begin 与 rbegin。
![qrcode_for_gh_6e5f8557b1f8_258.jpg](https://pic.leetcode-cn.com/610ed7bea4836735e55a90808f61d301d903a1363b255f461be0c0b268741323-qrcode_for_gh_6e5f8557b1f8_258.jpg)
**扫描二维码获取更多计算机相关知识~**
![image.png](https://pic.leetcode-cn.com/dbbe5b70c36bd0cd672630a055016dd32346f55eadb09a50f50d88e376b2176e-image.png)
```
const double EPS = 0.00001;
class Solution {
    struct Point {
        double x, y;
        Point() {}
        Point(double _x, double _y) : x(_x), y(_y) {}
        bool operator < (const Point &p) const {
            if(fabs(this->x - p.x) < EPS) {
                return this->y < p.y;
            }
            return this->x < p.x;
        }
    };
    Point getCenter(const vector<int> &sq) {
        Point p;
        p.x = (sq[0] + sq[0] + sq[2])/2.0;
        p.y = (sq[1] + sq[1] + sq[2])/2.0;
        return p;
    }

    void getInteraction(double a, double b, const vector<int> &sq, vector<Point> &vec) {
        double diff1, diff2;
        diff1 = a * sq[0] + b - sq[1];
        diff2 = a * sq[0] + b - (sq[1]+sq[2]);
        if(min(diff1, diff2) < EPS && max(diff1, diff2) > -EPS) {
            vec.push_back(Point(sq[0], a*sq[0] + b));
        } 
        diff1 = a * sq[0] + b - (sq[1]+sq[2]);
        diff2 = a * (sq[0] + sq[2]) + b - (sq[1] + sq[2]);
        if(min(diff1, diff2) < EPS && max(diff1, diff2) > -EPS) {
            vec.push_back(Point((sq[1]+sq[2] - b)/a, sq[1] + sq[2]));
        }
        diff1 = a * (sq[0]+sq[2]) + b - (sq[1]+sq[2]);
        diff2 = a * (sq[0]+sq[2]) + b - sq[1];
        if(min(diff1, diff2) < EPS && max(diff1, diff2) > -EPS) {
            vec.push_back(Point(sq[0]+sq[2], a*(sq[0]+sq[2]) + b));
        }
        diff1 = a * sq[0] + b - sq[1];
        diff2 = a * (sq[0] + sq[2]) + b - sq[1];
        if(min(diff1, diff2) < EPS && max(diff1, diff2) > -EPS) {
            vec.push_back(Point((sq[1] - b)/a, sq[1]));
        }
    }
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        auto p1 = getCenter(square1);
        auto p2 = getCenter(square2);
        
        vector<Point> vec;
        //处理p1, p2 重合的情况
        if(fabs(p1.x - p2.x) < EPS && fabs(p1.y < p2.y) < EPS) {
            vec.push_back(Point(p1.x, square1[1]));
            vec.push_back(Point(p1.x, square1[1] + square1[2]));
            vec.push_back(Point(p1.x, square2[1]));
            vec.push_back(Point(p1.x, square2[1] + square2[2]));
        }
        //处理与Y周平行的情况
        else if(fabs(p1.x - p2.x) < EPS) {
            vec.push_back(Point(p1.x, square1[1]));
            vec.push_back(Point(p1.x, square1[1] + square1[2]));
            vec.push_back(Point(p1.x, square2[1]));
            vec.push_back(Point(p1.x, square2[1] + square2[2]));
        } else {
            double a = (p1.y-p2.y)/(p1.x-p2.x);
            double b = p1.y - p1.x*a;
            getInteraction(a, b, square1, vec);
            getInteraction(a, b, square2, vec);
        }
        sort(vec.begin(), vec.end());
        return vector<double>{vec.begin()->x, vec.begin()->y, vec.rbegin()->x, vec.rbegin()->y};
    }
};
```
