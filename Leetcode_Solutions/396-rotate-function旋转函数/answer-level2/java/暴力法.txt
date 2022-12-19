### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/8d39c3602b168a7056645b23ea0b55bfd5a64cc7bb40f8a3d00d4b2ce3b55448-image.png)


### 代码

```java
class Solution {
    public int maxRotateFunction(int[] A) {
        int length = A.length;
        if (length == 0) {
            return 0;
        }
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < length; i++) {
            int sum = 0;
            for (int j = 0; j < length; j++) {
                sum += j * A[(i + j) % length];
            }
            max = Math.max(sum, max);
        }
        return max;
    }
}
```