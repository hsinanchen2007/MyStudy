执行用时 :4 ms, 在所有 c 提交中击败了85.19%的用户
内存消耗 :7 MB, 在所有 c 提交中击败了100.00%的用户

首先没想到排序，比较了相邻数组元素的大小，如果出现heights[i] > height[i+1]，就对其进行计数，但是执行结果为2, 因为1，3并没有被比较。如果只按这样比较情况会很复杂或者有不能解决的可能。
再看一遍题目，关键字*顺序排列*，所以想到排完序后比较不同位置。但我不会写排序，就调用qsort来写。其中cmp一开始是直接`return *a<*b`,发现不行，要使用减法。这个为什么呢？**求解，大大的问号？**
本来以为按照如下代码，内存会占用的比较多。但是。。。迷

```
int cmp(const int *a, const int *b) {
    return *a-*b;
}
int heightChecker(int* heights, int heightsSize){
    int bef[heightsSize];
    int count = 0, i;
    for (i=0; i<heightsSize; i++) {
        bef[i] = heights[i];
    }
    qsort(heights, heightsSize, sizeof(int), cmp);
    for (i=0; i<heightsSize; i++) {
        if(heights[i] != bef[i]){
            count++;
        }
    }
    return count;
}
```
