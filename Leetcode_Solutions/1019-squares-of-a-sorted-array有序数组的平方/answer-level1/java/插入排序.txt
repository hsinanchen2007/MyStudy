### 解题思路
还是插入排序思想, 总结合并类的都可以使用插入排序来处理,唯一需要区别的就是如果是已经有序的则可以利用有序的特点时间复杂度达到O(m+n),如果无序每次插入都需要和已有的进行排序则是O(m*n)
 /**
     * 思路: 两个指针,p1 p2 ,分别指向负数和正数
     * 对比平方值, 采用插入排序思想,
     * 时间复杂度 O(n+n/2)
     * 空间复杂度 O(n)
     * @param A
     * @return
     */
### 代码

```java
class Solution {
    public int[] sortedSquares(int[] A) {
        Objects.requireNonNull(A);
        if (A[0] >= 0 ) {
            for (int i = 0; i < A.length; i++)
                A[i] = A[i] * A[i];
            return A;
        }
        if (A[A.length - 1] <= 0) {
            int[] temp = new int[A.length];
            System.arraycopy(A, 0, temp, 0, A.length);
            int len = A.length - 1;
            for (int i = 0; i < A.length; i++) {
                A[i] = temp[len] * temp[len--];
            }
            return A;
        }
        int[] ans = new int[A.length];
        int p1 = 0, p2 = 0, p1Len = 0;
        // 找到第一个非负值
        while (p2 < A.length && A[p2++] < 0);
        p2--;
        p1 = p2 - 1;
        int i = 0;
        while (p1 >=0 && p2 < A.length)
            ans[i++] = (A[p1] + A[p2] >0)? A[p1] * A[p1--]: A[p2] * A[p2++];
        while (p1 >= 0)
            ans[i++] = A[p1] * A[p1--];
        while (p2 < A.length)
            ans[i++] = A[p2] * A[p2++];
        return ans;
    }
}
```