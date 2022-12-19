### 解题思路
要做这道题目之前，需要先做这一题：[836.矩形重叠](https://leetcode-cn.com/problems/rectangle-overlap/)
根据上面的题目，我们可以有效的判别矩形是否重叠。

我们设定，第一个矩形的面积为$Area_A$， 第二个矩形的面积为$Area_B$，重叠区域的面积为$Area_D$。

那么这道题目就可以分为两种情况：
- 两个矩形有重叠区域，面积为：$Area_A + Area_B - Area_D \quad \& \quad Area_D > 0$
- 两个矩形无重叠区域，面积为：$Area_A + Area_B$

从题目中可以知道：
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rectangle_area.png)
$Area_A = (C-A)*(D-B) \quad \& \quad Area_B = (G-E)*(H-F)$
那么问题就来到了如何求重得区域的面积了。

我们可以只看一个轴，$x$轴：
从$x$轴来看，重叠的时候一共可以分为四种情况：
- AC在左，AC不包含EG，按顺序排列为：[A,E,C,G];
- AC在左，AC包含EG，  按顺序排序为：[A,E,G,C];
- EG在左，EG不包含AC，按顺序排序为：[E,A,G,C];
- EG在左，EG包含AC，  按顺序排序为：[E,A,C,G].

所以，上面四种情况就可以确定了。我们需要的是中间的重叠部分，那么其实计算起来很简单：
两天线段总长 - 最长的线段即可。
所以，就可以求解这道题目了。

当然这道题目还有一个小问题，就是最后求解的时候，不要使用$Area_A + Area_B - Area_D$，最好使用$Area_B - Area_D + Area_A$，这样可以防止算出来的值超过**int**型，造成执行错误。

### 代码

```cpp
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        //先判定不重叠的情况,不重叠的话，就是两者面积相加
        if((C <= E || G <= A || D <= F || H <= B)){
            return (C - A) * (D - B) + (G - E) * (H - F);
        };
        //用向量的思想来算：
        //计算一共分四种情况：[A,E,C,G], [E,A,G,C], [A,E,G,C], [E,A,C,G]。
        //所以，可以得到的是：dx = 两边长 - 最大的长；
        //算两条边的边长
        int whole_x = (C - A) + (G - E);
        int whole_y = (D - B) + (H - F);

        //算最大的长
        int x[4] = {A,C,E,G};
        int y[4] = {B,D,F,H};
        //排序选最大和最小值
        sort(x,x+4);
        sort(y,y+4);
        //最长边
        int large_x = x[3] - x[0];
        int large_y = y[3] - y[0];
        //重叠区域面积
        int delta_area = (whole_x - large_x) * (whole_y - large_y);
        //两个矩形面积
        int area_a = (C - A) * (D - B);
        int area_b = (G - E) * (H - F);

        //这里容易越界
        return area_b - delta_area + area_a;

    }
};
```