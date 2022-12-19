### 解题思路
典型的二分法题目，即找到一个点，具有明确的方向性，进行下一次尝试。这里给出本题的C语言解法

本题使用了经典的二分查找模板，使用时需要注意：

1.退出条件为ll < rr

2.预先处理好左右边界条件

3.结果需要判断ll和ll-1的合理性

![image.png](https://pic.leetcode-cn.com/c38e89806fb41944f7c31a838798a5742e80fc4c6fcc5b34290abd7a29d10897-image.png)


### 代码

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

//【算法思路】二分法。
int hIndex(int* citations, int citationsSize){
    if(citationsSize == 0) {
        return 0;
    } else if(citations[0] >= citationsSize) {
        return citationsSize;
    } else if(citations[citationsSize - 1] == 1) {
        return 1;
    } else if(citationsSize == 1) {
        return citations[0] == 0? 0 : 1;
    }

    int ll = 0, rr = citationsSize - 1;

    while(ll < rr) {
        int mid = (ll + rr) / 2;

        int num = citationsSize - mid;

        if(citations[mid] > num) {
            rr = mid;
        } else {
            ll = mid + 1;
        }
    }

    //判断ll和ll - 1的合理性
    int ret = MMIN(citationsSize - ll, citations[ll]);
    ret = MMAX(ret, MMIN(citationsSize - (ll - 1), citations[ll - 1]));

    return ret;
}
```