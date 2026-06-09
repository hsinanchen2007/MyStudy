解法1：
```
package ZJM_9_回文数;

public class Main {
    public static void main(String[] args) {
        int num1 = 121;
        int num2 = -121;
        int num3 = 10;

        Solution solution = new Solution();
        System.out.println(solution.isPalindrome(num1));
        System.out.println(solution.isPalindrome(num2));
        System.out.println(solution.isPalindrome(num3));
    }
}

class Solution {
    public boolean isPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。（这较容易想到）
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性（0为回文易得，但最后一位为
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        //当逆转数大于x，就代表数已经有一半被逆转了，如121的一半21是大于12的或是1221的一半21是大于12的
        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber/10;
    }
}

/**
 * 解法一本题最基础解法是将int类型的数字转换为字符串，然后使用reverse()进行反转
 * 然后equals比较是否相等
 * 解法二是将整个数字进行反转，但有可能有溢出的问题
 * 解法三是最高级的解法，将数字的一半进行反转，与另一半进行验证是否是相等的
 * 将原始数字除以 10，然后给反转后的数字乘上 10，
 * 所以，当原始数字小于反转后的数字时，就意味着我们已经处理了一半位数的数字。（官方的奇思妙想）
 */

```
解法2：
```
package ZJM_9_回文数;

public class Main2 {
    public static void main(String[] args) {
        int num1 = 121;
        int num2 = -121;
        int num3 = 10;

        Solution2 solution = new Solution2();
        System.out.println(solution.isPalindrome(num1));
        System.out.println(solution.isPalindrome(num2));
        System.out.println(solution.isPalindrome(num3));
    }
}

class Solution2 {
    public boolean isPalindrome(int x) {
        StringBuilder s = new StringBuilder();
        s.append(x);

        return s.toString().equals(s.reverse().toString());
    }
}

/**
 * 偷懒的解法，所以题目中叫我们不要转化为字符串
 */

```
