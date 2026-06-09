### 解题思路

核心算法为双指针：

1.将两数组排序
2.增加aid，找到a[aid]大于b[bid]的情况
3.此时计算差值（aid和aid-1都要计算)
4.调整bid
5.重复2

问题的主要难点却在于超出int范围的比较问题。

此类问题根本方法为，中间处理扩展到long long，然后在结果转换到int。

注意，compare函数不能直接减法；abs不能直接调用（这个很坑）。

![image.png](https://pic.leetcode-cn.com/b914b211e16894cd9c5097b586636a8eec23e1a90aaf4ef1607412582b7cc9dd-image.png)


### 代码

```c
#define MMIN(a, b)        ((a) < (b)? (a) : (b))
#define AABS(a)           ((a) >= 0? (a) : -(a))

int compare(const void *a, const void *b)
{
    int ret=    *(int*)a > *(int*)b? 1 :
                (*(int*)a == *(int*)b? 0 : -1);
    return ret;
}

//【算法思路】双指针。
// 1.将两数组排序
// 2.找到a[aid]大于b[bid]的情况
// 3.此时计算差值，调整bid
// 4.重复2
//注意超int范围的处理
int smallestDifference(int* a, int aSize, int* b, int bSize){
    long long min = 0x7FFFFFFFFFFFFFFF;
    qsort(a, aSize, sizeof(int), compare);
    qsort(b, bSize, sizeof(int), compare);

    int aid = 0;
    int bid = 0;
    long long aa, bb, cc;

    while(aid < aSize) {

        if(a[aid] < b[bid]) {
            aid++;
            continue;
        }

        //此时a[aid] > b[bid],计算aid和aid-1数据与bid位置的差值
        bb = b[bid];

        if(aid > 0) {
            aa =a[aid - 1];
            min = MMIN(min, AABS(aa - bb));
        }

        aa = a[aid];
        min = MMIN(min, AABS(aa - bb));

        bid++;

        if(bid == bSize)
        {
            break;
        }
    }

    //最后一次a没有找到大于b的值
    if(aid == aSize && bid < bSize) {
        aa = a[aid - 1];
        bb = b[bid];
        min = MMIN(min, AABS(aa - bb));
    }

    return (int)min;
}
```