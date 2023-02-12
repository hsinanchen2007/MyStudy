/*

https://leetcode.cn/problems/find-k-length-substrings-with-no-repeated-characters/

1100. 长度为 K 的无重复字符子串

中等
46
company
亚马逊

给你一个字符串 S，找出所有长度为 K 且不含重复字符的子串，请你返回全部满足要求的子串的 数目。

示例 1：

输入：S = "havefunonleetcode", K = 5
输出：6
解释：
这里有 6 个满足题意的子串，分别是：'havef','avefu','vefun','efuno','etcod','tcode'。

示例 2：

输入：S = "home", K = 5
输出：0
解释：
注意：K 可能会大于 S 的长度。在这种情况下，就无法找到任何长度为 K 的子串。
 

提示：

1 <= S.length <= 10^4
S 中的所有字符均为小写英文字母
1 <= K <= 10^4

*/

class Solution100 {
public:
    // 2023.2.12, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-k-length-substrings-with-no-repeated-characters.cpp
    // Time:  O(n)
    // Space: O(k)
    int numKLenSubstrNoRepeats(string S, int K) {
        int result = 0, i = 0;
        unordered_set<int> lookup;
        for (int j = 0; j < S.length(); ++j) {
            while (lookup.count(S[j])) {
                lookup.erase(S[i]);
                ++i;
            }
            lookup.emplace(S[j]);
            result += int(j - i + 1 >= K);
        }
        return result;
    }
};


class Solution99 {
public:
    // OJ: https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int numKLenSubstrNoRepeats(string s, int k) {
        int N = s.size(), ans = 0, cnt[26] = {}, unique = 0;
        for (int i = 0; i < N; ++i) {
            if (++cnt[s[i] - 'a'] == 1) ++unique;
            if (i - k >= 0 && --cnt[s[i - k] - 'a'] == 0) --unique;
            ans += unique == k;
        }
        return ans;
    }
};


class Solution {
public:
    // 2023.2.12, from https://walkccc.me/LeetCode/problems/1100/
    int numKLenSubstrNoRepeats(string s, int k) {
        int ans = 0;
        int unique = 0;
        vector<int> count(26);

        for (int i = 0; i < s.length(); ++i) {
            if (++count[s[i] - 'a'] == 1)
                ++unique;
            if (i >= k && --count[s[i - k] - 'a'] == 0)
                --unique;
            if (unique == k)
                ++ans;
        }

        return ans;
    }
};