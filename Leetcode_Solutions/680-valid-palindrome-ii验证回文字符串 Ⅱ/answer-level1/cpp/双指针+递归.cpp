![680.PNG](https://pic.leetcode-cn.com/f343072dde792018c523ce8cacb40c91469b944ced2eafe76d3fad270f01eecb-680.PNG)

验证回文字符串方法最常用的就是双指针，从头和尾夹逼，判断是不是相同，不相同就返回false
本题增加一个条件，能够删除一个字符，并且最多删除一个，因此增加一个统计删除字符次数的count变量
还是利用双指针验证回文字符串的方法，不过在出现不一致的情况下，不能直接返回false，是先判断次数是不是超过1次了，超过的话直接返回false
没超过的话，有两种可能性，删除左边的或者删除右边的，只要有一种情况下剩余的字符串仍然是回文的话，则返回true，因此直接进行递归，返回两者的或
```
// 最多删除一个字符
class Solution {
public:
    int count = 0;
    bool validPalindrome(string s) 
    {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right]) {
                if (count < 1) {
                    count++;
                    return (validPalindrome(s.substr(left, (right - left))) || validPalindrome(s.substr(left + 1, (right - left))));
                } else {
                    return false;
                }  
            }
            left++;
            right--;
        }
        return true;
    }
};
```
