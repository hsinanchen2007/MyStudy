两个指针i和j分别指向haystack和needle串。
每次迭代逐位比较，主要是指针移动的条件判断：
1. 当两个当前字符相等时，i++,j++,并判断j是否越界，若越界就找到了，返回结果i-j；否则继续。
2. 当两个当前字符不相等时，先判断j是否越界，若未越界说明needle整体与haystack从i-j开始等长的字串不匹配，i重置到i-j的下一个位置，j重置为0；若越界，只需i++。

```
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 特殊情况判断
        if(haystack.length() < needle.length()) return -1;
        if(needle.length() == 0) return 0;
        
        // 双指针，i指向haystack，j指向needle
        int i = 0, j = 0;
        while(i < haystack.length()) {
            // 判断当前两个字符是否相等
            if(haystack[i] == needle[j]) {
                // 相等，则i，j自增1，若此时j越界，则找到索引
                j++;
                i++;
                if(j >= needle.length())
                    return i - j;
            }
            else {
                // 不相等，判断j是否越界
                if(j < needle.length()) {
                    //未越界，则i重置为haystack中与needle的第一个字符相等的第一个字符位置的后一位，j重置为0
                    i = i - j + 1;
                    j = 0;
                }
                else {
                    // 越界，i自增1
                    i++;
                }
            }
        }
        return -1;
    }
};
```
![捕获.JPG](https://pic.leetcode-cn.com/2ceff853abb53f30bcd7bd80be09f07d49652513c016653079ee20aea5a1afeb-%E6%8D%95%E8%8E%B7.JPG)


请看例子：
![1.png](https://pic.leetcode-cn.com/7c7bb60825444e13cc660b2c363b74e7f338f1e93c9b6a7f21d4b5c167c5c12d-1.png)
