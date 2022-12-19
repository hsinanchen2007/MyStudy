结果：
![Snipaste_2020-03-21_15-08-50.png](https://pic.leetcode-cn.com/8c6a130fe9f3c32996df3c5fba3e1b768aabe253b3064ad744ac8f1caee0a153-Snipaste_2020-03-21_15-08-50.png)

### 解题思路
- 公式：Ax + By + C = 0
A是x1-x2
B是y2-y1
C是x2*y1-x1*y2

- 判断平行或共线的公式：A1*B2 == A2*B1 (有可能都是0！暗含陷阱)

- 求交点坐标的公式
    1. x = (C2*A1-C1*A2) / (A2*B1-A1*B2)
    2. y = (C1*B2-C2*B1) / (A2*B1-A1*B2)

- 因为有两条线段，所以要求两次ABC作为基础

- 后面的细节判断太痛苦了，不提交几次都不知道还有这些鬼特殊情况

- 算法很可能不够精简，应该还能修短一些，但本人实在看吐了，就这样吧，反正再怎么改也是最快的了，毕竟0ms

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* intersection(int* start1, int start1Size, int* end1, int end1Size, int* start2, int start2Size, int* end2, int end2Size, int* returnSize){

    /* // xsub * y + ysub * x + inter = 0 // */
    //求两组A、B、C
    int xsub1 = start1[0] - end1[0];
    int ysub1 = end1[1] - start1[1];
    int xsub2 = start2[0] - end2[0];
    int ysub2 = end2[1] - start2[1];
    double inter1 = end1[0] * start1[1] - start1[0] * end1[1];
    double inter2 = end2[0] * start2[1] - start2[0] * end2[1];

    double* ans = (double*)malloc(sizeof(double) * 2);
    *returnSize = 2;

    if (xsub1 * ysub2 == xsub2 * ysub1) {  //可能平行和共线
        if (inter1 != inter2) {  //平行
            *returnSize = 0;
            return 0;
        }
        //以下都是共线，但还有很多特殊情况，共线的线段不一定有交点，而且还有一些mmp的垂直x、y轴的情况，老头疼了
        if ((end1[0] >= start2[0] && start1[0] < start2[0]) || (end1[0] > start2[0] && start1[0] <= start2[0])) {
            ans[0] = (double)start2[0];
            ans[1] = (double)start2[1];
            return ans;
        }
        if ((end1[0] <= start2[0] && start1[0] > start2[0]) || (end1[0] < start2[0] && start1[0] >= start2[0])) {
            ans[0] = end1[0];
            ans[1] = end1[1];
            return ans;
        }
        if ((start1[0] == start2[0] && start1[1] == start2[1]) || (start1[0] == end2[0] && start1[1] == end2[1])){
            ans[0] = (double)start1[0];
            ans[1] = (double)start1[1];
            return ans;
        }
        if ((start2[0] == end1[0] && start2[1] == end1[1]) || (end1[0] == end2[0] && end1[1] == end2[1])){
            ans[0] = (double)end1[0];
            ans[1] = (double)end1[1];
            return ans;
        }
        *returnSize = 0;
        return 0;
    }

    double x = (double)((inter2 * xsub1 - inter1 * xsub2) / (xsub2 * ysub1 - xsub1 * ysub2));
    double y = (double)((inter1 * ysub2 - inter2 * ysub1) / (xsub2 * ysub1 - xsub1 * ysub2));
    ans[0] = x; ans[1] = y;
    
    if (((x <= start1[0] && x >= end1[0]) || (x >= start1[0] && x <= end1[0])) && ((x <= start2[0] && x >= end2[0]) || (x >= start2[0] && x <= end2[0]))) return ans;

    *returnSize = 0;
    return 0;
}
```