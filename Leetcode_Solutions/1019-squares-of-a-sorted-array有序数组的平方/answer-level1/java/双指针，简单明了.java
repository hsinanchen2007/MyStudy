### 解题思路
双指针，判断绝对值大小

### 代码

```java
class Solution {
    public int[] sortedSquares(int[] A) {
        int head = 0, last = A.length - 1, index = A.length - 1;
        int[] result = new int[A.length];

        while (head <= last) {
            if (Math.abs(A[head]) < Math.abs(A[last])) result[index--] = (int) Math.pow(A[last--], 2);
            else result[index--] = (int) Math.pow(A[head++], 2);
        }

        return result;
    }
}
```