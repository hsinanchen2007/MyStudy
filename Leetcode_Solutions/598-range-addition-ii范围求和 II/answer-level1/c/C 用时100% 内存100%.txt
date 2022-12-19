### 解题思路
简单来说，可理解为多个以(0, 0)为起点的矩形求交集的过程，结果就是所有矩形交集部分的面积，分别对维度m和维度n求最小值并相乘
![image.png](https://pic.leetcode-cn.com/adf54c1475c3d684b0a3cfded59ec551f40e05009fb7da47fc3d8cf7fa396e95-image.png)


### 代码

```c
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
    int resM = m;
    int resN = n;
    for (int i = 0; i < opsSize; ++i) {
        resM = resM > ops[i][0] ? ops[i][0] : resM;
        resN = resN > ops[i][1] ? ops[i][1] : resN;
    }
    return resM * resN;
}
```