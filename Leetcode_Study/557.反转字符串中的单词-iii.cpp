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


class Solution99 {
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


class Solution98 {
public:
    // 2023.2.10, from https://github.com/grandyang/leetcode/issues/557
    /*
        这道题让我们翻转字符串中的每个单词，感觉整体难度要比之前两道Reverse Words in a String II和Reverse Words in a String要小一些，
        由于题目中说明了没有多余空格，使得难度进一步的降低了。首先我们来看使用字符流处理类stringstream来做的方法，相当简单，就是按顺序读入
        每个单词进行翻转即可，参见代码如下：    
    */
    string reverseWords(string s) {
        string res = "", t = "";
        istringstream is(s);
        while (is >> t) {
            reverse(t.begin(), t.end());
            res += t + " ";
        }
        res.pop_back();
        return res;
    }
};


class Solution97 {
public:
    // 2023.2.10, from https://github.com/grandyang/leetcode/issues/557
    /*
        下面我们来看不使用字符流处理类，也不使用STL内置的reverse函数的方法，那么就是用两个指针，分别指向每个单词的开头和结尾位置，确定了单词
        的首尾位置后，再用两个指针对单词进行首尾交换即可，有点像验证回文字符串的方法，参见代码如下：    
    */
    string reverseWords(string s) {
        string res = "", t = "";
        istringstream is(s);
        while (is >> t) {
            reverse(t.begin(), t.end());
            res += t + " ";
        }
        res.pop_back();
        return res;
    }
};


class Solution96 {
public:
    // 2023.2.10, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/reverse-words-in-a-string-iii.cpp
    // Time:  O(n)
    // Space: O(1)
    string reverseWords(string s) {
        for (int i = 0, j = 0; j <= s.length(); ++j) {
            if (j == s.length() || s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        return s;
    }
};


class Solution95 {
public:
    // OJ: https://leetcode.com/problems/reverse-words-in-a-string-iii
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    string reverseWords(string s) {
        for (int i = 0, int begin = 0; i <= s.size(); ++i) {
            if (i == s.size() || isspace(s[i])) {
                reverse(s.begin() + begin, s.begin() + i);
                begin = i + 1;
            }
        }
        return s;
    }
};


class Solution {
public:
    // 2023.2.10, from https://walkccc.me/LeetCode/problems/0557/
    string reverseWords(string s) {
        int i = 0;
        int j = 0;

        while (i < s.length()) {
            while (i < j || i < s.length() && s[i] == ' ')
                ++i;
            while (j < i || j < s.length() && s[j] != ' ')
                ++j;
            reverse(begin(s) + i, begin(s) + j);
        }

        return s;
    }
};


// @lc code=end

