/*
 * @lc app=leetcode.cn id=1763 lang=cpp
 *
 * [1763] 最长的美好子字符串
 */

/*

https://leetcode.cn/problems/longest-nice-substring/

1763. 最长的美好子字符串
当一个字符串 s 包含的每一种字母的大写和小写形式 同时 出现在 s 中，就称这个字符串 s 是 美好 字符串。比方说，"abABB" 
是美好字符串，因为 'A' 和 'a' 同时出现了，且 'B' 和 'b' 也同时出现了。然而，"abA" 不是美好字符串因为 'b' 出现了，
而 'B' 没有出现。

给你一个字符串 s ，请你返回 s 最长的 美好子字符串 。如果有多个答案，请你返回 最早 出现的一个。如果不存在美好子字符串，
请你返回一个空字符串。

 
示例 1：

输入：s = "YazaAay"
输出："aAa"
解释："aAa" 是一个美好字符串，因为这个子串中仅含一种字母，其小写形式 'a' 和大写形式 'A' 也同时出现了。
"aAa" 是最长的美好子字符串。

示例 2：

输入：s = "Bb"
输出："Bb"
解释："Bb" 是美好字符串，因为 'B' 和 'b' 都出现了。整个字符串也是原字符串的子字符串。

示例 3：

输入：s = "c"
输出：""
解释：没有美好子字符串。

示例 4：

输入：s = "dDzeE"
输出："dD"
解释："dD" 和 "eE" 都是最长美好子字符串。
由于有多个美好子字符串，返回 "dD" ，因为它出现得最早。
 

提示：

1 <= s.length <= 100
s 只包含大写和小写英文字母。
通过次数25,830提交次数37,694

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.17, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-nice-substring.cpp
    string longestNiceSubstring(string s) {
        array<array<int, 2>, 26> lookup = {0};
        for (const auto& c : s) {
            lookup[tolower(c) - 'a'][isupper(c) != 0] = 1;
        }
        string result;
        for (int i = 0, prev = -1; i <= size(s); ++i) {
            if (!(i == size(s) || !lookup[tolower(s[i]) - 'a'][0] || !lookup[tolower(s[i]) - 'a'][1])) {
                continue;
            }
            if (prev == -1 && i == size(s)) {
                return s;
            }
            auto tmp = longestNiceSubstring(s.substr(prev + 1, i - prev - 1));
            if (size(tmp) > size(result)) {
                result = move(tmp);
            }
            prev = i;
        }
        return result;
    }
};


class Solution99 {
    // 2022.8.17, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1763.%20Longest%20Nice%20Substring
    // OJ: https://leetcode.com/problems/longest-nice-substring/
    // Author: github.com/lzl124631x
    // Time: O(N^2)
    // Space: O(N)
    // Solution 1. Brute force
    bool nice(string &s) {
        int up[26] = {}, low[26] = {};
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') up[c - 'A'] = 1;
            else low[c - 'a'] = 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (up[i] ^ low[i]) return false;
        }
        return true;
    }
public:
    string longestNiceSubstring(string s) {
        int N = s.size();
        for (int len = N; len >= 2; --len) {
            for (int i = 0; i <= N - len; ++i) {
                auto sub = s.substr(i, len);
                if (nice(sub)) return sub;
            }
        }
        return "";
    }
};


class Solution98 {
    string ans;
public:
    // 2022.8.17, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1763.%20Longest%20Nice%20Substring
    // OJ: https://leetcode.com/problems/longest-nice-substring/
    // Author: github.com/lzl124631x
    // Time: O(N), the depth of the recursion is at most 26.
    // Space: O(N)
    // Solution 2. Divide and Conquer
    /*
        Time complexity
        The depth of the recursion is at most 26 levels, each of which we use a letter to split the windows.

        In each recursion, we traverse the string in O(N) time. Even though we take substring, each letter is 
        at most copied once, so overall each recursion is still O(N).

        So the overall time complexity is O(26N) = O(N).
    */
    string longestNiceSubstring(string s) {
        int state[26] = {};
        for (char c : s) {
            if (isupper(c)) state[c - 'A'] |= 2;
            else state[c - 'a'] |= 1;
        }
        int i = 0, N = s.size();
        while (i < N) {
            int j = i;
            while (j < N && state[tolower(s[j]) - 'a'] == 3) ++j; // find the window only contain characters that in state 3, i.e. having both upper and lower case
            int len = j - i;
            if (len == N) { // this string itself is nice, update the answer
                ans = s;
                break;
            }
            if (len > ans.size()) longestNiceSubstring(s.substr(i, len)); // handle this window recursively. The recursion is at most 26 levels.
            while (j < N && state[tolower(s[j]) - 'a'] != 3) ++j;
            i = j;
        } 
        return ans;
    }
};


class Solution97 {
public:
    // 2022.8.17, from https://github.com/wisdompeak/LeetCode/tree/master/Two_Pointers/1763.Longest-Nice-Substring
    /*
        本题和LC 395.Longest-Substring-with-At-Least-K-Repeating-Characters的风格非常类似。传统的双指针非常难做，
        无法设计能让左右指针都单向移动的策略。而二分搜值也没有单调性的依据（并不是滑窗长度越长越容易满足条件）。

        本题的滑窗法的关键设计，在于要保证“滑窗内不同字符的种类数目固定为k”。k是可以从1到26遍历一遍。当固定某个k时，我们一旦
        逐个遍历左指针i，相应地一定能找到一个最远的右指针j，使得[i:j]里面的字符种类是k，然后只需要检查这个滑窗里面每个字符是
        否都存在大小写两个版本即可。然后我们左指针i右移一位，那么右指针j也一定只需要相应地单调右移即可，以继续满足“字符种类恰
        为k”的要求。可以，我们用线性的时间就可以遍历所有这样的滑窗，找到其中最长的、且合法的滑窗即可。

        总的时间复杂度就是o(26N).
    */
    string longestNiceSubstring(string s) 
    {
        int retLen = -1, retStart = -1;
        for (int k=26; k>=1; k--)
        {
            auto [len, start] = helper(s, k);
            if (len > retLen)
            {
                retLen = len;
                retStart = start;
            } else if (len==retLen && start < retStart)
            {
                retStart = start;
            }                                
        }
        if (retLen!=-1)
            return s.substr(retStart, retLen);
        else
            return "";        
    }
    
    pair<int,int> helper(string&s, int k)
    {
        int j=0;
        unordered_map<char,int>Map1;
        unordered_map<char,int>Map2;
        int len = -1, start = -1;
                
        for (int i=0; i<s.size(); i++)
        {
            while (j<s.size() && (Map1.size()<k || Map1.size()==k && Map1.find(tolower(s[j]))!=Map1.end()))
            {
                Map1[tolower(s[j])]++;                
                Map2[s[j]]++; 
                j++;
            }
            if (Map1.size() < k) break;                
            
            int flag = 1;
            for (auto x: Map1)
            {
                if (Map2[tolower(x.first)]==0 || Map2[toupper(x.first)]==0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag==1)
            {
                if (j-i > len)
                {
                    len = j-i;
                    start = i;
                }                
            }       
            
            Map1[tolower(s[i])]--;
            if (Map1[tolower(s[i])]==0)
                Map1.erase(tolower(s[i]));
            Map2[s[i]]--;
                        
        }
        
        return {len, start};
    }
};


class Solution96 {
public:
    // 2022.8.17, from https://leetcode.cn/problems/longest-nice-substring/solution/zui-chang-de-mei-hao-zi-zi-fu-chuan-by-l-4l1t/
    // 作者：LeetCode-Solution
    // 链接：https://leetcode.cn/problems/longest-nice-substring/solution/zui-chang-de-mei-hao-zi-zi-fu-chuan-by-l-4l1t/
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        方法一：枚举
        思路

        题目要求找到最长的美好子字符串，题目中给定的字符串 ss 的长度 \textit{length}length 范围为 1 \le \textit{length} \le 1001≤length≤100。
        由于字符串的长度比较小，因此可以枚举所有可能的子字符串，然后检测该字符串是否为美好的字符串，并得到长度最长的美好字符串。

        题目关于美好字符串的定义为: 字符串中的每个字母的大写和小写形式同时出现在该字符串中。检测时，由于英文字母 \texttt{`a'}-\texttt{`z'}‘a’−‘z’ 
        最多只有 2626 个, 因此可以利用二进制位来进行标记，\textit{lower}lower 标记字符中出现过小写英文字母，\textit{upper}upper 标记字符中出现过
        大写英文字母。如果满足 \textit{lower} = \textit{upper}lower=upper ，我们则认为字符串中所有的字符都满足大小写形式同时出现，则认定该字符串
        为美好字符串。

        题目要求如果有多个答案，返回在字符串中最早出现的那个。此时，只需要首先检测从以字符串索引 00 为起始的子字符串。

        复杂度分析

        时间复杂度：O(n 2)，其中 nn 为字符串的长度。需要枚举所有可能的子字符串，因此需要双重循环遍历字符串，总共可能有 n^2
        个连续的子字符串。

        空间复杂度：O(1)。由于返回值不需要计算空间复杂度，除了需要两个整数变量用来标记以外不需要额外的空间。
    */
    string longestNiceSubstring(string s) {
        int n = s.size();
        int maxPos = 0;
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int lower = 0;
            int upper = 0;
            for (int j = i; j < n; ++j) {
                if (islower(s[j])) {
                    lower |= 1 << (s[j] - 'a');
                } else {
                    upper |= 1 << (s[j] - 'A');
                }
                if (lower == upper && j - i + 1 > maxLen) {
                    maxPos = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(maxPos, maxLen);
    }
};


class Solution95 {
public:
    // 2022.8.17, from https://leetcode.cn/problems/longest-nice-substring/solution/zui-chang-de-mei-hao-zi-zi-fu-chuan-by-l-4l1t/
    // 作者：LeetCode-Solution
    // 链接：https://leetcode.cn/problems/longest-nice-substring/solution/zui-chang-de-mei-hao-zi-zi-fu-chuan-by-l-4l1t/
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        方法二：分治
        思路

        分治思想来源于「395. 至少有K个重复字符的最长子串」，详细的解法与其相似。题目要求找到最长的美好子字符串，如果字符串本身即合法的美好字符串，
        此时最长的完美字符串即为字符串本身。由于字符串中含有部分字符 \textit{ch}ch 只出现大写或者小写形式，如果字符串包含这些字符 \textit{ch}
        ch 时，可以判定该字符串肯定不为完美字符串。一个字符串为美好字符串的必要条件是不包含这些非法字符。因此我们可以利用分治的思想，将字符串从这些
        非法的字符处切分成若干段，则满足要求的最长子串一定出现在某个被切分的段内，而不能跨越一个或多个段。

        递归时，\textit{maxPos}maxPos 用来记录最长完美字符串的起始索引，\textit{maxLen}maxLen 用来记录最长完美字符串的长度。

        每次检查区间 [\textit{start}, \textit{end}][start,end] 中的子字符串是否为完美字符串，如果当前的字符串为合法的完美字符串，则将当前区间
        的字符串的长度与 \textit{maxLen}maxLen 进行比较和替换；否则我们依次对当前字符串进行切分，然后递归检测切分后的字符串。

        复杂度分析

        时间复杂度：O(n \cdot |\Sigma|)O(n⋅∣Σ∣)，其中 nn 为字符串的长度，|\Sigma|∣Σ∣ 为字符集的大小，本题中字符串仅包含英文大小写字母，
        因此 |\Sigma| = 52∣Σ∣=52。本题使用了递归，由于字符集最多只有 \dfrac{|\Sigma|}{2} 2∣Σ∣
        ​
        个不同的英文字母，每次递归都会去掉一个英文字母的所有大小写形式，因此递归深度最多为 \dfrac{|\Sigma|}{2} 2∣Σ∣。

        空间复杂度：O(|\Sigma|)O(∣Σ∣)。由于递归深度最多为 |\Sigma|∣Σ∣，因此需要使用 O(|\Sigma|)O(∣Σ∣) 的递归栈空间。
    */
    void dfs(const string & s, int start, int end, int & maxPos, int & maxLen) {
        if (start >= end) {
            return;
        }
        int lower = 0, upper = 0;
        for (int i = start; i <= end; ++i) {
            if (islower(s[i])) {
                lower |= 1 << (s[i] - 'a');
            } else {
                upper |= 1 << (s[i] - 'A');
            }
        }
        if (lower == upper) {
            if (end - start + 1 > maxLen) {
                maxPos = start;
                maxLen = end - start + 1;
            }
            return;
        } 
        int valid = lower & upper;
        int pos = start;
        while (pos <= end) {
            start = pos;
            while (pos <= end && valid & (1 << (tolower(s[pos]) - 'a'))) {
                ++pos;
            }
            dfs(s, start, pos - 1, maxPos, maxLen);
            ++pos;
        }
    }

    string longestNiceSubstring(string s) {
        int maxPos = 0, maxLen = 0;
        dfs(s, 0, s.size() - 1, maxPos, maxLen);
        return s.substr(maxPos, maxLen);
    }
};


class Solution94 {
public:
    // 2022.8.17, from https://leetcode.cn/problems/longest-nice-substring/solution/zui-chang-de-mei-hao-zi-zi-fu-chuan-by-l-4l1t/
    // 作者：LeetCode-Solution
    // 链接：https://leetcode.cn/problems/longest-nice-substring/solution/zui-chang-de-mei-hao-zi-zi-fu-chuan-by-l-4l1t/
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        方法三：滑动窗口
        思路

        滑动窗口的解法同样参考「395. 至少有K个重复字符的最长子串」。
        我们枚举最长子串中的字符种类数目，它最小为 11，最大为 \dfrac{|\Sigma|}{2} 
        2
        ∣Σ∣
        ​
        ，其中同一个字符的大小写形式视为同一种字符。

        对于给定的字符种类数量 \textit{typeNum}typeNum，我们维护滑动窗口的左右边界 l,rl,r、滑动窗口内部大小字符出现的次数 \textit{upperCnt}, 
        \textit{lowerCnt}upperCnt,lowerCnt，以及滑动窗口内的字符种类数目 \textit{total}total。当 \textit{total} > \textit{typeNum}total>typeNum 
        时，我们不断地右移左边界 ll，并对应地更新 \textit{upperCnt}, \textit{lowerCnt}upperCnt,lowerCnt 以及 \textit{total}total，
        直到 \textit{total} \le \textit{typeNum}total≤typeNum 为止。这样，对于任何一个右边界 rr，我们都能找到最小的 ll（记为 l_{min}l min
        ​
        ，使得 s[l_{min}...r]s[l min...r] 之间的字符种类数目不多于 \textit{typeNum}typeNum。

        完美字符串定义为所有的字符同时出现大写和小写形式，最长的完美字符串一定出现在某个窗口中。对于任何一组 l_{min}, rl min,r 而言，我们需要判断当前 
        s[l_{min}...r]s[l min...r] 是否为完美字符串，检测方法如下：

        当前字符串中的字符种类数量为 \textit{typeNum}typeNum，当前字符串中同时出现大小写的字符的种类数量为 \textit{cnt}cnt，只有满足 
        \textit{cnt}cnt 等于 \textit{typeNum}typeNum 时，我们可以判定字符串为完美字符串。

        遍历 \textit{upperCnt}, \textit{lowerCnt}upperCnt,lowerCnt 两个数组，第 ii 个字符同时满足 \textit{upperCnt}[i] > 0, 
        \textit{lowerCnt}[i] > 0upperCnt[i]>0,lowerCnt[i]>0 时，则认为第 ii 个字符的大小写形式同时出现。

        根据上面的结论，当限定字符种类数目为 \textit{typeNum}typeNum 时，满足题意的最长子串，就一定出自某个 s[l_{min}...r]s[l 
        min
        ​
        ...r]。因此，在滑动窗口的维护过程中，就可以直接得到最长子串的大小。

        最后，还剩下一个细节：如何在滑动窗口的同时高效地维护 \textit{total}total 和 \textit{cnt}cnt。

        右移右边界 rr 时，假设 s[r]s[r] 对应的字符的索引为 \textit{idx}idx，当满足 \textit{upperCnt}[r] + \textit{lowerCnt}[r] 
        = 1upperCnt[r]+lowerCnt[r]=1 时，则我们认为此时新增了一种字符，将 \textit{total}total 加 11。

        右移右边界 rr 时，假设 s[r]s[r] 对应的字符的索引为 \textit{idx}idx，如果 s[r]s[r] 为小写字母，右移右边界后，当满足 
        \textit{lowerCnt}[idx] = 1lowerCnt[idx]=1 且 \textit{upperCnt}[idx] > 0upperCnt[idx]>0 时，则我们认为此时新增了一种大小写
        同时存在的字符，将 \textit{cnt}cnt 加 11；如果 s[r]s[r] 为大写字母，右移右边界后，当满足 \textit{upperCnt}[idx] = 1upperCnt[idx]=1 
        且 \textit{lowerCnt}[idx] > 0lowerCnt[idx]>0 时，则我们认为此时新增了一种大小写同时存在的字符，将 \textit{cnt}cnt 加 11。

        右移左边界 ll 时，假设 s[l]s[l] 对应的字符的索引为 \textit{idx}idx，当满足 \textit{upperCnt}[idx] + \textit{lowerCnt}[idx] = 
        1upperCnt[idx]+lowerCnt[idx]=1 时，右移左边界后则我们认为此时将减少一种字符，将 \textit{total}total 减 11。

        右移左边界 ll 时，假设 s[l]s[l] 对应的字符的索引为 \textit{idx}idx，如果 s[l]s[l] 为小写字母，右移左边界后，当满足 \textit{lowerCnt}[idx] 
        = 0lowerCnt[idx]=0 且 \textit{upperCnt}[idx] > 0upperCnt[idx]>0 时，则我们认为此时减少了一种大小写同时存在的字符，将 
        \textit{cnt}cnt 减 11；如果 s[l]s[l] 为大写字母，右移左边界后，当满足 \textit{upperCnt}[idx] = 0upperCnt[idx]=0 且 \textit{lowerCnt}[idx] 
        > 0lowerCnt[idx]>0 时，则我们认为此时减少了一种大小写同时存在的字符，将 \textit{cnt}cnt 减 11。

        复杂度分析

        时间复杂度：O(N \cdot |\Sigma|)O(N⋅∣Σ∣)，其中 NN 为字符串的长度，|\Sigma|∣Σ∣ 为字符集的大小，本题中字符集限定为大小写英文字母，
        |\Sigma| = 52∣Σ∣=52。我们需要遍历所有可能的字符种类数量，共 \dfrac{|\Sigma|}{2} 2∣Σ∣
        ​
        种可能性，内层循环中滑动窗口的复杂度为 O(2N)O(2N)，因此总的时间复杂度为 O(N \cdot |\Sigma|)O(N⋅∣Σ∣) 。

        空间复杂度：O(|\Sigma|)O(∣Σ∣)。需要 O(|\Sigma|)O(∣Σ∣) 存储所有大小写字母的计数。
    */
    string longestNiceSubstring(string s) {
        int maxPos = 0, maxLen = 0;
        auto check = [&](int typeNum) {
            vector<int> lowerCnt(26);
            vector<int> upperCnt(26);
            int cnt = 0;
            for (int l = 0, r = 0, total = 0; r < s.size(); ++r) {
                int idx = tolower(s[r]) - 'a';
                if (islower(s[r])) {
                    ++lowerCnt[idx];
                    if (lowerCnt[idx] == 1 && upperCnt[idx] > 0) {
                        ++cnt;
                    }
                } else {
                    ++upperCnt[idx];
                    if (upperCnt[idx] == 1 && lowerCnt[idx] > 0) {
                        ++cnt;
                    }
                }
                total += (lowerCnt[idx] + upperCnt[idx]) == 1 ? 1 : 0;

                while (total > typeNum) {
                    idx = tolower(s[l]) - 'a';
                    total -= (lowerCnt[idx] + upperCnt[idx]) == 1 ? 1 : 0;
                    if (islower(s[l])) {
                        --lowerCnt[idx];
                        if (lowerCnt[idx] == 0 && upperCnt[idx] > 0) {
                            --cnt;
                        }
                    } else {
                        --upperCnt[idx];
                        if (upperCnt[idx] == 0 && lowerCnt[idx] > 0) {
                            --cnt;
                        }
                    }
                    ++l;
                }
                if (cnt == typeNum && r - l + 1 > maxLen) {
                    maxPos = l;
                    maxLen = r - l + 1;
                }
            }
        };

        int mask = 0;
        for (char & ch : s) {
            mask |= 1 << (tolower(ch) - 'a');
        }
        int types = __builtin_popcount(mask);
        for (int i = 1; i <= types; ++i) {
            check(i);
        }
        return s.substr(maxPos, maxLen);
    }
};


class Solution93 {
public:
    // 2022.8.17, from https://leetcode.cn/problems/longest-nice-substring/solution/nbgao-1763-zui-chang-de-mei-hao-zi-zi-fu-gpiv/
    // 作者：nbgao
    // 链接：https://leetcode.cn/problems/longest-nice-substring/solution/nbgao-1763-zui-chang-de-mei-hao-zi-zi-fu-gpiv/
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    string longestNiceSubstring(string s) {
        int n = s.size(), len = 0; // len记录最长子串长度
        if(n <= 1)
            return "";
        string t = ""; // 记录最长子串
        for(int i=0;i<n;i++){
            int x=0, y=0; // x记录小写字母集合，y记录大写字母集合
            for(int j=i;j<n;j++){
                char c = s[j];
                if(islower(c))
                    x |= 1<<(c-'a');
                else
                    y |= 1<<(c-'A');
                if(x==y && len<(j-i+1)){ // 小写、大写字母集合相同，且子串长度大于最长长度，更新最长子串
                    len = j-i+1;
                    t = s.substr(i, len);
                }
            }
        }
        return t;
    }
};


class Solution92 {
public:
    // 2022.8.17, from https://leetcode.cn/problems/longest-nice-substring/solution/you-ya-yi-dian-de-n2-jie-fa-by-r4c12-2w2s/
    // 作者：life-and-donuts
    // 链接：https://leetcode.cn/problems/longest-nice-substring/solution/you-ya-yi-dian-de-n2-jie-fa-by-r4c12-2w2s/
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans;
        
        for (int i = 0; i < n; ++i) {
            int a = 0, b = 0;
            for (int j = i; j < n; ++j) {
                if ('a' <= s[j] && s[j] <= 'z') a |= 1 << (s[j] - 'a');
                else b |= 1 << (s[j] - 'A');
                if (a == b && j - i + 1 > ans.size()) {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    // 2022.8.17, from https://leetcode.cn/problems/longest-nice-substring/solution/you-ya-yi-dian-de-n2-jie-fa-by-r4c12-2w2s/
    // 作者：life-and-donuts
    // 链接：https://leetcode.cn/problems/longest-nice-substring/solution/you-ya-yi-dian-de-n2-jie-fa-by-r4c12-2w2s/
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    string longestNiceSubstring(string s) {
        function<string(int, int)> search = [&] (int beg, int end) -> string {
            if (beg >= end) {
                return "";
            }

            int a = 0, b = 0;

            for (int i = beg; i <= end; ++i) {
                if ('a' <= s[i] && s[i] <= 'z') {
                    a |= 1 << (s[i] - 'a');
                } else {
                    b |= 1 << (s[i] - 'A');
                }
            }

            int c = a & b;
            int split = -1;

            for (int i = beg; i <= end; ++i) {
                int id = 'a' <= s[i] && s[i] <= 'z' ? s[i] - 'a' : s[i] - 'A';
                if (((c >> id) & 1) == 0) {
                    split = i;
                    break;
                }
            }

            if (split == -1) {
                return s.substr(beg, end - beg + 1);
            }

            string left = search(beg, split - 1), right = search(split + 1, end);

            return left.size() >= right.size() ? left : right;
        };

        return search(0, s.size() - 1);
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

