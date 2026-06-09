![无标题.png](https://pic.leetcode-cn.com/78d20170b139913484c6643fb2de65d5c9597cd5eb116165f7458cbdb823b735-%E6%97%A0%E6%A0%87%E9%A2%98.png)


### 解题思路
拒绝采样，通俗的说就是用更大的范围取值，然后不符合要求的不要
我们在一个边长为2*radius的矩形（即半径为radius的圆的外接四边形）中随机取值，然后计算它距离矩形中心（即圆心）的距离，如果它在其内接圆内则输出，否则重新取点

### 代码

```cpp
class Solution {
public:
    double xcenter;
    double ycenter;
    double rad;
    random_device rd;
    default_random_engine e;
    uniform_real_distribution<double> tmp{-1,1};
    Solution(double radius, double x_center, double y_center) {
        e = default_random_engine(rd());
        xcenter = x_center;
        ycenter = y_center;
        rad = radius;
    }

    vector<double> randPoint() {
        while (true) {
            double a = tmp(e)*rad;
            double b = tmp(e)*rad;
            if (a*a+b*b>rad*rad) continue;
            return { xcenter + a,ycenter + b };
        }
    }
};
```