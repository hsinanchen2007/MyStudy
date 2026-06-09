**思路**
1. 先将A数组中的m个元素移动到末尾；
2. 然后利用归并排序的merge思想，每次取出A和B数组头元素中的最小值逐个放到A数组中。

以上说法有点抽象，我们举个例子吧。假设$A = [1,2,3,0,0,0], B = [2,5,6]$。A数组元素的变化过程如下：
1. $[0,0,0,1,2,3]$
2. $[1,0,0,1,2,3]$
3. $[1,2,0,0,0,3]$
4. $[1,2,2,0,0,3]$
5. $[1,2,2,3,0,0]$
6. $[1,2,2,3,5,0]$
7. $[1,2,2,3,5,6]$

说明：以上元素被移动到正确的位置上后，其实无需置0（为了演示看起来更加直观，置0）。

具体详见如下代码：

```java
    public void merge(int[] A, int m, int[] B, int n) {
        // 先将A右移到末尾
        System.arraycopy(A, 0, A, n, m);

        int index = 0;
        int indexA, indexB;
        for (indexA = n, indexB = 0; indexA < m + n && indexB < n;) {
            if (A[indexA] <= B[indexB]) {
                A[index++] = A[indexA++];
            } else {
                A[index++] = B[indexB++];
            }
        }

        while (indexA < m + n) {
            A[index++] = A[indexA++];
        }

        while (indexB < n) {
            A[index++] = B[indexB++];
        }
    }
```

**复杂度分析**
时间复杂度：$O(m + n)$
空间复杂度：$O(1)$