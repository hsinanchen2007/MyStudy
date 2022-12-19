### 解题思路
首先我们知道异或的两个简单性质：
- 相同的两个数异或结果为`0`，即`a ^ a = 0`
- 一个数跟`0`异或结果为它本身，即`a ^ 0 = a`
 
那么对于给定的两个数`a`和`b`：
操作 | a |  b | 备注
:-:|:-:|:-:|:-:
a ^= b | a ^ b  | b |
b ^= a | a ^ b | a | b = b ^ (a ^ b) = a
a ^= b | b | a | a = (a ^ b) ^ a = b


### 代码

```java
class Solution {
    public int[] swapNumbers(int[] numbers) {
        if (numbers == null || numbers.length < 2) {
            return numbers;
        }
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0];
        numbers[0] ^= numbers[1];
        return numbers;
    }
}
```