### 解题思路
数组排序 

### 代码

```java
class Solution {
    public int largestPerimeter(int[] A) {
        Arrays.sort(A);
        //循环遍历计算从小的两条边之和是否大于第三条边
        for (int i = A.length - 3; i >= 0; --i)
            if (A[i] + A[i+1] > A[i+2])
                return A[i] + A[i+1] + A[i+2];
        return 0;
    }
}


```