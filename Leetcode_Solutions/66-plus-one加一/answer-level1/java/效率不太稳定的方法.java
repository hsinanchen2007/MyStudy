### 解题思路
    其实该方法是基于字符串、链表相加。
    只要检索每一位，如果加起来（包括carry）不是大于9的，直接更新当前下标值并return。
    否则就继续检索下一位。
    这里我感觉效率不太稳定原因是遇到需要扩容时候，我这里是建了新的空数组，为原数组length + 1大小。
    然后第一位被carry占掉，剩余的依原数组顺序。这里还望大神指导下效率问题是否有影响。
![捕获.PNG](https://pic.leetcode-cn.com/bd1a31e49b0cc4ce2f9f93933bd39402760361d3274f2cf631fdf9a58acc2539-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int i = digits.length - 1, carry = 0;
        while (i >= 0) {
            int temp = i == digits.length - 1 ? digits[i] + 1 + carry : digits[i] + carry;
            if (temp < 10) {
                digits[i] = temp;
                return digits;
            }
            carry = temp / 10;
            digits[i] = temp % 10;
            i--;
        }
        if (carry > 0) {
            int l = digits.length;
            int[] res = new int[l + 1];
            res[0] = carry;
            System.arraycopy(digits, 0, res, 1, res.length - 1);
            return res;
        }
        return digits;
    }
}
```