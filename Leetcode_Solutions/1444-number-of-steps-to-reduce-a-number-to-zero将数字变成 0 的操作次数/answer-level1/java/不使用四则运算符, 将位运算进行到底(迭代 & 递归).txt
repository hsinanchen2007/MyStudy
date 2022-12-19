### 解题思路
以32位二进制为例, 例如15(0x0000000f):
1. 遇奇减1, 即将末位1变为0, 和0xfffffffe(-2)取&即可;
2. 遇偶除2, 即右移一位即可;
3. 两种情况都需要次数加1.

### 迭代

```java
class Solution {
    public int numberOfSteps (int num) {
        int count = 0;
        while (num != 0) {
            count++;
            num = (num & 1) == 1 ? num & -2 : num >> 1;
        }
        return count;
    }
}
```

### 递归
```java
class Solution {

    private int count = 0;

    public int numberOfSteps (int num) {
        if (num != 0) {
            count++;
            if ((num & 1) != 0) {
                numberOfSteps(num & -2);
            } else {
                numberOfSteps(num >> 1);
            }
        }
        return count;
    }
}
```


### Tips
其实对于count的自增操作, 也可以转变为count + 1, 按照[**371.两整数之和**](https://leetcode-cn.com/problems/sum-of-two-integers/)的思路, 让代码只存在位运算和逻辑运算.