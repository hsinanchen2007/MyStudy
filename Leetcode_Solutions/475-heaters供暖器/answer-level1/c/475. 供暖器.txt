### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/dbf5eb41e55d14d9ae26f274069f6a0c31f51b475459d7733bce551385a3c28d-image.png)
该题的例子有误导性，容易让人以为给的位置都是按照顺序排列的。
但是如果房子和暖气的位置排列是升序的，问题就简单了，所以我们就对房子和加热器进行排序。
在升序的前提下，我们逐个遍历房间位置，然后找到与其距离最近的暖气，计算出需要的半径。
对每个房间的需求半径取最大值，就可以得到需要的加热半径。
测试需要考虑的情况见注释
### 代码

```c
int CompareInt(void *x, void *y) {
    if (*(int *)x < *(int *)y) {
        return -1;
    } else if (*(int *)x == *(int *)y) {
        return 0;
    } else {
        return 1;
    }
}
int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    if (houses == NULL || housesSize < 1 || heaters == NULL || heatersSize < 1) {
        return 0;
    }
    qsort(houses, housesSize, sizeof(int), CompareInt);
    qsort(heaters, heatersSize, sizeof(int), CompareInt);

    int left = 0;
    int right = 0;
    int r_max = 0;
    int lLength = 0;
    int rLength = 0;
    int minLength = 0;

    for (int i=0; i<housesSize; i++) {
        while (right + 1 < heatersSize && heaters[right] <= houses[i]) {
            right++;
            left = right - 1;
        }

        lLength = abs(houses[i] - heaters[left]);
        rLength = abs(houses[i] - heaters[right]);
        minLength = lLength < rLength ? lLength : rLength;

        r_max = minLength > r_max ? minLength : r_max;
    }

    return r_max;
}

/* test case 
普通
[1,2,3]
[2]

普通
[1,2,3,4]
[1,4]

房间外
[1,2,3,4,5]
[0,6]

房间内外
[1,2,3,4,5]
[2,15]

单点
[1]
[1]

[1]
[10]

空集
[]
[]

[1,2,3]
[]

[]
[1,2,3]

跳点
[1,2,6,19]
[2,10,50]

暖气很远的单点
[1,2,3]
[100]

跳点 + 很远 + 外点
[10,15,20]
[0,1000]

乱序
[3,2,1]
[5,1,10]
*/
```