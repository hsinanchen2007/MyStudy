### 解题思路
多记些C语言自带的函数，对机考或笔试很有帮忙。
这次使用了stdlib.h的快排qsort,思路简单。
![image.png](https://pic.leetcode-cn.com/469cdd0630433884728fe30bb4a8cb2b6d9a7e0b52581ca8c2e4527a80c0eec4-image.png)
### 代码

```c
int comparefun(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr,arrSize,sizeof(int), comparefun);
    *returnSize = k;
    return arr;
}
```