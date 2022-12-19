/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

/*

https://leetcode.cn/problems/repeated-substring-pattern/

459. 重复的子字符串
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

 
示例 1:

输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。

示例 2:

输入: s = "aba"
输出: false

示例 3:

输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 

提示：

1 <= s.length <= 104
s 由小写英文字母组成
通过次数127,491提交次数250,299

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.md
    /*
        这又是一道标准的KMP的题目。

        如果KMP还不够了解，可以看我的B站：

        帮你把KMP算法学个通透！（理论篇）
        帮你把KMP算法学个通透！（求next数组代码篇）
        我们在字符串：KMP算法精讲里提到了，在一个串中查找是否出现过另一个串，这是KMP的看家本领。

        那么寻找重复子串怎么也涉及到KMP算法了呢？

        这里就要说一说next数组了，next 数组记录的就是最长相同前后缀( 字符串：KMP算法精讲 这里介绍了什么是前缀，什么是后缀，
        什么又是最长相同前后缀)， 如果 next[len - 1] != -1，
        则说明字符串有最长相同的前后缀（就是字符串里的前缀子串和后缀子串相同的最长长度）。

        最长相等前后缀的长度为：next[len - 1] + 1。(这里的next数组是以统一减一的方式计算的，因此需要+1)
        数组长度为：len。

        如果len % (len - (next[len - 1] + 1)) == 0 ，则说明数组的长度正好可以被 (数组长度-最长相等前后缀的长度) 整除 ，
        说明该字符串有重复的子字符串。

        数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组
        就是这个周期的循环。强烈建议大家把next数组打印出来，看看next数组里的规律，有助于理解KMP算法

        如图：

        459.重复的子字符串_1

        next[len - 1] = 7，next[len - 1] + 1 = 8，8就是此时字符串asdfasdfasdf的最长相同前后缀的长度。
        (len - (next[len - 1] + 1)) 也就是： 12(字符串的长度) - 8(最长公共前后缀的长度) = 4， 12 正好可以被 4 整除，
        所以说明有重复的子字符串（asdf）。C++代码如下：（这里使用了前缀表统一减一的实现方式）

        拓展
        在字符串：KMP算法精讲中讲解KMP算法的基础理论，给出next数组究竟是如何来了，前缀表又是怎么回事，为什么要选择前缀表。

        讲解一道KMP的经典题目，力扣：28. 实现 strStr()，判断文本串里是否出现过模式串，这里涉及到构造next数组的代码实现，
        以及使用next数组完成模式串与文本串的匹配过程。

        后来很多同学反馈说：搞不懂前后缀，什么又是最长相同前后缀（最长公共前后缀我认为这个用词不准确），以及为什么前缀表要统一
        减一（右移）呢，不减一行不行？针对这些问题，我在字符串：KMP算法精讲给出了详细的讲解。
    */
    // 这里使用了前缀表统一减一的实现方式
    void getNext (int* next, const string& s){
        next[0] = -1;
        int j = -1;
        for(int i = 1;i < s.size(); i++){
            while(j >= 0 && s[i] != s[j+1]) {
                j = next[j];
            }
            if(s[i] == s[j+1]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern (string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0) {
            return true;
        }
        return false;
    }
};


class Solution99 {
public:
    // 前缀表（不减一）的C++代码实现
    void getNext (int* next, const string& s){
        next[0] = 0;
        int j = 0;
        for(int i = 1;i < s.size(); i++){
            while(j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if(s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern (string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - (next[len - 1] )) == 0) {
            return true;
        }
        return false;
    }
};


class Solution98 {
public:
    // 2022.7.23, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/459.%20Repeated%20Substring%20Pattern
    // Solution 1. Brute force
    bool repeatedSubstringPattern(string s) {
        int N = s.size();
        for (int len = 1; len <= N / 2; ++len) {
            if (N % len) continue;
            int i = len;
            for (; i < N; ++i) {
                if (s[i] != s[i % len]) break;
            }
            if (i == N) return true;
        }
        return false;
    }
};


class Solution97 {
public:
    // 2022.7.23, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/459.%20Repeated%20Substring%20Pattern
    // Solution 2. Brute force with string_view
    bool repeatedSubstringPattern(string s) {
        string_view p = s, sv = s;
        for (int len = s.size() / 2; len >= 1; --len) {
            if (s.size() % len) continue;
            p = p.substr(0, len);
            int i = s.size() / len - 1;
            for (; i >= 0 && p == sv.substr(i * len, len); --i);
            if (i < 0) return true;
        }
        return false;
    }
};


class Solution96 {
public:
    // 2022.7.23, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/459.%20Repeated%20Substring%20Pattern
    // Solution 3. KMP
    bool repeatedSubstringPattern(string s) {
        int N = s.size(), j = -1;
        vector<int> lps(N + 1, -1);
        for (int i = 1; i <= N; ++i) {
            while (j >= 0 && s[i - 1] != s[j]) j = lps[j];
            lps[i] = ++j;
        }
        return lps[N] && (lps[N] % (N - lps[N])) == 0;
    }
};


class Solution95 {
public:
    // 2022.7.23, from https://walkccc.me/LeetCode/problems/0459/
    bool repeatedSubstringPattern(string s) {
        const string ss = s + s;
        return ss.substr(1, ss.length() - 2).find(s) != string::npos;
    }
};


class Solution94 {
public:
    // 2022.7.23, from https://www.guozet.me/leetcode/Leetcode-459-Repeated-Substring-Pattern.html?h=repeated
    // 给定一个字符串，问其是否有n个重复的子串组成。如果字符串的长度是len，那么我们在0-n/2之间进行判断，是否是字符串。
    // 如果子字符串的长度不能被len整除，那么这肯定不是可以重复N次组建成给定字符串的子字符串
    // 如果能够被字符串长度len整除，那么就使用整除得到的数值n，进行n次子字符串重复，重复完成之后，判断是否和输入的字符串相等， 
    // 如果相等，那就返回true，如果不相等，那就是false
    bool repeatedSubstringPattern(string s) {
      int len = s.size();
      for(int i = 0; i < len/2; ++i) {
        if(len % (i+1) == 0) {
          int count = len / (i+1);
          string res = "";
          for(int j = 0; j < count; ++j) {
            res += s.substr(0, i+1);
          }
          if(res == s) return true;
        }
      }
      return false;
    }
};


class Solution93 {
public:
    // 2022.7.23, from https://github.com/MaskRay/LeetCode/blob/master/repeated-substring-pattern.cc
    bool repeatedSubstringPattern(string str) {
        vector<int> pi(str.size());
        for (int j = 0, i = 1; i < str.size(); i++) {
        while (j && str[i] != str[j]) j = pi[j-1];
        if (str[i] == str[j]) j++;
        pi[i] = j;
        }
        return pi.back() && str.size()%(str.size()-pi.back()) == 0;
    }
};


class Solution92 {
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/repeated-substring-pattern.cpp
    // Time:  O(n)
    // Space: O(n)
private:
    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }

public:
    bool repeatedSubstringPattern(string str) {
        vector<int> prefix = getPrefix(str);
        return prefix.back() != -1 &&
               (prefix.back() + 1) % (str.length() - prefix.back() - 1) == 0;
    }
};


class Solution91 {
public:
    // 2022.7.23, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/555694/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<int> next(n + 1);
        for (int i = 2, j = 0; i <= n; i ++ ) {
            while (j && s[i] != s[j + 1]) j = next[j];
            if (s[i] == s[j + 1]) j ++ ;
            next[i] = j;
        }
        int t = n - next[n];
        return t < n && n % t == 0;
    }
};


class Solution90 {
public:
    // 2022.7.26, from https://walkccc.me/LeetCode/problems/0459/
    // Time: O(n^2), where n = |\texttt{s}|n=∣s∣
    // Space: O(n)O(n)
    bool repeatedSubstringPattern(string s) {
        const string ss = s + s;
        return ss.substr(1, ss.length() - 2).find(s) != string::npos;
    }
};


class Solution89 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/459
    /*
        这道题给了我们一个字符串，问其是否能拆成n个重复的子串。那么既然能拆分成多个子串，那么每个子串的长度肯定
        不能大于原字符串长度的一半，那么我们可以从原字符串长度的一半遍历到1，如果当前长度能被总长度整除，说明可
        以分成若干个子字符串，我们将这些子字符串拼接起来看跟原字符串是否相等。 如果拆完了都不相等，返回false。

        解法一：
    */
    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        for (int i = n / 2; i >= 1; --i) {
            if (n % i == 0) {
                int c = n / i;
                string t = "";
                for (int j = 0; j < c; ++j) {
                    t += str.substr(0, i); 
                }
                if (t == str) return true;
            }
        }
        return false;
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/459
    /*
        下面这种方法是参考的网上的这个帖子，原作者说是用的KMP算法，LeetCode之前也有一道应用KMP算法来解的题
        Shortest Palindrome，但是感觉那道题才是KMP算法。这道题也称为KMP算法感觉怪怪的(关于KMP的详细介绍
        请参见从头到尾彻底理解KMP，也可以看博主自己写的一篇KMP Algorithm 字符串匹配算法KMP小结)，KMP算法中
        的next数组是找当前位置的最大相同前缀后缀的个数，而这道题维护的一位数组dp[i]表示，到位置i-1为止的重复
        字符串的字符个数，不包括被重复的那个字符串，什么意思呢，我们举个例子，比如"abcabc"的dp数组为[0 0 0 0 1 2 3]，
        dp数组长度要比原字符串长度多一个。那么我们看最后一个位置数字为3，就表示重复的字符串的字符数有3个。
        如果是"abcabcabc"，那么dp数组为[0 0 0 0 1 2 3 4 5 6]，我们发现最后一个数字为6，那么表示重复的字符
        串为“abcabc”，有6个字符。那么怎么通过最后一个数字来知道原字符串是否由重复的子字符串组成的呢，首先当然
        是最后一个数字不能为0，而且还要满足dp[n] % (n - dp[n]) == 0才行，因为n - dp[n]是一个子字符串的长度，
        那么重复字符串的长度和肯定是一个子字符串的整数倍，参见代码如下：

        解法二：
    */
    bool repeatedSubstringPattern(string str) {
        int i = 1, j = 0, n = str.size();
        vector<int> dp(n + 1, 0);
        while (i < n) {
            if (str[i] == str[j]) dp[++i] = ++j;
            else if (j == 0) ++i;
            else j = dp[j];
        }
        return dp[n] && (dp[n] % (n - dp[n]) == 0);
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

