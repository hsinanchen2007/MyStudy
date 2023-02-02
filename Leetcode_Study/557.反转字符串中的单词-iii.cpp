/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

/*

https://leetcode.cn/problems/reverse-words-in-a-string-iii/

557. 反转字符串中的单词 III

简单
514
company
Facebook
给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1：

输入：s = "Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"

示例 2:

输入： s = "God Ding"
输出："doG gniD"
 
提示：

1 <= s.length <= 5 * 104
s 包含可打印的 ASCII 字符。
s 不包含任何开头或结尾空格。
s 里 至少 有一个词。
s 中的所有单词都用一个空格隔开。

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.2, from https://walkccc.me/LeetCode/problems/0557/
    // Time: O(n)
    // Space: O(1)
    string reverseWords(string s) {
        int i = 0, j = 0;
        while (i < s.size()) {
            // s 不包含任何开头或结尾空格, so we don't need to check and consider if first character is empty or not
            while (i < j || i < s.size() && s[i] == ' ') i++;
            // so when i = 0, it will go to below while loop, do j++ until empty space
            while (j < i || j < s.size() && s[j] != ' ') j++;
            // reverse(begin, end) where end is the next one of last element, so we don't have to +1/-1 for it
            reverse(s.begin()+i, s.begin()+j);
        }
        return s;
    }
};


class Solution {
public:
    // 2023.2.2, from https://github.com/lzl124631x/LeetCode/blob/master/leetcode/557.%20Reverse%20Words%20in%20a%20String%20III/s1.cpp
    // OJ: https://leetcode.com/problems/reverse-words-in-a-string-iii
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    string reverseWords(string s) {
        for (int i = 0, begin = 0; i <= s.size(); ++i) {
            if (i == s.size() || isspace(s[i])) {
                reverse(s.begin() + begin, s.begin() + i);
                begin = i + 1;
            }
        }
        return s;
    }
};


// @lc code=end

