/*

https://leetcode.cn/problems/minimum-window-subsequence/

727. 最小窗口子序列

困难
144
company
谷歌 Google

给定字符串 S and T，找出 S 中最短的（连续）子串 W ，使得 T 是 W 的 子序列 。

如果 S 中没有窗口可以包含 T 中的所有字符，返回空字符串 ""。如果有不止一个最短长度的窗口，返回开始位置最靠左的那个。

示例 1：

输入：
S = "abcdebdde", T = "bde"
输出："bcde"
解释：
"bcde" 是答案，因为它在相同长度的字符串 "bdde" 出现之前。
"deb" 不是一个更短的答案，因为在窗口中必须按顺序出现 T 中的元素。 

注：

所有输入的字符串都只包含小写字母。All the strings in the input will only contain lowercase letters.
S 长度的范围为 [1, 20000]。
T 长度的范围为 [1, 100]。
 
*/

class Solution100 {
public:
    // 2023.2.11, from https://github.com/grandyang/leetcode/issues/727
    /*
        这道题给了我们两个字符串S和T，让我们找出S的一个长度最短子串W，使得T是W的子序列，如果长度相同，取起始位置靠前的。
        清楚子串和子序列的区别，那么题意就不难理解，题目中给的例子也很好的解释了题意。我们经过研究可以发现，返回的子串的
        起始字母和T的起始字母一定相同，这样才能保证最短。那么你肯定会想先试试暴力搜索吧，以S中每个T的起始字母为起点，均开
        始搜索字符串T，然后维护一个子串长度的最小值。如果是这种思路，那么还是趁早打消念头吧，博主已经替你试过了，OJ 不依
        。原因也不难想，假如S中有大量的连续b，并且如果T也很长的话，这种算法实在是不高效啊。根据博主多年经验，这种玩字符串
        且还是 Hard 的题，十有八九都是要用动态规划 Dynamic Programming 来做的，那么就直接往 DP 上去想吧。DP 的第一步就
        是设计 dp 数组，像这种两个字符串的题，一般都是一个二维数组，想想该怎么定义。确定一个子串的两个关键要素是起始位置
        和长度，那么我们的 dp 值到底应该是定起始位置还是长度呢？That is a question! 仔细想一想，其实起始位置是长度的基础
        ，因为我们一旦知道了起始位置，那么当前位置减去起始位置，就是长度了，所以我们 dp 值定为起始位置。那么 dp[i][j] 
        表示范围S中前i个字符包含范围T中前j个字符的子串的起始位置，注意这里的包含是子序列包含关系。然后就是确定长度了，有
        时候会使用字符串的原长度，有时候会多加1，看个人习惯吧，这里博主长度多加了个1。

        OK，下面就是重中之重啦，求状态转移方程。一般来说，dp[i][j] 的值是依赖于之前已经求出的dp值的，在递归形式的解法中，
        dp数组也可以看作是记忆数组，从而省去了大量的重复计算，这也是 dp 解法凌驾于暴力搜索之上的主要原因。牛B的方法总是
        最难想出来的，dp 的状态转移方程就是其中之一。在脑子一片浆糊的情况下，博主的建议是从最简单的例子开始分析，比如 
        S = "b", T = "b", 那么我们就有 dp[1][1] = 0，因为S中的起始位置为0，长度为1的子串可以包含T。如果当 S = "d", 
        T = "b"，那么我们有 dp[1][1] = -1，因为我们的dp数组初始化均为 -1，表示未匹配或者无法匹配。下面来看一个稍稍复杂些
        的例子，S = "dbd", T = "bd"，我们的dp数组是：

        ∅  b  d
        ∅  ?  ?  ?
        d  ? -1 -1
        b  ?  1 -1
        d  ?  1  1

        这里的问号是边界，我们还不知道如何初给边界赋值，我们看到，为 -1 的地方是对应的字母不相等的地方。我们首先要明确的是 
        dp[i][j] 中的j不能大于i，因为T的长度不能大于S的长度，所以j大于i的 dp[i][j] 一定都是-1的。再来看为1的几个位置，
        首先是 dp[2][1] = 1，这里表示db包含b的子串起始位置为1，make sense！然后是 dp[3][1] = 1，这里表示 dbd 包含b的子串
        起始位置为1，没错！然后是 dp[3][2] = 1，这里表示 dbd 包含 bd 的起始位置为1，all right! 那么我们可以观察出，
        当 S[i] == T[j] 的时候，实际上起始位置和 dp[i - 1][j - 1] 是一样的，比如 dbd 包含 bd 的起始位置和 db 包含b的起始
        位置一样，所以可以继承过来。那么当 S[i] != T[j] 的时候，怎么搞？其实是和 dp[i - 1][j] 是一样的，比如 dbd 包含b的
        起始位置和 db 包含b的起始位置是一样的。

        嗯，这就是状态转移方程的核心了，下面再来看边界怎么赋值，由于j比如小于等于i，所以第一行的第二个位置往后一定都是-1，
        我们只需要给第一列赋值即可。通过前面的分析，我们知道了当 S[i] == T[j] 时，我们取的是左上角的 dp 值，表示当前字母在
        S中的位置，由于我们dp数组提前加过1，所以第一列的数只要赋值为当前行数即可。最终的 dp 数组如下：

        ∅  b  d
        ∅  0 -1 -1
        d  1 -1 -1
        b  2  1 -1
        d  3  1  1

        为了使代码更加简洁，我们在遍历完每一行，检测如果 dp[i][n] 不为-1，说明T已经被完全包含了，且当前的位置跟起始位置都知道了
        ，我们计算出长度来更新一个全局最小值 minLen，同时更新最小值对应的起始位置 start，最后取出这个全局最短子串，如果没有找到
        返回空串即可，参见代码如下：

        解法一：                
    */
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size(), start = -1, minLen = INT_MAX;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= min(i, n); ++j) {
                dp[i][j] = (S[i - 1] == T[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j];
            }
            if (dp[i][n] != -1) {
                int len = i - dp[i][n];
                if (minLen > len) {
                    minLen = len;
                    start = dp[i][n];
                }
            }
        }
        return (start != -1) ? S.substr(start, minLen) : "";
    }
};


class Solution99 {
public:
    // 2023.2.11, from https://github.com/grandyang/leetcode/issues/727
    /*
        论坛上的 danzhutest大神 提出了一种双指针的解法，其实这是优化过的暴力搜索的方法，而且居然 beat 了 100%，给跪了好嘛？！
        而且这双指针的跳跃方式犹如舞蹈般美妙绝伦，比那粗鄙的暴力搜索双指针不知道高到哪里去了？！举个栗子来说吧，比如当 S = "bbbbdde", 
        T = "bde" 时，我们知道暴力搜索的双指针在S和T的第一个b匹配上之后，就开始检测S之后的字符能否包含T之后的所有字符，当匹配
        结束后，S的指针就会跳到第二个b开始匹配，由于有大量的重复b出现，所以每一个b都要遍历一遍，会达到平方级的复杂度，会被 OJ 
        无情拒绝。而下面这种修改后的算法会跳过所有重复的b，使得效率大大提升，具体是这么做的，当第一次匹配成功后，我们的双指针往
        前走，找到那个刚好包含T中字符的位置，比如开始指针 i = 0 时，指向S中的第一个b，指针 j = 0 时指向T中的第一个b，然后开始
        匹配T，当 i = 6， j = 2 时，此时完全包含了T。暴力搜索解法中此时i会回到1继续找，而这里，我们通过向前再次匹配T，会在 
        i = 3，j = 0 处停下，然后继续向后找，这样S中重复的b就会被跳过，从而大大的提高了效率，但是最坏情况下的时间复杂度还是 O(mn)。
        旋转，跳跃，我闭着眼，尘嚣看不见，你沉醉了没？博主已经沉醉在这双指针之舞中了......    
    */
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size(), start = -1, minLen = INT_MAX, i = 0, j = 0;
        while (i < m) {
            if (S[i] == T[j]) {
                if (++j == n) {
                    int end = i + 1;
                    while (--j >= 0) {
                        while (S[i--] != T[j]);
                    }
                    ++i; ++j;
                    if (end - i < minLen) {
                        minLen = end - i;
                        start = i;
                    }
                }
            }
            ++i;
        }
        return (start != -1) ? S.substr(start, minLen) : "";
    }
};


class Solution98 {
public:
    // 2023.2.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/minimum-window-subsequence.cpp
    // Time:  O(s * t)
    // Space: O(s)
    string minWindow(string S, string T) {
        vector<vector<int>> lookup(S.size() + 1, vector<int>(26, -1));
        vector<int> find_char_next_pos(26, -1);
        for (int i = S.length() - 1; i >= 0; --i) {
            find_char_next_pos[S[i] - 'a'] = i + 1;
            lookup[i] = find_char_next_pos;
        }
        
        int min_i = -1, min_len = numeric_limits<int>::max();
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] != T[0]) {
                continue;
            }
            int start = i;
            for (const auto& c : T) {
                start = lookup[start][c - 'a'];
                if (start == -1) {
                    break;
                }
            }
            if (start != -1) {
               if (start - i < min_len) {
                   min_i = i;
                   min_len = start - i;
               }
            }
        }
        return min_i != -1 ? S.substr(min_i, min_len) : "";
    }
};


class Solution97 {
public:
    // 2023.2.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/minimum-window-subsequence.cpp
    // Time:  O(s * t)
    // Space: O(s)
    string minWindow(string S, string T) {
        vector<vector<int>> dp(2, vector<int>(S.length(), -1));
        for (int j = 0; j < S.length(); ++j) {
            if (S[j] == T[0]) {
                dp[0][j] = j;
            }
        }
                
        for (int i = 1; i < T.length(); ++i) {
            int prev = -1;
            dp[i % 2] = vector<int>(S.length(), -1);
            for (int j = 0; j < S.length(); ++j) {
                if (prev != -1 && S[j] == T[i]) {
                    dp[i % 2][j] = prev;
                }
                if (dp[(i - 1) % 2][j] != -1) {
                    prev = dp[(i - 1) % 2][j];
                }
            }
        }

        int start = 0, end = S.length();
        for (int j = 0; j < S.length(); ++j) {
            int i = dp[(T.length() - 1) % 2][j];
            if (i >= 0 && j - i < end - start) {
                tie(start, end) = make_pair(i, j);
            }
        }
        return end < S.length() ? S.substr(start, end - start + 1) : "";
    }
};


class Solution96 {
public:
    // 2023.2.11, from https://walkccc.me/LeetCode/problems/0727/
    string minWindow(string S, string T) {
        const int m = T.length();
        const int n = S.length();
        // dp[i][j] := start index (1-indexed) of
        // The minimum window of T[0..i] and S[0..j)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // Fill in placeholder values
        for (int j = 0; j <= n; ++j)
        dp[0][j] = j + 1;

        for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (T[i - 1] == S[j - 1])
            dp[i][j] = dp[i - 1][j - 1];
            else
            dp[i][j] = dp[i][j - 1];

        int bestLeft = 0;
        int minLength = INT_MAX;

        for (int j = 1; j <= n; ++j)
        if (dp[m][j] > 0 && j - dp[m][j] + 1 < minLength) {
            bestLeft = dp[m][j] - 1;
            minLength = j - dp[m][j] + 1;
        }

        return minLength == INT_MAX ? "" : S.substr(bestLeft, minLength);
    }
};


class Solution95 {
public:
    // 2023.2.11, from https://github.com/wisdompeak/LeetCode/blob/master/Greedy/727.Minimum-Window-Subsequence/727.Minimum-Window-Subsequence_v1.cpp
    /*
        解法1：双序列DP

        对于双字符串的题目，双序列DP是一个非常自然的思路。根据双序列DP的套路，我们定义dp[i][j]表示，截止到S[i]的最短的substring
        长度，使得T[1:j]是这个substring的subsequence。注意，这个substring一定要包括S[i]本身。也就是说，如果这个dp的值是k，那么
        要求T[1:j]是S[i-k+1:i]的一个subsequence。

        最终的答案是 min {dp[i][N]} (i=1,2,...M)。

        根据双序列DP的套路，转移方程的入手点就是观察S[i]和T[j]的关系。

        for (int i=1; i<=M; i++)
        for (int j=1; j<=N; j++)
        {
            if (S[i]==T[j])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=dp[i-1][j]+1; //说明S[i]对于构建T[1:j]没有帮助，T[1:j]得从dp[i][j-1]里面找
        }

        然后我们考虑边界条件。易知 dp[0][j] (i=0, j=1,2,...N) 都是需要定义的边界条件。长度为0的S子串肯定不会是T的supersequence。
        故这些初始值应该是INT_MAX.

        其次可以看出 dp[i][0] (i=0,1,2,...,M)也是需要提前设置初始值。显然，长度为0的T子串是任何长度为0的S子串的subsequence，故初始
        值是0.

        最后在所有dp[i][N]中找到第一个最小值k，那么 S.substr(i-k+1,k)就是答案。

        显然时间复杂度是o(MN).    
    */
    string minWindow(string S, string T) 
    {
        int m = S.size();
        int n = T.size();
        S = "#"+S;
        T = "#"+T;
        auto dp = vector<vector<int>>(m+1,vector<int>(n+1,0));
        
        for (int j=1; j<=n; j++)
            dp[0][j] = INT_MAX/2;
        for (int i=0; i<=m; i++)
            dp[i][0] = 0;
        
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
            {
                if (S[i]==T[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = dp[i-1][j]+1;
            }
        
        int len  = INT_MAX/2;
        int pos;
        for (int i=1; i<=m; i++)
        {
            if (dp[i][n] < len)
            {
                len = dp[i][n];
                pos = i;
            }
        }
        
        if (len>=INT_MAX/2)
            return "";
        else
            return S.substr(pos-len+1,len);
        
    }
};


class Solution94 {
public:
    // 2023.2.11, from https://github.com/wisdompeak/LeetCode/blob/master/Greedy/727.Minimum-Window-Subsequence/727.Minimum-Window-Subsequence_v2.cpp
    /*
        解法2：状态机
        其实只要确定T[0]在S中的位置（比如说是start），那么T在S里的superstring就可以唯一地用贪心法确定。简单的方法就是双指针：
        S的指针指向start，T的指针指向0，S的指针一直向右遍历，试图去匹配T里面的每一个字符。如果T能够扫描完每一个字符，那么S指针
        的位置就是这个superstring的结尾。这样的做法复杂度是(M+N)*K，其中K是T[0]在S中出现的次数。

        也可以利用类似LC 792的状态机的做法。提前对S预处理得到next[i][ch]，表示在S串的i位置上向右看，第一个出现ch的位置。这样
        我们就可以用o(1)时间实现S指针的跳转。这样的做法时间复杂度是N*K.    
    */
    string minWindow(string s1, string s2) 
    {
        int m = s1.size();
        int next[m+1][26];
        s1 = "#" + s1;
        
        for (int ch=0; ch<26; ch++)
            next[m][ch] = -1;
        for (int i=m-1; i>=0; i--)
        {
            for (int ch=0; ch<26; ch++)
                next[i][ch] = next[i+1][ch];
            next[i][s1[i+1]-'a'] = i+1;
        }
        
        vector<int>start;
        for (int i=1; i<=m; i++)
        {
            if (s1[i]==s2[0])
                start.push_back(i);
        }
        
        string ret = "";
        for (int i: start)
        {
            int j = i-1;
            int flag = 1;
            for (auto ch: s2)
            {
                j = next[j][ch-'a'];
                if (j==-1)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                int len = j-i+1;
                if (ret == "" || len < ret.size())
                {
                    ret = s1.substr(i, len);
                }
            }        
        }
        
        return ret;
    }
};

