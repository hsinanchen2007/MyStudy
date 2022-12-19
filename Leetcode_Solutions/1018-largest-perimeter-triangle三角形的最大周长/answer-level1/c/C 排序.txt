### 解题思路
知识点：组成三角形，任意两边之后大于第三边。
先排序，存在组合A>B>C。
后边小的两条边（B，C）之和大于第三边，那么就可以组成三角形。
因为A>B，A>C，已经必然存在，A+B>C，A+C>B。
所以接下来就是要找到B+C>A的，周长最大的情况。

### 代码

```c
int cmp(const void *a, const void *b)
{
    return *((int*)b) - *((int*)a); 
}

int largestPerimeter(int* A, int ASize){
    if ((A == NULL) || (ASize < 3)) {
        return 0;
    }
    qsort(A, ASize, sizeof(int), cmp);

    for (int i = 0; i < ASize - 2; i++) {
        if (*(A + i) < (*(A + i + 1) + *(A + i + 2))) {
            return *(A + i + 1) + *(A + i + 2) + *(A + i);
        } 
    }
    return 0;
   
}
```