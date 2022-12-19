/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

/*

https://leetcode.cn/problems/backspace-string-compare/

844. 比较含退格的字符串
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。
 

示例 1：

输入：s = "ab#c", t = "ad#c"
输出：true
解释：s 和 t 都会变成 "ac"。

示例 2：

输入：s = "ab##", t = "c#d#"
输出：true
解释：s 和 t 都会变成 ""。

示例 3：

输入：s = "a#c", t = "b"
输出：false
解释：s 会变成 "c"，但 t 仍然是 "b"。
 

提示：

1 <= s.length, t.length <= 200
s 和 t 只含有小写字母以及字符 '#'
 

进阶：

你可以用 O(n) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
通过次数162,073提交次数332,283

*/

// @lc code=start
class Solution100 {
public:
    // 2022.9.15, from https://www.acwing.com/activity/content/code/content/1208070/
    string get(string& s) {
        string res;
        for (auto c: s)
            if (c == '#') {
                if (res.size()) res.pop_back();
            } else {
                res += c;
            }
        return res;
    }

    bool backspaceCompare(string s, string t) {
        return get(s) == get(t);
    }
};


class Solution99 {
public:
    // 2022.9.15, from https://github.com/grandyang/leetcode/issues/844
    /*
        这道题给了我们两个字符串，里面可能会有井号符#，这个表示退格符，键盘上的退格键我们应该都很熟悉吧，当字打错了的时候，
        肯定要点退格键来删除的。当然也可以连续点好几下退格键，这样就可以连续删除了，在例子2和3中，也确实能看到连续的井号符。
        题目搞懂了之后，就开始解题吧，博主最先想的方法就是对S和T串分别处理完退格操作后再进行比较，那么就可以使用一个子函数
        来进行字符串的退格处理，在子函数中，我们新建一个结果 res 的空串，然后遍历输入字符串，当遇到退格符的时候，判断若结果 
        res 不为空，则将最后一个字母去掉；若遇到的是字母，则直接加入结果 res 中即可。这样S和T串同时处理完了之后，再进行
        比较即可，参见代码如下：

        解法一：
    */
    bool backspaceCompare(string S, string T) {
        return helper(S) == helper(T);      
    }
    string helper(string str) {
        string res = "";
        for (char c : str) {
            if (c == '#') {
                if (!res.empty()) res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};


class Solution98 {
public:
    // 2022.9.15, from https://github.com/grandyang/leetcode/issues/844
    /*
        我们也可以不使用单独的子函数，而是直接用 for 循环来处理S和T串，当然原理都是一样的，分别建立s和t的空串，然后进行退格操作，
        最后比较s和t串是否相等即可，参见代码如下：

        解法二：
    */
    bool backspaceCompare(string S, string T) {
        string s = "", t = "";
        for (char c : S) c == '#' ? s.size() > 0 ? s.pop_back() : void() : s.push_back(c);
        for (char c : T) c == '#' ? t.size() > 0 ? t.pop_back() : void() : t.push_back(c);
        return s == t;
    }
};


class Solution97 {
public:
    // 2022.9.15, from https://github.com/grandyang/leetcode/issues/844
    /*
        这道题的 follow up 让我们使用常数级的空间复杂度，就是说不能新建空的字符串来保存处理之后的结果，那么只能在遍历的过程中
        同时进行比较，只能使用双指针同时遍历S和T串了。我们采用从后往前遍历，因为退格是要删除前面的字符，所以倒序遍历要好一些。
        用变量i和j分别指向S和T串的最后一个字符的位置，然后还需要两个变量 cnt1 和 cnt2 来分别记录S和T串遍历过程中连续出现的井
        号的个数，因为在连续井号后，要连续删除前面的字母，如何知道当前的字母是否是需要删除，就要知道当前还没处理的退格符的个数。
        好，现在进行 while 循环，条件是i和j至少有一个要大于等于0，然后对S串进行另一个 while 循环，条件是当i大于等于0，且当前
        字符是井号，或者 cnt1 大于0，若当前字符是退格符，则 cnt1 自增1，否则 cnt1 自减1，然后i自减1，这样就相当于跳过了当前
        的字符，不用进行比较。对T串也是做同样的 while 循环处理。之后若i和j有一个小于0了，那么可以根据i和j是否相等的情况进行返
        回。否则再看若S和T串当前的字母不相等，则返回 false，因为当前位置的退格符已经处理完了，剩下的字母是需要比较相等的，若不
        相等就可以直接返回 false 了。最后当外层的 while 循环退出后，返回i和j是否相等，参见代码如下：

        解法三：
    */
    bool backspaceCompare(string S, string T) {
        int i = (int)S.size() - 1, j = (int)T.size() - 1, cnt1 = 0, cnt2 = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0 && (S[i] == '#' || cnt1 > 0)) S[i--] == '#' ? ++cnt1 : --cnt1;
            while (j >= 0 && (T[j] == '#' || cnt2 > 0)) T[j--] == '#' ? ++cnt2 : --cnt2;
            if (i < 0 || j < 0) return i == j;
            if (S[i--] != T[j--]) return false;
        }
        return i == j;
    }
};


class Solution96 {
public:
    // 2022.9.15, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/backspace-string-compare.cpp
    // Time:  O(m + n)
    // Space: O(1)
    bool backspaceCompare(string S, string T) {
        for (int i = S.length() - 1, j = T.length() - 1; i >= 0 || j >= 0; --i, --j) {
            if (findNextChar(S, &i) != findNextChar(T, &j)) {
                return false;
            }
        }
        return true;
    }

private:
    char findNextChar(const string& s, int *i) {
        int skip = 0;
        for (; *i >= 0; --(*i)) {
            if (s[*i] == '#') {
                ++skip;
            } else if (skip > 0) {
                --skip;
            } else {
                return s[*i];
            }
        }
        return '\0';
    }
};


class Solution95 {
    // 2022.9.15, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/844.%20Backspace%20String%20Compare
    // OJ: https://leetcode.com/problems/backspace-string-compare/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    /*
        Update the S and T to the results of applying backspaces, then compare the strings.
    */
    string normalize(string &s) {
        int len = 0;
        for (char c : s) {
            if (c == '#') len = max(len - 1, 0);
            else s[len++] = c;
        }
        s.resize(len);
        return s;
    }
public:
    bool backspaceCompare(string S, string T) {
        return normalize(S) == normalize(T);
    }
};


class Solution94 {
    // 2022.9.15, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/844.%20Backspace%20String%20Compare
    // OJ: https://leetcode.com/problems/backspace-string-compare/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // 2022.9.15, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/844.%20Backspace%20String%20Compare
    /*
        If it's not allowed to change the input string, we scan backward. back function is used to skip all characters 
        that are deleted using backspaces. After back, the indexes are pointing to characters that we need to compare.
    */
    void back(string &s, int &i) {
        if (i < 0 || s[i] != '#') return;
        int cnt = 0;
        for (; i >= 0 && (cnt || s[i] == '#'); --i) {
            if (s[i] == '#') ++cnt;
            else --cnt;
        }
    }
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1;
        while (i >= 0 || j >= 0) {
            back(S, i);
            back(T, j);
            if ((i >= 0 && j < 0) || (i < 0 && j >= 0)) return false;
            for (; i >= 0 && j >= 0 && S[i] != '#' && T[j] != '#'; --i, --j) {
                if (S[i] != T[j]) return false;
            } 
        }
        return true;
    }
};


class Solution93 {
public:
    // 2022.9.15, from https://walkccc.me/LeetCode/problems/0844/
    /*
        Approach 1: Stack
        Time: O(n)
        Space: O(n)
    */
    bool backspaceCompare(string S, string T) {
        return backspace(S) == backspace(T);
    }

private:
    string backspace(const string& s) {
        string stack;

        for (const char c : s)
        if (c != '#')
            stack.push_back(c);
        else if (!stack.empty())
            stack.pop_back();

        return stack;
    }
};


class Solution92 {
public:
    // 2022.9.15, from https://walkccc.me/LeetCode/problems/0844/
    /*
        Approach 2: Two Pointers
        Time: O(n)O(n)
        Space: O(1)O(1)
    */
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1;  // S's index
        int j = T.length() - 1;  // T's index

        while (true) {
        // delete chars of S if needed
        int back = 0;
        while (i >= 0 && (S[i] == '#' || back > 0)) {
            back += S[i] == '#' ? 1 : -1;
            --i;
        }
        // delete chars of T if needed
        back = 0;
        while (j >= 0 && (T[j] == '#' || back > 0)) {
            back += T[j] == '#' ? 1 : -1;
            --j;
        }
        if (i >= 0 && j >= 0 && S[i] == T[j]) {
            --i;
            --j;
        } else {
            break;
        }
        }

        return i == -1 && j == -1;
    }
};


class Solution91 {
public:
    // 2022.9.15, from https://github.com/wisdompeak/LeetCode/blob/master/String/844.Backspace-String-Compare/844.Backspace-String-Compare.cpp
    /*
        844.Backspace-String-Compare
        此题的考点是用o(n)时间和o(1)空间．这就提示我们做in-place的修改．

        我们可以尝试用双指针的方法，将有效的字符都移动到字符串的前面去。具体的做法是快指针j扫每个元素，如果遇到了正常的字符，则str[i]=str[j]，
        同时慢指针i自增1。如果遇到了退格键，那么将慢指针i退一个即可。最终i指针的位置就代表了这个字符串最终有多长。
    */
    bool backspaceCompare(string S, string T) 
    {
        int i = convert(S);
        int j = convert(T);
        return S.substr(0,i)==T.substr(0,j);
    }

    int convert(string& str)
    {
        int i=0;
        for (int j=0; j<str.size(); j++)
        {
            if (str[j]!='#')
            {
                str[i] = str[j];
                i++;
            }
            else
            {
                i = max(0, i-1);
            }                
        }
        return i;
        
    }
};


class Solution90 {
public:
    // 2022.9.15, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0844.%E6%AF%94%E8%BE%83%E5%90%AB%E9%80%80%E6%A0%BC%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2.md
    /*
        普通方法（使用栈的思路）
        这道题目一看就是要使用栈的节奏，这种匹配（消除）问题也是栈的擅长所在，跟着一起刷题的同学应该知道，在栈与队列：匹配问题都是栈的强项，
        我就已经提过了一次使用栈来做类似的事情了。

        那么本题，确实可以使用栈的思路，但是没有必要使用栈，因为最后比较的时候还要比较栈里的元素，有点麻烦。

        这里直接使用字符串string，来作为栈，末尾添加和弹出，string都有相应的接口，最后比较的时候，只要比较两个字符串就可以了，比比较栈里的
        元素方便一些。

        代码如下：
        时间复杂度:O(n + m)，n为S的长度，m为T的长度 ，也可以理解是O(n)的时间复杂度
        空间复杂度:O(n + m)
    */
    bool backspaceCompare(string S, string T) {
        string s; // 当栈来用
        string t; // 当栈来用
        for (int i = 0; i < S.size(); i++) {
            if (S[i] != '#') s += S[i];
            else if (!s.empty()) {
                s.pop_back();
            }
        }
        for (int i = 0; i < T.size(); i++) {
            if (T[i] != '#') t += T[i];
            else if (!t.empty()) {
                t.pop_back();
            }
        }
        if (s == t) return true; // 直接比较两个字符串是否相等，比用栈来比较方便多了
        return false;
    }
};


class Solution89 {
private:
    // 2022.9.15, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0844.%E6%AF%94%E8%BE%83%E5%90%AB%E9%80%80%E6%A0%BC%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2.md
    /*
        性能依然是：
        时间复杂度：O(n + m)
        空间复杂度：O(n + m)
    */
    string getString(const string& S) {
        string s;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] != '#') s += S[i];
            else if (!s.empty()) {
                s.pop_back();
            }
        }
        return s;
    }
public:
    bool backspaceCompare(string S, string T) {
        return getString(S) == getString(T);
    }
};


class Solution {
public:
    // 2022.9.15, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0844.%E6%AF%94%E8%BE%83%E5%90%AB%E9%80%80%E6%A0%BC%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2.md
    /*
        优化方法（从后向前双指针）
        当然还可以有使用 O(1) 的空间复杂度来解决该问题。

        同时从后向前遍历S和T（i初始为S末尾，j初始为T末尾），记录#的数量，模拟消除的操作，如果#用完了，就开始比较S[i]和S[j]。
        动画如下：

        如果S[i]和S[j]不相同返回false，如果有一个指针（i或者j）先走到的字符串头部位置，也返回false。

        代码如下：
    */
    bool backspaceCompare(string S, string T) {
        int sSkipNum = 0; // 记录S的#数量
        int tSkipNum = 0; // 记录T的#数量
        int i = S.size() - 1;
        int j = T.size() - 1;
        while (1) {
            while (i >= 0) { // 从后向前，消除S的#
                if (S[i] == '#') sSkipNum++;
                else {
                    if (sSkipNum > 0) sSkipNum--;
                    else break;
                }
                i--;
            }
            while (j >= 0) { // 从后向前，消除T的#
                if (T[j] == '#') tSkipNum++;
                else {
                    if (tSkipNum > 0) tSkipNum--;
                    else break;
                }
                j--;
            }
            // 后半部分#消除完了，接下来比较S[i] != T[j]
            if (i < 0 || j < 0) break; // S 或者T 遍历到头了
            if (S[i] != T[j]) return false;
            i--;j--;
        }
        // 说明S和T同时遍历完毕
        if (i == -1 && j == -1) return true;
        return false;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

