/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

/*

https://leetcode.cn/problems/reverse-string-ii/

541. 反转字符串 II
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 

示例 1：

输入：s = "abcdefg", k = 2
输出："bacdfeg"

示例 2：

输入：s = "abcd", k = 2
输出："bacd"
 

提示：

1 <= s.length <= 104
s 仅由小写英文组成
1 <= k <= 104
通过次数129,772提交次数218,759

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.md
    /*
        这道题目其实也是模拟，实现题目中规定的反转规则就可以了。

        一些同学可能为了处理逻辑：每隔2k个字符的前k的字符，写了一堆逻辑代码或者再搞一个计数器，来统计2k，再统计前k个字符。
        其实在遍历字符串的过程中，只要让 i += (2 * k)，i 每次移动 2 * k 就可以了，然后判断是否需要有反转的区间。
        因为要找的也就是每2 * k 区间的起点，这样写，程序会高效很多。

        所以当需要固定规律一段一段去处理字符串的时候，要想想在在for循环的表达式上做做文章。

        性能如下： 
        那么这里具体反转的逻辑我们要不要使用库函数呢，其实用不用都可以，使用reverse来实现反转也没毛病，毕竟不是解题关键部分。
    */
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
            } else {
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};


class Solution99 {
public:
    // 2022.7.23, from https://github.com/lzl124631x/LeetCode/blob/master/leetcode/541.%20Reverse%20String%20II/s1.cpp
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k)
        reverse(s.begin() + i, s.begin() + min((int)s.size(), i + k));
        return s;
    }
};


class Solution98 {
public:
    // 2022.7.23, from https://walkccc.me/LeetCode/problems/0541/
    string reverseStr(string s, int k) {
        for (size_t i = 0; i < s.length(); i += 2 * k) {
        int l = i;
        int r = min(i + k - 1, s.length() - 1);
        while (l < r)
            swap(s[l++], s[r--]);
        }

        return s;
    }
};


class Solution97 {
public:
    // 2022.7.23, from https://www.guozet.me/leetcode/Leetcode-541-Reverse-String-II.html?h=reverses
    string reverseStr(string s, int k) {
        int n = s.size(), count = n/2;
        for (int i = 0; i < count; ++i) {
            if(i % 2 == 0) {
                if (i*k + k < n)
                    reverse(s.begin()+i*k, s.begin()+(i+1)*k);
                else
                    reverse(s.begin()+i*k, s.begin()+n);
            }
        }
        return s;
    }
};


class Solution96 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/reverse-string-ii.cpp
    // Time:  O(n)
    // Space: O(1)
    string reverseStr(string s, int k) {
        for (int left = 0; left < s.size(); left += 2 * k) {
            for (int i = left, j = min(left + k - 1, static_cast<int>(s.size()) - 1);
                 i < j; ++i, --j) {
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};


class Solution95 {
public:
    // 2022.7.23, from AcWing https://www.acwing.com/activity/content/code/content/597655/
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += k * 2) {
            int l = i, r = min(i + k, (int)s.size());
            reverse(s.begin() + l, s.begin() + r);
        }
        return s;
    }
};


class Solution94 {
public:
    // 2022.7.26, from https://github.com/grandyang/leetcode/issues/541
    /*
        这道题是之前那道题Reverse String的拓展，同样是翻转字符串，但是这里是每隔k隔字符，翻转k个字符，最后如果不够k个了的话，
        剩几个就翻转几个。比较直接的方法就是先用n／k算出来原字符串s能分成几个长度为k的字符串，然后开始遍历这些字符串，遇到2的倍数
        就翻转，翻转的时候注意考虑下是否已经到s末尾了，参见代码如下：
    */
    string reverseStr(string s, int k) {
        int n = s.size(), cnt = n / k;
        for (int i = 0; i <= cnt; ++i) {
            if (i % 2 == 0) {
                if (i * k + k < n) {
                    reverse(s.begin() + i * k, s.begin() + i * k + k);
                } else {
                    reverse(s.begin() + i * k, s.end());
                }
            }
        }
        return s;
    }
};


class Solution {
public:
    // 2022.7.26, from https://github.com/grandyang/leetcode/issues/541
    /*
        在论坛里又发现了写法更为简洁的方法，就是每2k个字符来遍历原字符串s，然后进行翻转，翻转的结尾位置是取i+k
        和末尾位置之间的较小值，感觉很叼，参见代码如下：
    */
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        return s;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

