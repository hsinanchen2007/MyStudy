解法一：此题的思路跟**整数反转**有点类似。比如：1221，对x取模得余数（末位）1，再对x取商得（首位）1，再判断这2个数是否相等。然后将x去掉首尾得中间值22，再依次循环判断！末位数一直将x % pre就可以，首位数需要将x / post， 这个值可以事先算好(为10^x的长度-1)，每经历一次循环，x的长度减少2位，pre=10不变，post /= 100； 

     class Solution {
        public boolean isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int pre = 1;
        // 算取初始pre的值
        while (x / pre >= 10) {
            pre = pre * 10;
        }
        // 固定post的值
        int post = 10;
        while (pre >= post) {
            int postfix = x % post;
            int prefix = x / pre;
            // 判断首位和末尾的值是否相同
            if(prefix != postfix) {
                return false;
            }
            // x的值去掉首 尾，得到新的x值
            x = x % pre;
            x = x / post;
            // pre的值随x长度变化而变化
            pre = pre / 100;
        }
        return true;
      }
    }

