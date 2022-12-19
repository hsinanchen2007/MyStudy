1，	定义numInfos结构体，记录每个数字的起始位置start、结束位置end和个数count；
2，	依次统计每个数字start、end、count，并实时更新数组的度；
3，	遍历numInfos，找到count等于数组度的最短长度。长度通过start和end计算。

```
struct numInfo {
    unsigned short count;
    unsigned short start;
    unsigned short end;
};
```

**关于结构体数组的大小：**
因为输入的大小在0到49,999之间，所以开一个最大50000的结构体数组，内存开销也在接受范围内。
当然，为了节省内存，在实现时，需要先算出数组最大的值，减少内存的浪费；
同时统计元素使用short类型，可以cover住1到50,000的长度就可以了。

```
    for (i = 0; i < numsSize; i++) {
        maxNum = maxNum < nums[i] ? nums[i] : maxNum;
    }
    maxNum++;
    struct numInfo numInfos[maxNum];
```


