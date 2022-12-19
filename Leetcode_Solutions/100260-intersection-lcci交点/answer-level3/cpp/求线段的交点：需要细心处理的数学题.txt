### 解题思路
本题是一道数学题，用到的知识是基础的解析几何知识，难点在于如何照顾到各种特殊情况。

![cover.png](https://pic.leetcode-cn.com/5abc87f8e2991d98ce4fdb4d8ac3a698710c76508b636b4bed366a3a432fd421-cover.png)

从思路上讲是非常直接的，即：
1. 求两直线的方程；
2. 联立方程求交点，如果无解（即：两直线平行），则直接返回空值；
3. 如果存在解，那么需要进一步验证这个两直线的交点是否为两个线段的交点。根据两直线的位置关系，存在两种情况：
3.1 两直线相交。这种情况下验证方法是平凡的。
3.2 如果两直线共线，那么此时需要进一步求出题目中满足要求的解（优先满足横坐标最小，再满足纵坐标最小）。同时，此时还有无解的可能性。


那么下面从实现上来讲一下如何做得尽可能漂亮一些。

### [1] 如何求直线方程
这里我们采用直线的一般式方程
![1.png](https://pic.leetcode-cn.com/f5609bdd2eceffb634e0c89efd5003f56f4ab7d2457f68fa618440391297788c-1.png)
这样做得原因是为了方便地处理斜率为0以及斜率不存在的情况。根据两点式直线方程
![2.png](https://pic.leetcode-cn.com/1245f22c3a0052c8648cbb2c9bfa3ef08d7a7fe7ea2fc37930ce916282051f43-2.png)
不难推导出
![3.png](https://pic.leetcode-cn.com/75c306f307520b30c8639cb11c2051184944be56ae7088beb481a4dc14a92b3f-3.png)

### [2] 求解两直线交点
其实说白了就是求解一个二元一次方程组。那么，使用Cramer's Rule是最便于代码实现的，原因有两个：
(i)  对于不平行的两条直线，回避了斜率为0或者斜率不存在的情况
(ii) 除了最后一步是除法，其他步骤都是加减乘三种运算。那么除了最后一步，可以一直使用整型变量进行计算，这样可以保证结果的精度。

对于线性方程组
![4.png](https://pic.leetcode-cn.com/3612be0ca0ecd6ef509026e6a7e3b4f601f2a54463594410aa68705ddb2a79ff-4.png)
对应的矩阵方程为
![5.png](https://pic.leetcode-cn.com/3b370a09cb69bda4462782c991e85e0ace28ca1ba5222b618d137d66aed6a262-5.png)
我们将所需的行列式分别按照如下进行表示
![6.png](https://pic.leetcode-cn.com/73b7506694e3cbaccec60965515de17e63cd20ccf71817c3b3d0400c12af018c-6.png)
那么
1) 如果d!=0，则
![7.png](https://pic.leetcode-cn.com/54edccc691e52b5759f2189a940f039c543b04290d258a5798cb73d84002537a-7.png)
2) 若d == 0，那么 
  (i)  dx != 0 或者 dy != 0，此时两直线平行，无解；
  (ii) dx = dy = 0，此时两直线重合，有无数个解，需要进一步考察两条线段P, Q的关系来找出一个满足题目要求的解。
       对于两个共线的线段，它们的关系一共有三种：P∩Q=∅、P∩Q≠∅和P⊆Q，如图所示：
![8.png](https://pic.leetcode-cn.com/b5150f78966fe9e48f73c8a893ecccba37f898f256c258792ada4e5d90a8d114-8.png)
       考察一下后可以发现，除了P∩Q=∅时无解以外，只要P∩Q≠∅，那么如果我们从小到大排列确定两条线段的四个点，那么第二个点就是满足题目要求的那个点（对于平行于y轴的直线，同样的思路可以处理）。
       此外，即使对于P∩Q=∅的无解情形，我们也可以暂时认为排位第二的那个点是一个解，因为这个解会在后面的验证过程中被舍去。

### [3] 进一步验证解的合理性
   只需要验证上面求出来的那个解的横纵坐标均在两条线段的端点之间即可。

PS: 本来想再写一个C版本的，因为C版本的跑起来更快，但是看到C版本长长的一串入参顿时没了写下去的欲望。




### 代码

```C++ []
class Solution {
    //用来表示一般型直线方程Ax+By=C
    struct Line {int A, B, C;};

    //start[0],start[1]什么的实在看上去太难受了，搞两个宏出来
#define X(point) (point)[0]
#define Y(point) (point)[1]

    inline bool isBetween(double x, double m, double n)
    {
        return m < n ? ((m <= x) && (x <= n)) : ((n <= x) && (x <= m));
    }

    //给出两点的坐标，求出对应的一般型直线方程
    inline void solveLine(vector<int>& p1, vector<int>& p2, Line& line)
    {
        line.A = Y(p2) - Y(p1);
        line.B = X(p1) - X(p2);
        line.C = X(p1) * Y(p2) - X(p2) * Y(p1);
    }

    //计算二阶行列式
    inline int det(int x1, int y1, int x2, int y2) {return x1 * y2 - x2 * y1;}

    //以下两个比较函数，用于处理两直线重合的特殊情况
    inline static bool cmpX(vector<int> *p1, vector<int>* p2) {return X(*p1) < X(*p2);}
    inline static bool cmpY(vector<int> *p1, vector<int> *p2) {return Y(*p1) < Y(*p2);}

public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        Line line1, line2;
        double x, y;

        solveLine(start1, end1, line1);
        solveLine(start2, end2, line2);

        int d  = det(line1.A, line1.B, 
                     line2.A, line2.B);
        int dx = det(line1.C, line1.B, 
                     line2.C, line2.B);
        int dy = det(line1.A, line1.C, 
                     line2.A, line2.C);

        if(d != 0) //两直线相交
        {
            x = (double) dx / d;
            y = (double) dy / d;
        }
        else
        {
            if(dx || dy) return vector<double>(); //平行
            
            //共线
            vector<vector<int>*> points({&start1, &end1, &start2, &end2});
            if(X(start1) != X(end1)) 
                sort(points.begin(), points.end(), cmpX);
            else 
                sort(points.begin(), points.end(), cmpY);

            x = X(*points[1]);
            y = Y(*points[1]);
        }

        if(!isBetween(x, X(start1), X(end1))
            || !isBetween(x, X(start2), X(end2))
            || !isBetween(y, Y(start1), Y(end1))
            || !isBetween(y, Y(start2), Y(end2)))
        {
            return vector<double>();
        }
        return vector<double>({x, y});
    }
};
```