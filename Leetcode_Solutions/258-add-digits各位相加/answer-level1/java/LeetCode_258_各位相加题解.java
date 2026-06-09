### 解题思路

从例子中的38的结果为2推算：

38 = 3 * 10 + 8 => 3 + 8 = 11

中间的差为 3 * 9

同理 11 = 1 * 10 + 1 => 1 + 1 = 2

中间的差等于 1 * 9

由此可得出差值可以被9整除。

每层循环都缩小了9的整数倍，直到最后的出来的结果小于10 => [1, 9]。

由此可以缩短为对9区域，因为区间在[1, 9]。所以将（原数 - 1）% 9 + 1即可。

### 代码

```java
class Solution {
    public int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
}
```

#### 递归实现

#### 代码

```java
class Solution {
    public int addDigits(int num) {
        if (num < 10) return num;

        int sum = 0;
        while (num != 0) {
            int digit = num % 10;
            sum += digit;
            num /= 10;
        }

        return addDigits(sum);
    }
}
```