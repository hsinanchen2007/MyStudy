### 解题思路
此处撰写解题思路
算出反转之后的数值, 如果和原数值相等, 则认为数回力数; 如果x < 0, 则直接返回false

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
    int num = x;
    if (x < 0) {
            return false;
        }
        /*
         * 思路: 把原来的数字挨个拆开, 组成一个新的数字, 如果两个一样大, 则可以的
         */

        int a = 0;
        while (x != 0) {
            a = a * 10 + x % 10;
            x = x / 10;
        }
        return a == num;
    }
}
```