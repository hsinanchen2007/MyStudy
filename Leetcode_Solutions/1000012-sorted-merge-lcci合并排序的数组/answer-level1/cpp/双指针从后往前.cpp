### 解题思路
两个都是有序数组，把B的元素插入A，最终的结果是B的元素全部插入A。
设定3个指针(or 数组索引）：
1. pointer i 指向数组A的最末端-> m+n-1;
2. pointer p 指向有序数组A的最后一个有效元素->m-1;
3. pointer k 指向有序数组B的最后一个有效元素->n-1;
每次比较A[p]和B[k]的大小，把大的元素插入末尾A[i]。
pointer i 向前移动一位。
已经被赋值的元素索引向前移动一位。一直到两个数组中的任意一个遍历结束。

收尾工作：
存在B数组元素中的元素比A数组中最小的还要小。那么A遍历结束了，B还有元素未插入。
所以需要将的B数组中剩下的元素从头插入到A数组中。

只要B数组遍历结束，即代表B数组全部插入A数组。所以，A数组有剩余元素未遍历的情况不做考虑。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int p = m-1;
        int k = n-1;
        int i = m+n-1;
        while(k>=0 && p>=0)
        {
            A[i--] = A[p]>B[k]?A[p--]:B[k--];
        }
        for(int j = 0; j<=k;j++)
        {
            A[j] = B[j];
        }
    }
};
```