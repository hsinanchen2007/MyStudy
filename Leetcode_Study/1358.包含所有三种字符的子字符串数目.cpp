/*
 * @lc app=leetcode.cn id=1358 lang=cpp
 *
 * [1358] 包含所有三种字符的子字符串数目
 */

/*

https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/

1358. 包含所有三种字符的子字符串数目

中等
86
company
彭博 Bloomberg

给你一个字符串 s ，它只包含三种字符 a, b 和 c 。

请你返回 a，b 和 c 都 至少 出现过一次的子字符串数目。 

示例 1：

输入：s = "abcabc"
输出：10
解释：包含 a，b 和 c 各至少一次的子字符串为 "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" 和 "abc" (相同字符串算多次)。

示例 2：

输入：s = "aaacb"
输出：3
解释：包含 a，b 和 c 各至少一次的子字符串为 "aaacb", "aacb" 和 "acb" 。

示例 3：

输入：s = "abc"
输出：1 

提示：

3 <= s.length <= 5 x 10^4
s 只包含字符 a，b 和 c 。

*/

// @lc code=start
class Solution100 {
    int cnt[3] = {0};
    bool valid() {
        for (int n : cnt) 
            if (!n) return false;
        return true;
    }    
public:
    // 2023.2.19, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1358.%20Number%20of%20Substrings%20Containing%20All%20Three%20Characters
    int numberOfSubstrings(string s) {
        int L = 0, R = 0, N = s.size(), ans = 0;
        while (R < N) { 
            if (!valid()) cnt[s[R++] - 'a']++;
            while (valid()) {
                ans += N - R + 1;
                cnt[s[L++] - 'a']--;
            }
        }
        return ans;
    }
};


class Solution99 {
public:
    // 2023.2.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/number-of-substrings-containing-all-three-characters.cpp
    // Time:  O(n)
    // Space: O(1)
    int numberOfSubstrings(string s) {
        int result = 0;
        vector<int> left(3, -1);
        for (int right = 0; right < s.length(); ++right) {
            left[s[right] - 'a'] = right;
            result += *min_element(cbegin(left), cend(left)) + 1;
        }
        return result;
    }
};


class Solution98 {
public:
    // 2023.2.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/number-of-substrings-containing-all-three-characters.cpp
    // Time:  O(n)
    // Space: O(1)
    int numberOfSubstrings(string s) {
        int result = 0, left = 0;
        vector<int> count(3);
        for (int right = 0; right < s.length(); ++right) {
            ++count[s[right] - 'a'];
            while (all_of(cbegin(count), cend(count),
                          [](const auto& x) {
                              return x != 0;
                          })) {
                --count[s[left++] - 'a'];
            }
            result += left;
        }
        return result;
    }
};


class Solution {
public:
    // 2023.2.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/number-of-substrings-containing-all-three-characters.cpp
    // Time:  O(n)
    // Space: O(1)
    int numberOfSubstrings(string s) {
        int result = 0, right = 0;
        vector<int> count(3);
        for (int left = 0; left < s.length(); ++left) {
            while (right < s.length() &&
                   !all_of(cbegin(count), cend(count),
                           [](const auto& x) {
                              return x != 0;
                           })) {
                ++count[s[right++] - 'a'];
            }
            if (all_of(cbegin(count), cend(count),
                       [](const auto& x) {
                          return x != 0;
                       })) {
                result += (s.length() - 1) - (right - 1) + 1;
            }
            --count[s[left] - 'a'];
        }
        return result;
    }
};


// @lc code=end

