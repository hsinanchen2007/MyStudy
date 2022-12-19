### 解题思路
题目很简单，纸上简单画画可以找出规律

### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        int size = n / 2;
        int[] results = new int[n];
        int begin = 0;
        int end = n - 1;
        while (begin < end) {
            results[begin] = -size;
            results[end] = size;
            size--;
            begin++;
            end--;
        }
        return results;
    }
}
```