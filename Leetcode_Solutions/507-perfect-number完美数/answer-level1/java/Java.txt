### 代码

```java
class Solution {
    /**
     * 要验证一个数字是否是 “完美数”，我们需要获得这个数所有可能的正因子
     *
     * 那么我们需要从 1 开始，遍历到这个数字的二分之一大小，计算所有的正因子的和
     *
     * 然后正确的代码如下：
     *
     * 个人的记录的 Java 版本代码题库：https://github.com/llyer/leetcode
     *
     * @param num
     * @return
     */
    public boolean checkPerfectNumber(int num) {
        if (num == 0) return false;
        int count = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                count += i;
            }
        }
        return  count == num ? true : false;
    }
}
```