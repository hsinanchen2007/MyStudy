### 解题思路
先把特例处理
（1）两个矩形是同一个矩形
（2）两个矩形不相交
两个矩形相交:先计算两个矩形的总面积，再计算两个相交矩形的面积，返回总面积减去相交面积
计算相交面积的方法：将四个x坐标，四个y坐标排序，然后相交面积=(y3-y2)*(x3-x2);(x3代表x坐标中第三个元素，其他一样)

### 代码

```cpp
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(A==E&&C==G&&B==F&&D==H)return (C-A)*(D-B);//两个矩形是同一个矩形
        int BigArea=(C-A)*(D-B)+(G-E)*(H-F);
        if(C<=E||G<=A||H<=B||D<=F)return BigArea;//两个矩形不相交
        vector<int> x={A,C,E,G};
        vector<int> y={B,D,F,H};
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        return BigArea-((x[2]-x[1])*(y[2]-y[1]));
    }
};
```