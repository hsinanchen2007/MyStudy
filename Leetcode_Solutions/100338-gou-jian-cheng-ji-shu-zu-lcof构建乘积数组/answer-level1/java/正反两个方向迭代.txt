### 解题思路

两次迭代，从不同方向，时间复杂度O(n)
```
let K[i] = A[0]XA[1]X...A[i];
let V[i] = A[i]XA[i+1]X..A[n-1];
B[i] = K[i - 1] * V[i + 1];
```

![image.png](https://pic.leetcode-cn.com/245125ad610f4927c5dfecbfe1ddb79ed1788e7e730f1aeee59b052a84554ebc-image.png)

### 代码

```java
class Solution {
    public int[] constructArr(int[] a) {
        int[] result = new int[a.length];
        Arrays.fill(result, 1);
        int val = 1;
        for (int i = 0; i < a.length; i++) {
            result[i] *= val;
            val *= a[i];
        }
        val = 1;
        for (int i = a.length - 1; i >= 0; i--) {
            result[i] *= val;
            val *= a[i];
        }
        return result;
    }
}
```