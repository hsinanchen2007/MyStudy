/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

/*

https://leetcode.cn/problems/find-all-anagrams-in-a-string/

438. 找到字符串中所有字母异位词
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
 

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 

提示:

1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母
通过次数222,464提交次数406,280

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.27, by Hsinan
    vector<int> findAnagrams(string &str, string &pattern) {
        vector<int> resultIndices;
        // TODO: Write your code here
        int start = 0;
        int patternSize = pattern.size();
        unordered_map<char, int> hashTbl;
        for (auto item : pattern) {
            hashTbl[item]++;
        }
        unordered_map<char, int> tmpTbl;
        for (int end = 0; end < str.size(); end++) {
            tmpTbl[str[end]]++;
            if (end - start + 1 == patternSize) {
                bool isMatch = true;
                for (auto check : tmpTbl) {
                    if (tmpTbl[check.first] != hashTbl[check.first]) {
                        isMatch = false;
                        break;
                    } 
                }
                if (isMatch) {
                    resultIndices.push_back(start);
                }
                tmpTbl[str[start]]--;
                if (tmpTbl[str[start]] == 0) {
                    tmpTbl.erase(str[start]);
                }
                start++;
            } 
        }

        return resultIndices;
    }
};


class Solution99 {
public:
    // 2022.8.27, from https://www.acwing.com/activity/content/code/content/541455/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/541455/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> cnt;
        for (auto c: p) cnt[c] ++ ;
        vector<int> res;
        int tot = cnt.size();
        for (int i = 0, j = 0, satisfy = 0; i < s.size(); i ++ ) {
            if ( -- cnt[s[i]] == 0) satisfy ++ ;
            while (i - j + 1 > p.size()) {
                if (cnt[s[j]] == 0) satisfy -- ;
                cnt[s[j ++ ]] ++ ;
            }
            if (satisfy == tot) res.push_back(j);
        }
        return res;
    }
};


class Solution98 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/438
    /*
        这道题给了我们两个字符串s和p，让在s中找字符串p的所有变位次的位置，所谓变位次就是字符种类个数均相同但是顺序可以
        不同的两个词，那么肯定首先就要统计字符串p中字符出现的次数，然后从s的开头开始，每次找p字符串长度个字符，来验证字
        符个数是否相同，如果不相同出现了直接 break，如果一直都相同了，则将起始位置加入结果 res 中，参见代码如下：
        解法一：
    */
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        vector<int> res, cnt(128, 0);
        int ns = s.size(), np = p.size(), i = 0;
        for (char c : p) ++cnt[c];
        while (i < ns) {
            bool success = true;
            vector<int> tmp = cnt;
            for (int j = i; j < i + np; ++j) {
                if (--tmp[s[j]] < 0) {
                    success = false;
                    break;
                }
            }
            if (success) {
                res.push_back(i); 
            }
            ++i;
        }
        return res;
    }
};


class Solution97 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/438
    // NOTE: this line "if (p.size() > s.size()) return {};" is added by Hsinan to pass
    //       new LC testcase
    /*
        我们可以将上述代码写的更加简洁一些，用两个哈希表，分别记录p的字符个数，和s中前p字符串长度的字符个数，然后比较，如果
        两者相同，则将0加入结果 res 中，然后开始遍历s中剩余的字符，每次右边加入一个新的字符，然后去掉左边的一个旧的字符，
        每次再比较两个哈希表是否相同即可，参见代码如下：
        解法二：
    */
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        if (p.size() > s.size()) return {};
        vector<int> res, m1(256, 0), m2(256, 0);
        for (int i = 0; i < p.size(); ++i) {
            ++m1[s[i]]; ++m2[p[i]];
        }
        if (m1 == m2) res.push_back(0);
        for (int i = p.size(); i < s.size(); ++i) {
            ++m1[s[i]]; 
            --m1[s[i - p.size()]];
            if (m1 == m2) res.push_back(i - p.size() + 1);
        }
        return res;
    }
};


class Solution96 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/438
    /*
        下面这种利用滑动窗口 Sliding Window 的方法也比较巧妙，首先统计字符串p的字符个数，然后用两个变量 left 和 right 
        表示滑动窗口的左右边界，用变量 cnt 表示字符串p中需要匹配的字符个数，然后开始循环，如果右边界的字符已经在哈希表中了，
        说明该字符在p中有出现，则 cnt 自减1，然后哈希表中该字符个数自减1，右边界自加1，如果此时 cnt 减为0了，说明p中的字符
        都匹配上了，那么将此时左边界加入结果 res 中。如果此时 right 和 left 的差为p的长度，说明此时应该去掉最左边的一个
        字符，如果该字符在哈希表中的个数大于等于0，说明该字符是p中的字符，为啥呢，因为上面有让每个字符自减1，如果不是p中的
        字符，那么在哈希表中个数应该为0，自减1后就为 -1，所以这样就知道该字符是否属于p，如果去掉了属于p的一个字符，cnt 
        自增1，参见代码如下：
        解法三：
    */
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        vector<int> res, m(256, 0);
        int left = 0, right = 0, cnt = p.size(), n = s.size();
        for (char c : p) ++m[c];
        while (right < n) {
            if (m[s[right++]]-- >= 1) --cnt;
            if (cnt == 0) res.push_back(left);
            if (right - left == p.size() && m[s[left++]]++ >= 0) ++cnt;
        }
        return res;
    }
};


class Solution95 {
public:
    // 2022.8.27, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/find-all-anagrams-in-a-string.cpp
    // Time:  O(n)
    // Space: O(1)
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (p.empty() || s.empty()) {
            return result;
        }

        vector<int> cnts(26);
        for (const auto& c : p) {
            ++cnts[c - 'a'];
        }
        
        for (int left = 0, right = 0; right < s.length(); ++right) {
            --cnts[s[right] - 'a'];
            while (left <= right && cnts[s[right] - 'a'] < 0) {
                ++cnts[s[left++] - 'a'];
            }
            if (right - left + 1 == p.length()) {
                result.emplace_back(left);
            }
        }
        return result;
    }
};


class Solution94 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/438.%20Find%20All%20Anagrams%20in%20a%20String
    // OJ: https://leetcode.com/problems/find-all-anagrams-in-a-string/
    // Author: github.com/lzl124631x
    // Time: O(M + RN) where `R` is the range of characters
    // Space: O(R)
    vector<int> findAnagrams(string s, string p) {
        int target[26] = {}, cnt[26] = {};
        for (char c : p) target[c - 'a']++;
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            cnt[s[i] - 'a']++;
            if (i >= p.size()) cnt[s[i - p.size()] - 'a']--;
            int j = 0;
            for (; j < 26 && target[j] == cnt[j]; ++j);
            if (j == 26) ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};


class Solution93 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/438.%20Find%20All%20Anagrams%20in%20a%20String
    // OJ: https://leetcode.com/problems/find-all-anagrams-in-a-string/
    // Author: github.com/lzl124631x
    // Time: O(M + RN) where `R` is the range of characters
    // Space: O(1)
    vector<int> findAnagrams(string s, string p) {
        int cnt[26] = {};
        for (char c : p) cnt[c - 'a']++;
        vector<int> ans;
        for (int i = 0, N = s.size(), M = p.size(); i < N; ++i) {
            cnt[s[i] - 'a']--;
            if (i - M >= 0) cnt[s[i - M] - 'a']++;
            int j = 0;
            while (j < 26 && cnt[j] == 0) ++j;
            if (j == 26) ans.push_back(i - M + 1);
        }
        return ans;
    }
};


class Solution92 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/438.%20Find%20All%20Anagrams%20in%20a%20String
    // OJ: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/
    // Author: github.com/lzl124631x
    // Time: O(M + N)
    // Space: O(R) where `R` is the range of characters
    vector<int> findAnagrams(string s, string p) {
        int cnt[26] = {}, matched = 0;
        for (char c : p) cnt[c - 'a']++;
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            if (--cnt[s[i] - 'a'] >= 0) ++matched;
            if (i >= p.size() && ++cnt[s[i - p.size()] - 'a'] > 0) --matched;
            if (matched == p.size()) ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};


class Solution91 {
public:
    // 2022.8.27, from https://walkccc.me/LeetCode/problems/0438/
    // Time: O(n)
    // Space: O(26)
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> count(128);
        int required = p.length();

        for (const char c : p)
            ++count[c];

        for (int l = 0, r = 0; r < s.length(); ++r) {
            if (--count[s[r]] >= 0)
                --required;
            while (required == 0) {
                if (r - l + 1 == p.length())
                    ans.push_back(l);
                if (++count[s[l++]] > 0)
                    ++required;
            }
        }

        return ans;
    }
};


class Solution90 {
public:
    // 2022.8.27, from https://github.com/wisdompeak/LeetCode/blob/master/Hash/438.Find-All-Anagrams-in-a-String/438.Find%20All%20Anagrams%20in%20a%20String.cpp
    /*
        438.Find-All-Anagrams-in-a-String
        注意到本题的查验子串的窗口长度是固定的s.size()，所以不需要双指针，单指针即可。
        需要构造字符的哈希表时，用数组而不是map，效率更高。但记得一定要赋初值 vectorMap(256,0)
        数组之间判断是否相等的比较，直接用 == 即可。
        仔细考虑循环条件，不要遗漏最后一次比较。
        完全相同的问题有 567.Permutation in String
    */
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int>P(255,0);
        vector<int>S(255,0);
        for (char ch:p) P[ch]++;
        
        vector<int>results;
        for (int i=0; i<s.size(); i++)
        {
            S[s[i]]++;
            if (i>=p.size()) S[s[i-p.size()]]--;            
            if (S==P) results.push_back(i-p.size()+1);
        }
        return results;
    }
};


class Solution89 {
public:
    // 2022.8.27, from https://medium.com/leetcode-patterns/leetcode-pattern-2-sliding-windows-for-strings-e19af105316b
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> table;
        vector<int> ans;
        
        for(char c : p){
            table[c]++;
        }
        
        if(s.length() < p.length() || s.length() == 0) return ans;
        
        int begin = 0, end = 0, word_size = p.length();
        int counter = table.size();
        
        while(end  < s.length()){
            char endchar = s[end];
            
            if(table.count(endchar) == 1){
                table[endchar]--;
                if(table[endchar] == 0) counter--;
            }
            
            end++;
            
            while(counter == 0){
                if(end - begin == word_size) {
                    ans.push_back(begin);
                }
                
                char beginchar = s[begin];
                
                if(table.count(beginchar) == 1){
                    table[beginchar]++;
                    if(table[beginchar] > 0) counter++;
                }
                
                begin++;
            }
        }
        
        return ans;
    }
};


class Solution88 {
public:
    // 2023.2.11, from https://ke.algomooc.com/p/t_pc/course_pc_detail/video/v_62c247d5e4b00a4f372196e7?product_id=p_62b96d90e4b00a4f371ee3ad&content_app_id=&type=8&parent_pro_id=p_6243bcc1e4b04e8d90291891
    vector<int> findAnagrams(string s, string p) {

        // 滑动窗口模板化解题，五步走策略

        // 【1、定义需要维护的变量】

        // 题目要求返回这些子串的起始索引，因此使用数组来保存结果，存储的是整型
        vector<int> res;

        // 由于都是小写字母，因此直接用 26 个长度的数组代替原来的 HashMap ，比直接使用 HashMap 更优秀
        // needs 代表 p 中每个字符出现的频次
        vector<int> needs(26, 0);
        

        for(auto& ch : p){
            // 对于数组类型，其下标为 int 类型
            // 可以直接使用 char 类型变量，默认强制转换，存储的就是字母对应的 ASCII 码
            // 比如 ch 是 b 字符，那么 b - a = 1，即 needs[1] 表示记录 b 出现的频次
            needs[ch - 'a']++;
        }

        // window 代表在滑动窗口中每个字符出现的频次
        vector<int> window(26, 0);


        // 【2、定义窗口的首尾端 (start, end)， 然后滑动窗口】

        // 窗口的左端位置从 0 开始
        int start = 0;

         // 窗口的右端位置从 0 开始，可以一直移动到尾部
        for(int end = 0; end < s.size(); end++){

            // 【3、更新需要维护的变量, 有的变量需要一个 if 语句来维护 (比如最大最小长度)】

            // 获取此时将要加入到滑动窗口的元素
            auto cur = s[end];

            // 这个字符的频次需要发生变化
            window[cur - 'a']++;

            // 加入之后，去对比一下 window 中 cur 这个字符是否满足要求
            if(window == needs){
                
                // 相同情况下，找到一个符合条件的索引
                res.push_back(start);
            } 
            

            // 【4、如果题目的窗口长度固定：用一个 if 语句判断一下当前窗口长度是否达到了限定长度 】

            // 4.1、如果达到了，窗口左指针前移一个单位，从而保证下一次右指针右移时，窗口长度保持不变,
            if( end >= p.size() - 1 ){
                
                // 4.2、更新 (部分或所有) 维护变量 
                auto chr = s[start];

                // 最左端那个元素的频次发生变化
                window[chr - 'a']--;

                // 4.3、窗口左指针前移一个单位保证下一次右指针右移时窗口长度保持不变
                start++;
                
            }

        }

        // 【5、返回所需要的答案】
        return res;
    }
};


class Solution87 {
public:
    // 2023.2.11, from https://zxi.mytechroad.com/blog/?s=LeetCode+438.
    // Author: Huahua
    // Running time: 35 ms
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int l = p.length();
        vector<int> ans;
        vector<int> vp(26, 0);
        vector<int> vs(26, 0);
        for (char c : p) ++vp[c - 'a'];    
        for (int i = 0; i < n; ++i) {
            if (i >= l) --vs[s[i - l] - 'a'];        
            ++vs[s[i] - 'a'];
            if (vs == vp) ans.push_back(i + 1 - l);
        }
        return ans;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/

class Solution86 {
public:
    // 2023.2.14, from https://labuladong.github.io/algo/di-ling-zh-bfe1b/wo-xie-le--f02cd/
    vector<int> findAnagrams(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        vector<int> res; // 记录结果
        while (right < s.size()) {
            char c = s[right];
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) 
                    valid++;
            }
            // 判断左侧窗口是否要收缩
            while (right - left >= t.size()) {
                // 当窗口符合条件时，把起始索引加入 res
                if (valid == need.size())
                    res.push_back(left);
                char d = s[left];
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    // 2023.3.19, mainly from educative template
    // s1 is target, s2 is pattern while LC 567 is s1 is pattern, s2 is target
    vector<int> findAnagrams(string s1, string s2) {
        unordered_map<char, int> hashTbl;
        vector<int> answer;
        int matched = 0;

        // fill up hashTbl of s1 first
        for (auto item : s2) hashTbl[item]++;

        // iterate s2 string and compare with hashTbl
        for (int start = 0, end = 0; end < s1.size(); end++) {
            // update hashTbl and check matched
            if (hashTbl.find(s1[end]) != hashTbl.end()) {
                hashTbl[s1[end]]--;
                if (hashTbl[s1[end]] == 0) {
                    matched++;
                }
            }

            if (matched == hashTbl.size()) {
                answer.push_back(start);
            };

            // update start
            if (end >= s2.size() - 1) {
                char leftChar = s1[start++];
                if (hashTbl.find(leftChar) != hashTbl.end()) {
                    if (hashTbl[leftChar] == 0) {
                        matched--;
                    }
                    // this one is tricky, it is to maintain the original hashTbl as original value
                    hashTbl[leftChar]++;
                }
            }
        }

        return answer;
    }
};


// @lc code=end

