/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

/*

https://leetcode.cn/problems/longest-palindromic-substring/

5. 最长回文子串

中等
6.1K
company
亚马逊
company
字节跳动
company
思科 Cisco
给你一个字符串 s，找到 s 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

示例 2：

输入：s = "cbbd"
输出："bb" 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母组成

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.1, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/5.%20Longest%20Palindromic%20Substring
    // Solution 1: DP
    // OJ: https://leetcode.com/problems/longest-palindromic-substring/
    // Author: github.com/lzl124631x
    // Time: O(N^2)
    // Space: O(N)
    string longestPalindrome(string s) {
        int N = s.size(), start = 0, len = 0;
        bool dp[1001] = {};
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= i; --j) {
                if (i == j) dp[j] = true;
                else dp[j] = s[i] == s[j] && (i + 1 > j - 1 || dp[j - 1]);
                if (dp[j] && j - i + 1 > len) {
                    start = i;
                    len = j - i + 1;
                }
            }
        }
        return s.substr(start, len);
    }
};


class Solution99 {
    int expand(string &s, int L, int R) {
        while (L >= 0 && R < s.size() && s[L] == s[R]) --L, ++R;
        return R - L - 1;
    }
public:
    // 2023.2.1, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/5.%20Longest%20Palindromic%20Substring
    // Solution 2: Expanding from Middle
    // OJ: https://leetcode.com/problems/longest-palindromic-substring/
    // Author: github.com/lzl124631x
    // Time: O(N^2)
    // Space: O(1)
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expand(s, i, i), len2 = expand(s, i, i + 1);
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};


class Solution98 {
public:
    // 2023.2.1, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/5.%20Longest%20Palindromic%20Substring
    // Solution 3: Manacher
    // OJ: https://leetcode.com/problems/longest-palindromic-substring/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    string longestPalindrome(string s) {
        int N = s.size();
        string t = "^*";
        for (char c : s) {
            t += c;
            t += '*';
        }
        t += '$'; // inflating the `s` ( example: "abc" becomes "^*a*b*c*$" )
        int M = t.size();
        
        vector<int> r(M); // `r[i]` is the number of palindromes with `t[i]` as the center (aka. the radius of the longest palindrome centered at `t[i]`)
        r[1] = 1;
        int j = 1; // `j` is the index with the furthest reach `j + r[j]`
        for (int i = 2; i <= 2 * N; ++i) {
            int cur = j + r[j] > i ? min(r[2 * j - i], j + r[j] - i) : 1; // `t[2*j-i]` is the symmetry point to `t[i]`
            while (t[i - cur] == t[i + cur]) ++cur; // expanding the current radius
            if (i + cur > j + r[j]) j = i;
            r[i] = cur;
        }
        
        int len = 1, start = 0;
        for (int i = 2; i <= 2 * N; ++i) {
            if (r[i] - 1 > len) {
                len = r[i] - 1;
                start = (i - r[i]) / 2;
            }
        }
        return s.substr(start, len);
    }
};


class Solution97 {
public:
    // 2023.2.1, from https://walkccc.me/LeetCode/problems/0005/
    // Approach 1: Naive
    // Time: O(n^2)
    // Space: O(n)
    string longestPalindrome(string s) {
        if (s.empty())
        return "";

        // [start, end] indices of the longest palindrome in s
        pair<int, int> indices{0, 0};

        for (int i = 0; i < s.length(); ++i) {
        const auto [l1, r1] = extend(s, i, i);
        if (r1 - l1 > indices.second - indices.first)
            indices = {l1, r1};
        if (i + 1 < s.length() && s[i] == s[i + 1]) {
            const auto [l2, r2] = extend(s, i, i + 1);
            if (r2 - l2 > indices.second - indices.first)
            indices = {l2, r2};
        }
        }

        return s.substr(indices.first, indices.second - indices.first + 1);
    }

private:
    // Returns [start, end] indices of the longest palindrome extended from
    // s[i..j]
    pair<int, int> extend(const string& s, int i, int j) {
        for (; i >= 0 && j < s.length(); --i, ++j)
        if (s[i] != s[j])
            break;
        return {i + 1, j - 1};
    }
};


class Solution96 {
public:
    // 2023.2.1, from https://walkccc.me/LeetCode/problems/0005/
    // Approach 2: Manacher
    // Time: O(n)
    // Space: O(n)
    string longestPalindrome(string s) {
        // @ and $ signs are sentinels appended to each end to avoid bounds checking
        const string& t = join('@' + s + '$', '#');
        const int n = t.length();
        // t[i - maxExtends[i]..i) ==
        // t[i + 1..i + maxExtends[i]]
        vector<int> maxExtends(n);
        int center = 0;

        for (int i = 1; i < n - 1; ++i) {
        const int rightBoundary = center + maxExtends[center];
        const int mirrorIndex = center - (i - center);
        maxExtends[i] =
            rightBoundary > i && min(rightBoundary - i, maxExtends[mirrorIndex]);

        // Attempt to expand palindrome centered at i
        while (t[i + 1 + maxExtends[i]] == t[i - 1 - maxExtends[i]])
            ++maxExtends[i];

        // If palindrome centered at i expand past rightBoundary,
        // adjust center based on expanded palindrome.
        if (i + maxExtends[i] > rightBoundary)
            center = i;
        }

        // Find the maxExtend and bestCenter
        int maxExtend = 0;
        int bestCenter = -1;

        for (int i = 0; i < n; ++i)
        if (maxExtends[i] > maxExtend) {
            maxExtend = maxExtends[i];
            bestCenter = i;
        }

        const int l = (bestCenter - maxExtend) / 2;
        const int r = (bestCenter + maxExtend) / 2;
        return s.substr(l, r - l);
    }

private:
    string join(const string& s, char c) {
        string joined;
        for (int i = 0; i < s.length(); ++i) {
        joined += s[i];
        if (i != s.length() - 1)
            joined += c;
        }
        return joined;
    }
};


class Solution95 {
public:
    // 作者：⊙_⊙
    // 链接：https://leetcode.cn/leetbook/read/array-and-string/conm7/?discussion=BMElkd
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    string longestPalindrome(string s) {
        int i = 0, j = 0;
        for(int k=1; k<s.size(); k++)
        {
            int i0 = k, j0 = k;//奇数回文
            while(i0>0 && j0<s.size()-1)
            {
                if(s[i0-1]==s[j0+1])
                {
                    i0--;
                    j0++;
                }
                else    break;
            }
            if(j0-i0 > j-i) 
            {
                i = i0;
                j = j0;
            }

            i0 = k, j0 = k-1;//偶数回文
            while(i0>0 && j0<s.size()-1)
            {
                if(s[i0-1]==s[j0+1])
                {
                    i0--;
                    j0++;
                }
                else    break;
            }
            if(j0-i0 > j-i) 
            {
                i = i0;
                j = j0;
            }
        } 
        return s.substr(i,j-i+1);
    }
};


class Solution94 {
public:
    // 作者：CainHuang
    // 链接：https://leetcode.cn/leetbook/read/array-and-string/conm7/?discussion=v7utYQ
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        1、动态规划
        从长度length为1，到长度s.size()进行遍历，每个长度都从i = 0开始遍历，结尾j = i + length - 1
        if length == 1， dp[i][j] == 1
        else if length == 2, dp[i][j] = (s[i] == s[j])
        else dp[i][j] = (s[i] == s[j] && dp[i+1][j-1])
    */
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int length = 1; length <= n; ++length) {
            for (int i = 0; i + length - 1 < n; ++i) {
                int j = i + length - 1;
                if (length == 1) {
                    dp[i][j] = 1;
                } else if (length == 2) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                if (dp[i][j] && length > ans.size()) {
                    ans = s.substr(i, length);
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    // 作者：CainHuang
    // 链接：https://leetcode.cn/leetbook/read/array-and-string/conm7/?discussion=v7utYQ
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        2、中心扩散法：
        从前面的判断可以知道，dp[i][j] -> dp[i - 1][j + 1] -> dp[i - 2][j + 2] -> ... -> 某个边界结束，
        得到边界条件为 length == 1 或者 length == 2，我们以这个边界作为中心，进行循环扩散，直到两边的值不相同为止，然后返回这个边界下标，
        用于给外面判断最长字串，扩散代码如下：

        pair<int, int> expandAroundCenter(const string& s, int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                --left;
                ++right;
            }
            return {left+1, right-1};
        }
        
        在得到中心扩散方法后，遍历字符串，以索尼i为基准的两个边界进行扩散，然后计算出最大的字串索引，遍历完成，直接返回最长子串
    */
    string longestPalindrome(string s) {
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > right - left) {
                left = left1;
                right = right1;
            } 
            if (right2 - left2 > right - left) {
                left = left2;
                right = right2;
            }
        }
        return s.substr(left, right - left + 1);
    }

    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
};


// @lc code=end

