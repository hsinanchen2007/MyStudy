### 解题思路
通过快慢指针来结束循环。
### 代码

```java
class Solution {
    public boolean isHappy(int n) {
        int slow = n, fast = n;
        do {
            fast = change(fast);
            fast = change(fast);
            slow = change(slow);

        } while (slow != fast);
        return slow == 1;
    }

    private int change(int n) {
        int sum = 0;
        int num;
        while (n != 0) {
            num = n % 10;
            n /= 10;
            sum += num * num;
        }
        return sum;
    }
}
```