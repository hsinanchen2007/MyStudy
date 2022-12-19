/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

/*

https://leetcode.cn/problems/substring-with-concatenation-of-all-words/

30. 串联所有单词的子串
给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。
 

示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。

示例 2：

输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]

示例 3：

输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
 

提示：

1 <= s.length <= 104
s 由小写英文字母组成
1 <= words.length <= 5000
1 <= words[i].length <= 30
words[i] 由小写英文字母组成
通过次数137,313提交次数348,701

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.27, from https://www.acwing.com/activity/content/code/content/347952/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/347952/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        int n = s.size(), m = words.size(), w = words[0].size();
        unordered_map<string, int> tot;
        for (auto& word : words) tot[word] ++ ;

        for (int i = 0; i < w; i ++ ) {
            unordered_map<string, int> wd;
            int cnt = 0;
            for (int j = i; j + w <= n; j += w) {
                if (j >= i + m * w) {
                    auto word = s.substr(j - m * w, w);
                    wd[word] -- ;
                    if (wd[word] < tot[word]) cnt -- ;
                }
                auto word = s.substr(j, w);
                wd[word] ++ ;
                if (wd[word] <= tot[word]) cnt ++ ;
                if (cnt == m) res.push_back(j - (m - 1) * w);
            }
        }

        return res;
    }
};


class Solution99 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/30
    /*
        这道题让我们求串联所有单词的子串，就是说给定一个长字符串，再给定几个长度相同的单词，让找出串联给定所有单词
        的子串的起始位置，还是蛮有难度的一道题。假设 words 数组中有n个单词，每个单词的长度均为 len，那么实际上这
        道题就让我们出所有长度为 nxlen 的子串，使得其刚好是由 words 数组中的所有单词组成。那么就需要经常判断s串
        中长度为 len 的子串是否是 words 中的单词，为了快速的判断，可以使用 HashMap，同时由于 words 数组可能有
        重复单词，就要用 HashMap 来建立所有的单词和其出现次数之间的映射，即统计每个单词出现的次数。

        遍历s中所有长度为 nxlen 的子串，当剩余子串的长度小于 nxlen 时，就不用再判断了。所以i从0开始，到 (int)s.size() 
        - nxlen 结束就可以了，注意这里一定要将 s.size() 先转为整型数，再进行解法。一定要形成这样的习惯，一旦 
        size() 后面要减去数字时，先转为 int 型，因为 size() 的返回值是无符号型，一旦减去一个比自己大的数字，则
        会出错。对于每个遍历到的长度为 nxlen 的子串，需要验证其是否刚好由 words 中所有的单词构成，检查方法就是每次
        取长度为 len 的子串，看其是否是 words 中的单词。为了方便比较，建立另一个 HashMap，当取出的单词不在 words 
        中，直接 break 掉，否则就将其在新的 HashMap 中的映射值加1，还要检测若其映射值超过原 HashMap 中的映射值，
        也 break 掉，因为就算当前单词在 words 中，但若其出现的次数超过 words 中的次数，还是不合题意的。在 for 
        循环外面，若j正好等于n，说明检测的n个长度为 len 的子串都是 words 中的单词，并且刚好构成了 words，则将
        当前位置i加入结果 res 即可，具体参见代码如下：

        解法一：
    */
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        vector<int> res;
        int n = words.size(), len = words[0].size();
        unordered_map<string, int> wordCnt;
        for (auto &word : words) ++wordCnt[word];
        for (int i = 0; i <= (int)s.size() - n * len; ++i) {
            unordered_map<string, int> strCnt;
            int j = 0; 
            for (j = 0; j < n; ++j) {
                string t = s.substr(i + j * len, len);
                if (!wordCnt.count(t)) break;
                ++strCnt[t];
                if (strCnt[t] > wordCnt[t]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};


class Solution98 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/30
    /*
        这道题还有一种 O(n) 时间复杂度的解法，设计思路非常巧妙，但是感觉很难想出来，博主目测还未到达这种水平。这种方法
        不再是一个字符一个字符的遍历，而是一个词一个词的遍历，比如根据题目中的例子，字符串s的长度n为 18，words 数组中
        有两个单词 (cnt=2)，每个单词的长度 len 均为3，那么遍历的顺序为 0，3，6，8，12，15，然后偏移一个字符 1，4，
        7，9，13，16，然后再偏移一个字符 2，5，8，10，14，17，这样就可以把所有情况都遍历到，还是先用一个 HashMap m1 
        来记录 words 里的所有词，然后从0开始遍历，用 left 来记录左边界的位置，count 表示当前已经匹配的单词的个数。然后
        一个单词一个单词的遍历，如果当前遍历的到的单词t在 m1 中存在，那么将其加入另一个 HashMap m2 中，如果在 m2 中
        个数小于等于 m1 中的个数，那么 count 自增1，如果大于了，则需要做一些处理，比如下面这种情况：s = barfoofoo, 
        words = {bar, foo, abc}，给 words 中新加了一个 abc ，目的是为了遍历到 barfoo 不会停止，当遍历到第二 foo 
        的时候,  m2[foo]=2, 而此时 m1[foo]=1，这时候已经不连续了，所以要移动左边界 left 的位置，先把第一个词 t1=bar 
        取出来，然后将 m2[t1] 自减1，如果此时 m2[t1]<m1[t1] 了，说明一个匹配没了，那么对应的 count 也要自减1，然后
        左边界加上个 len，这样就可以了。如果某个时刻 count 和 cnt 相等了，说明成功匹配了一个位置，将当前左边界 left 
        存入结果 res 中，此时去掉最左边的一个词，同时 count 自减1，左边界右移 len，继续匹配。如果匹配到一个不在 m1 
        中的词，说明跟前面已经断开了，重置 m2，count 为0，左边界 left 移到 j+len，参见代码如下：

        解法二：
    */
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        vector<int> res;
        int n = s.size(), cnt = words.size(), len = words[0].size();
        unordered_map<string, int> m1;
        for (string w : words) ++m1[w];
        for (int i = 0; i < len; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> m2;
            for (int j = i; j <= n - len; j += len) {
                string t = s.substr(j, len);
                if (m1.count(t)) {
                    ++m2[t];
                    if (m2[t] <= m1[t]) {
                        ++count;
                    } else {
                        while (m2[t] > m1[t]) {
                            string t1 = s.substr(left, len);
                            --m2[t1];
                            if (m2[t1] < m1[t1]) --count;
                            left += len;
                        }
                    }
                    if (count == cnt) {
                        res.push_back(left);
                        --m2[s.substr(left, len)];
                        --count;
                        left += len;
                    }
                } else {
                    m2.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }
        return res;
    }
};


class Solution97 {
public:
    // 2022.8.27, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/substring-with-concatenation-of-all-words.cpp
    // Time:  O((m + n) * k), m is the length of the string,
    //                        n is the size of the dictionary,
    //                        k is the length of each word
    // Space: O(n * k)
    // Sliding window solution.
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) {
            return {};
        }
        
        vector<int> result;
        const int m = s.length(), n = words.size(), k = words.front().length();
        if (m < n * k) {
            return result;
        }

        unordered_map<string, int> lookup;
        for (const auto& word : words) {
            ++lookup[word];                        // Space: O(n * k)
        }
        for (int i = 0; i < k; ++i) {              // Time:  O(k)
            unordered_map<string, int> tmp;
            for (int j = i, left = i, count = 0; j <= m - k; j += k) {  // Time:  O(m / k)
                const auto& str = s.substr(j, k);  // Time:  O(k)
                if (lookup.count(str)) {
                    ++tmp[str];
                    ++count;
                    while (tmp[str] > lookup[str]) {
                        --tmp[s.substr(left, k)];
                        --count;
                        left += k;
                    }
                    if (count == n) {
                        result.emplace_back(left);
                    }
                } else {
                    tmp.clear();
                    count = 0;
                    left = j + k;
                }
            }
        }
        return result;
    }
};


class Solution96 {
public:
    // 2022.8.27, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/substring-with-concatenation-of-all-words.cpp
    // Time:  O((m - n * k) * n * k) ~ O(m * n * k), m is the length of the string,
    //                                               n is the size of the dictionary,
    //                                               k is the length of each word
    // Space: O(n * k)
    vector<int> findSubstring(string s, vector<string>& words) {
        const auto word_length = words.front().length();
        const auto cat_length = word_length * words.size();
        vector<int> result;

        if (s.length() < cat_length) {
            return result;
        }

        unordered_map<string, int> wordCount;
        for (const auto & word : words) {
            ++wordCount[word];
        }

        for (auto it = s.begin(); it != prev(s.end(), cat_length - 1); ++it) {
            unordered_map<string, int> unused(wordCount);
            for (auto jt = it; jt != next(it, cat_length); jt += word_length) {
                auto pos = unused.find(string(jt, next(jt, word_length)));
                if (pos == unused.end()) {
                    break;
                }
                if (--pos->second == 0) {
                    unused.erase(pos);
                }
            }
            if (unused.empty()) {
                result.emplace_back(distance(s.begin(), it));
            }
        }
        return result;
    }
};


class Solution95 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/30.%20Substring%20with%20Concatenation%20of%20All%20Words
    // OJ: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
    // Author: github.com/lzl124631x
    // Time: O(MNL) where `M` is length of `A[i]`, `N` is length of `s`, and `L` is length of `A`.
    // Space: O(ML)
    // Solution 1. Fixed-length Sliding Window
    vector<int> findSubstring(string s, vector<string>& A) {
        int N = s.size(), M = A[0].size(), len = M * A.size();
        unordered_map<string, int> cnt, tmp;
        for (auto &w : A) cnt[w]++;
        vector<int> ans;
        for (int start = 0; start < M; ++start) {
            tmp.clear();
            int matched = 0;
            for (int i = start; i < N; i += M) {
                auto w = s.substr(i, M);
                if (cnt.count(w) && ++tmp[w] <= cnt[w]) matched++;
                if (i - len >= 0) {
                    auto rm = s.substr(i - len, M);
                    if (cnt.count(rm) && --tmp[rm] < cnt[rm]) matched--;
                }
                if (matched == A.size()) ans.push_back(i - len + M);
            }
        }
        return ans;
    }
};


class Solution94 {
private:
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/30.%20Substring%20with%20Concatenation%20of%20All%20Words
    // OJ: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
    // Author: github.com/lzl124631x
    // Time: O(MNL)
    // Space: O(ML)
    // Solution 2. Backtracking
    vector<int> findSubstring(string s, vector<string>& A) {
        if (A.empty()) return {};
        int L = A.size(), M = A[0].size(), last = s.size() - M * L;
        unordered_map<string, int> cnt;
        for (auto &w : A) ++cnt[w];
        vector<int> ans;
        function<bool(int, int)> dfs = [&](int i, int seen) {
            if (seen == L) return true;
            int &c = cnt[s.substr(i, M)];
            if (!c) return false;
            c--;
            bool ans = dfs(i + M, seen + 1);
            c++;
            return ans;
        };
        for (int i = 0; i <= last; ++i) {
            if (dfs(i, 0)) ans.push_back(i);
        }
        return ans;
    }
};


class Solution93 {
public:
    // 2022.8.27, from https://walkccc.me/LeetCode/problems/0030/
    // Time: O(|\texttt{s}||\texttt{words}||\texttt{words[0]}|)
    // Space: O(\Sigma |\texttt{words[i]}|)O(Σ∣words[i]∣)
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty())
        return {};

        const int k = words.size();
        const int n = words[0].length();
        vector<int> ans;
        unordered_map<string, int> count;

        for (const string& word : words)
        ++count[word];

        for (int i = 0; i < s.length() - k * n + 1; ++i) {
        unordered_map<string, int> seen;
        int j;
        for (j = 0; j < k; ++j) {
            const string& word = s.substr(i + j * n, n);
            if (++seen[word] > count[word])
            break;
        }
        if (j == k)
            ans.push_back(i);
        }

        return ans;
    }
};


class Solution92 {
public:
    // 2022.8.27, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/030.Substring-with-Concatenation-of-All-Words/30.%20Substring%20with%20Concatenation%20of%20All%20Words.cpp
    /*
        30. Substring-with-Concatenation-of-All-Words
        典型的双指针算法题，常规思路：右指针一路前进，遇到不符合条件的情况就移动左指针直至消除负面条件，再接着移动右指针。
        具体的实现比较复杂，需要注意这么几点：
        1.增加一个外层循环，双指针的起始点可以从0~M, M是每个词的长度. 注意count和showTime在每个start都要清零，故设置
        为循环内变量。

                for (int start=0; start<M; start++ )
                {
                    int i=start;
                    int j=start;
                    int count=0;
                    unordered_map<string,int> showTime;
                    
                    while (j<s.size() && i<=j)
                    {
                        ...
                    }
                }
        2.每次考察右指针对应的待加入的子串，

                        string ss = s.substr(j,M);
        但不要着急移动右指针，进入如下的判断：

        (a).待加入的新元素不在字典中，则count和showTime全部都清零！移动两个指针：都移到右指针的下一个位置

                        if (Map.find(ss)==Map.end())
                        {
                            j+=M;
                            i=j;
                            count=0;
                            showTime.clear();
                        }
        (b).待加入的新元素在字典中，且没有溢出，则加入并更新统计。移动右指针。
        注意，加入之后如果已经满足条件，则记录并处理。

                        else if (Map_temp[ss]<Map[ss])
                        {
                            j+=M;
                            showTime[ss]++;
                            if (showTime[ss]==Map[ss])
                                count++;
                            
                            if (count==N)
                            {
                                results.push_back(i);
                                string tt = s.substr(i,M);
                                showTime[tt]--;
                                count--;
                                i+=M;
                            }
                        }
        (c) 待加入的新元素虽然在字典中，但会造成溢出，则不加入统计。移动左指针，退出最左边的元素。

                        else
                        {
                            string tt = s.substr(i,M);
                            showTime[tt]--;
                            if (showTime[tt]==Map[tt]-1)
                                count--;
                            i+=M;
                        }
        5.重复循环。
    */
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        int N=words[0].size();
        int COUNT=words.size();
        unordered_map<string,int>Table;
        for (int i=0; i<words.size(); i++)
            Table[words[i]]++;
                
        vector<int>results;
        for (int start=0; start<N; start++)
        {
            int i=start;
            int j=i;
            int count=0;
            unordered_map<string,int>Map;

            while (j<s.size())
            {
                if (Table.find(s.substr(j,N))==Table.end())
                {
                    Map.clear();
                    count=0;
                    j+=N;
                    i=j;
                }
                else if (Map[s.substr(j,N)]<Table[s.substr(j,N)])
                {
                    Map[s.substr(j,N)]++;
                    count++;
                    j+=N;
                }
                else if (Map[s.substr(j,N)]==Table[s.substr(j,N)])
                {
                    Map[s.substr(i,N)]--;
                    i+=N;
                    count--;
                }
                
                if (count==COUNT)
                {
                    results.push_back(i);
                    Map[s.substr(i,N)]--;
                    i+=N;
                    count--;                    
                }                                     
            }
        }
        
        return results;
    }
};


class Solution91 {
    // Substring with Concatenation of All Words
    #define REP(i, n) for (int i = 0; i < (n); i++)

public:
    // 2022.8.27, from https://github.com/MaskRay/LeetCode/blob/master/substring-with-concatenation-of-all-words.cc
    // NOTE: Time Limit Exceeded as of 2022.8.27
    vector<int> findSubstring(string S, vector<string> &L) {
        map<string, int> ss;
        map<string, int> tt;
        vector<int> r;
        int n = S.size(), m = L[0].size();
        if (m*L.size() > n)
        return r;
        for (auto x: L)
        ++ss[x];
        REP(i, n-m+1) {
            bool f = true;
            tt.clear();
            for (int j = i; j < i+L.size()*m; j += m) {
                string t = S.substr(j, m);
                if (! ss.count(t) || ++tt[t] > ss[t]) {
                    f = false;
                    break;
                }
            }
            if (f)
                r.push_back(i);
        }
        return r;
    }
};


class Solution {
public:
    // 2022.8.27, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/0001-0500/0030-Substring-with-Concatenation-of-All-Words/cpp-0030/main.cpp
    // Sliding Window
    // Time Complexity: O(word_len * |s|)
    // Space Complexity: O(|s|)
    vector<int> findSubstring(string s, vector<string>& words) {

        int word_len = words[0].size();

        map<string, int> words_f;
        for(int i = 0; i < words.size(); i ++) words_f[words[i]] ++;

        vector<int> res;
        for(int start = 0; start < word_len; start ++){

            vector<string> data;
            for(int i = start; i < s.size(); i += word_len)
                data.push_back(s.substr(i, word_len));

            int ok_cnt = 0, l = 0, r = -1;
            map<string, int> cur_f;
            while(l < (int)data.size()){
                if(r + 1 < (int)data.size() && words_f.count(data[r + 1]) && cur_f[data[r + 1]] + 1 <= words_f[data[r + 1]]){
                    cur_f[data[r + 1]] ++;

                    if(cur_f[data[r + 1]] == words_f[data[r + 1]]){
                        ok_cnt ++;
                        if(ok_cnt == words_f.size())
                            res.push_back(start + l * word_len);
                    }

                    r ++;
                }
                else{

                    if(words_f.count(data[l])){
                        cur_f[data[l]] --;
                        if(cur_f[data[l]] + 1 == words_f[data[l]]) ok_cnt --;
                    }
                    l ++;
                    r = max(r, l - 1);
                }
            }
        }

        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

