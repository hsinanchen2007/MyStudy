### 解题思路
最后一个数等于前面数的和的相反数

### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        int[] arr = new int[n];
        int sum = 0;
        for (int i = 0; i <= n-2; i++) {
            arr[i] = i;
            sum += i;
        }
        arr[n-1] = -sum;
        return arr;
    }
}
```