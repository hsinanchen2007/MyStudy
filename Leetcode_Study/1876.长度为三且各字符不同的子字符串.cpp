/*
 * @lc app=leetcode.cn id=1876 lang=cpp
 *
 * [1876] 长度为三且各字符不同的子字符串
 */

/*

https://leetcode.cn/problems/substrings-of-size-three-with-distinct-characters/

1876. 长度为三且各字符不同的子字符串
如果一个字符串不含有任何重复字符，我们称这个字符串为 好 字符串。

给你一个字符串 s ，请你返回 s 中长度为 3 的 好子字符串 的数量。

注意，如果相同的好子字符串出现多次，每一次都应该被记入答案之中。

子字符串 是一个字符串中连续的字符序列。
 

示例 1：

输入：s = "xyzzaz"
输出：1
解释：总共有 4 个长度为 3 的子字符串："xyz"，"yzz"，"zza" 和 "zaz" 。
唯一的长度为 3 的好子字符串是 "xyz" 。

示例 2：

输入：s = "aababcabc"
输出：4
解释：总共有 7 个长度为 3 的子字符串："aab"，"aba"，"bab"，"abc"，"bca"，"cab" 和 "abc" 。
好子字符串包括 "abc"，"bca"，"cab" 和 "abc" 。
 

提示：

1 <= s.length <= 100
s​​​​​​ 只包含小写英文字母。
通过次数12,017提交次数16,863

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.19, by Hsinan
    int countGoodSubstrings(string s) {
        int start = 0;
        int total_nice = 0;
        unordered_map<char, int> hashTbl;
        for (int end = 0; end < s.size(); end++) {
            hashTbl[s[end]]++;
            if (end - start + 1 == 3) {
                // perform check when window size is 3
                bool isNice = true;
                for (int j = start; j <= end; j++) {
                    if (hashTbl[s[j]] > 1) {
                        // has duplicated one
                        isNice = false;
                        break;
                    }
                }
                // update counter if it's nice
                if (isNice) total_nice++;
                // update hashTbl, decrease start and start++
                hashTbl[s[start++]]--;
            }
        }
        return total_nice;
    }
};


class Solution99 {
public:
    // 2022.8.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/substrings-of-size-three-with-distinct-characters.cpp
    // Time:  O(n)
    // Space: O(1)
    int countGoodSubstrings(string s) {
        static const int K = 3;

        int result = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < size(s); ++i) {
            if (i >= K) {
                if (--count[s[i - K]] == 0) {
                    count.erase(s[i - K]);
                }
            }
            ++count[s[i]];
            if (size(count) == K) {
                ++result;
            }
        }
        return result;
    }
};


class Solution98 {
public:
    // 2022.8.19, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1876.%20Substrings%20of%20Size%20Three%20with%20Distinct%20Characters
    // OJ: https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int countGoodSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i+ 2 < s.size(); ++i) {
            ans += s[i] != s[i+1] && s[i+1] != s[i+2] && s[i] != s[i+2];
        }
        return ans;
    }
};


class Solution97 {
public:
    // 2022.8.19, from https://walkccc.me/LeetCode/problems/1876/
    int countGoodSubstrings(string s) {
        int ans = 0;

        for (int i = 0; i + 2 < s.length(); ++i) {
            const char a = s[i];
            const char b = s[i + 1];
            const char c = s[i + 2];
            if (a == b || a == c || b == c)
                continue;
            ++ans;
        }

        return ans;
    }
};



class Solution {
public:
    // 2022.8.19, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/1501-2000/1876-Substrings-of-Size-Three-with-Distinct-Characters/cpp-1876/main.cpp
    // Linear Scan
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int countGoodSubstrings(string s) {
        int res = 0;
        for(int i = 2; i < s.size(); i ++)
            res += ((s[i-2]!=s[i-1]) && (s[i-1]!=s[i]) && (s[i]!=s[i-2]));
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

