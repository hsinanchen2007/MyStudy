### 解题思路
参考自精选大佬，需要注意的是，此时的数学模型已经变换，因此最后返回的是a，和题目提供的公式思想上虽一致，但是实际算法数值上的操作已经发生了变换

### 代码

```java
class Solution {
    public int fib(int n) {
        int a = 0, b = 1, sum;
        for(int i = 0; i < n; i++){
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
}
```