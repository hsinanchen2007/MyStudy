#### 方法一：拒绝采样

为了在一个半径为 $R$ 的圆 $C$ 中均匀随机生成点，我们可以使用拒绝采样的方法。

我们使用一个边长为 $2R$ 的正方形覆盖住圆 $C$，并在正方形内随机生成点，若该点落在圆内，我们就返回这个点，否则我们拒绝这个点，重新生成知道新的随机点落在圆内。

![pic](https://pic.leetcode-cn.com/Figures/883/squareCircleOverlay.png){:width=400px}

由于正方形的面积为 $(2R)^2 = 4R^2$，圆的面积为 $\pi R^2$，因此在正方形中随机生成的点，落在圆内的概率为 $\text{Pr}(x) = \frac{\pi R^2}{4R^2} \approx 0.785$，因此期望的生成次数为 $\text{E} = \frac{1}{0.785} \approx 1.274$。

```C++ [sol1]
class Solution {
public:
    double rad, xc, yc;
    //c++11 random floating point number generation
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};

    Solution(double radius, double x_center, double y_center) {
        rad = radius, xc = x_center, yc = y_center;
    }

    vector<double> randPoint() {
        double x0 = xc - rad;
        double y0 = yc - rad;

        while(true) {
            double xg = x0 + uni(rng) * 2 * rad;
            double yg = y0 + uni(rng) * 2 * rad;
            if (sqrt(pow((xg - xc), 2) + pow((yg - yc), 2)) <= rad)
                return {xg, yg};
        }
    }
};
```

```Java [sol1]
class Solution {
    double rad, xc, yc;
    public Solution(double radius, double x_center, double y_center) {
        rad = radius;
        xc = x_center;
        yc = y_center;
    }

    public double[] randPoint() {
        double x0 = xc - rad;
        double y0 = yc - rad;

        while(true) {
            double xg = x0 + Math.random() * rad * 2;
            double yg = y0 + Math.random() * rad * 2;
            if (Math.sqrt(Math.pow((xg - xc) , 2) + Math.pow((yg - yc), 2)) <= rad)
                return new double[]{xg, yg};
        }
    }
}
```

**复杂度分析**

* 时间复杂度：期望时间复杂度为 $O(1)$，但最坏情况下会达到 $O(\infty)$（一直被拒绝）。

* 空间复杂度：$O(1)$。

#### 方法二：计算分布函数

不失一般性，我们只考虑在原点且半径为 `1` 的单位圆，对于非一般性的情况，我们只需要把生成的点的坐标根据半径等比例放大，再根据圆心坐标进行平移即可。

对于两条线段，我们在它们中均匀随机生成点。如果一条线段的长度是另一条的两倍，那么生成的点在第一条线段上的概率也应当是在第二条线段上的概率的两倍。因此我们考虑单位圆内部的每一个圆环，生成的点落在半径为 $R_1$ 的圆环上的概率应当与圆环的周长成正比，同时也与 $R_1$ 成正比，即 $f(R_1) = k * R_1$，其中 $f(x)$ 为概率密度函数（PDF）。由于 $f(x)$ 在定义域上的积分为 `1`，因此可以求出 $f(x)$ 的表达式 $f(x) = 2x$。

得到了概率密度函数后，我们计算累计分布函数（CDF），即 $F(x) = \int f(x) = \int 2x = x^2$。累计分布函数 $F(x)$ 告诉我们，在单位圆中随机生成一个点，它离圆心的距离小于等于 $x$ 的概率为 $F(x) = x^2$。对于一个给定的累计分布函数，如果我们想要根据其生成随机变量，我们可以通过 $[0, 1]$ 的均匀分布生成随机变量 $U$，找到满足 $F(X) = U$ 的 $X$，此时 $X$ 即为满足累计分布函数的随机变量。

对于 $F(X) = U$，由于 $F(X)$ 单调递增，因此有 $X = F^{-1}(U)$。由于 $F(x) = x^2$，因此有 $F^{-1}(x) = \sqrt{x}$，即用 $X = \sqrt{U}$ 来生成随机变量 $X$。

除了 $X$（代表到圆心的距离）之外，我们还需要随机生成其与水平轴正方向的夹角 $\theta$，随后我们就可以根据

$$
\text{x\_coord} = X \cdot \cos \theta\\
\text{y\_coord} = X \cdot \sin \theta
$$

得到点在单位圆内的坐标。再经过我们等比例放大坐标和平移两个步骤，就可以得到任意圆内的一个均匀随机生成的点了。

```C++ [sol2]
class Solution {
public:
    double rad, xc, yc;
    //c++11 random floating point number generation
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};

    Solution(double radius, double x_center, double y_center) {
        rad = radius, xc = x_center, yc = y_center;
    }

    vector<double> randPoint() {
        double d = rad * sqrt(uni(rng));
        double theta = uni(rng) * (2 * M_PI);
        return {d * cos(theta) + xc, d * sin(theta) + yc};
    }
};
```

```Java [sol2]
class Solution {
    double rad, xc, yc;
    public Solution(double radius, double x_center, double y_center) {
        rad = radius;
        xc = x_center;
        yc = y_center;
    }

    public double[] randPoint() {
        double d = rad * Math.sqrt(Math.random());
        double theta = Math.random() * 2 * Math.PI;
        return new double[]{d * Math.cos(theta) + xc, d * Math.sin(theta) + yc};
    }
}
```

**复杂度分析**

* 时间复杂度：$O(1)$。

* 空间复杂度：$O(1)$。