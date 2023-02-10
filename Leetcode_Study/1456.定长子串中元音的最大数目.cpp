/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

/*

https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

1456. 定长子串中元音的最大数目

中等
56
company
字节跳动
给你字符串 s 和整数 k 。

请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。

英文中的 元音字母 为（a, e, i, o, u）。

示例 1：

输入：s = "abciiidef", k = 3
输出：3
解释：子字符串 "iii" 包含 3 个元音字母。

示例 2：

输入：s = "aeiou", k = 2
输出：2
解释：任意长度为 2 的子字符串都包含 2 个元音字母。

示例 3：

输入：s = "leetcode", k = 3
输出：2
解释："lee"、"eet" 和 "ode" 都包含 2 个元音字母。

示例 4：

输入：s = "rhythms", k = 4
输出：0
解释：字符串 s 中不含任何元音字母。

示例 5：

输入：s = "tryhard", k = 4
输出：1
 
提示：

1 <= s.length <= 10^5
s 由小写英文字母组成
1 <= k <= s.length

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.8, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/maximum-number-of-vowels-in-a-substring-of-given-length.cpp
    int maxVowels(string s, int k) {
        static const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int result = 0, curr = 0;
        for (int i = 0; i < s.length(); ++i) {
            curr += vowels.count(s[i]);
            if (i >= k) {
                curr -= vowels.count(s[i - k]);
            }
            result = max(result, curr);
        }
        return result;
    }
};


class Solution99 {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    // 2023.2.8, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1456.%20Maximum%20Number%20of%20Vowels%20in%20a%20Substring%20of%20Given%20Length
    // OJ: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    /*
        Solution 1. Sliding window
        We keep a sliding window of size k. Let i be the index of the new element getting into the window. We increment 
        cnt if s[i] is vowel. If i >= k, we need to pop s[i - k] out of the window and decrement cnt if s[i - k] is vowel. 
        The answer is the maximum cnt.
    */
    int maxVowels(string s, int k) {
        int cnt = 0, ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i >= k) cnt -= isVowel(s[i - k]);
            cnt += isVowel(s[i]);
            ans = max(ans, cnt);
        }
        return ans;
    }
};


class Solution {
public:
    // Author: Huahua
    int maxVowels(string s, int k) {    
        vector<int> v(128);
        v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = 1;
        int total = 0;
        int ans = 0;
        for (int i = 1; i <= s.length(); ++i) {
            total += v[s[i - 1]];
            if (i >= k) {
                ans = max(ans, total);
                total -= v[s[i - k]];
            }
        }
        return ans;
    }
};


// @lc code=end

