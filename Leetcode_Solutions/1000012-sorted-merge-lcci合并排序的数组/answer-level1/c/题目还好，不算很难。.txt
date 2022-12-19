### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/3f658cb79c761217a0c3d2596f31b8249e34799158f909da8f223508e5f22b75-image.png)
1）可以将B中的元素挨个插入A，然后挪动A的元素
2）可以将B的元素先拷贝进入A，然后对A各种排序，快排，堆排，冒泡，选择排序等等，排序算法我都不会写了。。
### 代码

```c
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    memcpy(A + m, B, sizeof(int) * n);

    qsort(A, m + n, sizeof(int), cmp);
}
```