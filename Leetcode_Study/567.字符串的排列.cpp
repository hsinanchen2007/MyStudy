/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

/*

https://leetcode.cn/problems/permutation-in-string/

567. 字符串的排列
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。

换句话说，s1 的排列之一是 s2 的 子串 。
 

示例 1：

输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").
示例 2：

输入：s1= "ab" s2 = "eidboaoo"
输出：false
 

提示：

1 <= s1.length, s2.length <= 104
s1 和 s2 仅包含小写字母
通过次数216,571提交次数490,404

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.27, by Hsinan
    bool checkInclusion(string s1, string s2) {
        // s1 is pattern string
        int patternSize = s1.size();
        int start = 0;
        for (int end = patternSize - 1; end < s2.size(); end++) {
            // use substr, first parameter is starting index, second parameter is size
            string tmp = s2.substr(start, patternSize);
            if (std::is_permutation(tmp.begin(), tmp.end(), s1.begin())) {
                return true;
            } else {
                start++;
            }
        }
        return false;
    }
};


class Solution99 {
public:
    // 2022.8.27, from https://www.acwing.com/activity/content/code/content/610515/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/610515/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    unordered_map<char, int> S1, S2;

    bool check(char c) {
        if (S1.count(c) && S1[c] == S2[c])
            return true;
        return false;
    }

    bool checkInclusion(string s1, string s2) {
        for (auto c: s1) S1[c] ++ ;
        for (int i = 0, j = 0, cnt = 0; i < s2.size(); i ++ ) {
            if (check(s2[i])) cnt -- ;
            S2[s2[i]] ++ ;
            if (check(s2[i])) cnt ++ ;

            if (i - j >= s1.size()) {
                if (check(s2[j])) cnt -- ;
                S2[s2[j]] -- ;
                if (check(s2[j])) cnt ++ ;
                j ++ ;
            }
            if (cnt == S1.size()) return true;
        }

        return false;
    }
};


class Solution98 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/567
    // NOTE: Below code will have problem in LC!!!! 
    // TODO: Fix it later 
    /*
        这道题给了两个字符串s1和s2，问我们s1的全排列的字符串任意一个是否为s2的字串。虽然题目中有全排列的关键字，
        但是跟之前的全排列的题目的解法并不一样，如果受思维定势影响比较深的话，很容易遍历s1所有全排列的情况，然后
        检测其是否为s2的子串，这种解法是非常不高效的，估计OJ不会答应。 这道题的正确做法应该是使用滑动窗口Sliding 
        Window的思想来做，可以使用两个哈希表来做，或者是使用一个哈希表配上双指针来做。我们先来看使用两个哈希表
        来做的情况，我们先来分别统计s1和s2中前n1个字符串中各个字符出现的次数，其中n1为字符串s1的长度，这样如果
        二者字符出现次数的情况完全相同，说明s1和s2中前n1的字符互为全排列关系，那么符合题意了，直接返回true。
        如果不是的话，那么我们遍历s2之后的字符，对于遍历到的字符，对应的次数加1，由于窗口的大小限定为了n1，所以
        每在窗口右侧加一个新字符的同时就要在窗口左侧去掉一个字符，每次都比较一下两个哈希表的情况，如果相等，说明
        存在，参见代码如下：
        解法一：
    */
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> m1(128), m2(128);
        for (int i = 0; i < n1; ++i) {
            ++m1[s1[i]]; ++m2[s2[i]];
        }
        if (m1 == m2) return true;
        for (int i = n1; i < n2; ++i) {
            ++m2[s2[i]];
            --m2[s2[i - n1]];
            if (m1 == m2) return true;
        }
        return false;
    }
};


class Solution97 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/567
    /*
        下面这种解法是利用一个哈希表加上双指针，我们还是先统计s1中字符的出现次数，然后遍历s2中的字符，对于每个遍历到的字符，
        我们在哈希表中对应的字符次数减1，如果次数次数小于0了，说明该字符在s1中不曾出现，或是出现的次数超过了s1中的对应的字符
        出现次数，那么我们此时移动滑动窗口的左边界，对于移除的字符串，哈希表中对应的次数要加1，如果此时次数不为0，说明该字符
        不在s1中，继续向右移，直到更新后的次数为0停止，此时到达的字符是在s1中的。如果次数大于等于0了，我们看此时窗口大小是否
        为s1的长度，若二者相等，由于此时窗口中的字符都是在s1中存在的字符，而且对应的次数都为0了，说明窗口中的字符串和s1互为
        全排列，返回true即可，参见代码如下：
        解法二：
    */
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), left = 0;
        vector<int> m(128);
        for (char c : s1) ++m[c];
        for (int right = 0; right < n2; ++right) {
            if (--m[s2[right]] < 0) {
                while (++m[s2[left++]] != 0) {}
            } else if (right - left + 1 == n1) return true;
        }
        return n1 == 0;
    }
};


class Solution96 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/567
    /*
        下面这种解法也是用一个哈希表外加双指针来做的，跟上面的解法思路大体相同，写法有些不同，不变的还是统计s1中字符出现的次数，
        不一样的是我们用一个变量cnt来表示还需要匹配的s1中的字符的个数，初始化为s1的长度，然后遍历s2中的字符，如果该字符在哈希
        表中存在，说明匹配上了，cnt自减1，哈希表中的次数也应该自减1，然后如果cnt减为0了，说明s1的字符都匹配上了，如果此时窗口
        的大小正好为s1的长度，那么说明找到了s1的全排列，返回true，否则说明窗口过大，里面有一些非s1中的字符，我们将左边界右移，
        同时将移除的字符串在哈希表中的次数自增1，如果增加后的次数大于0了，说明该字符是s1中的字符，我们将其移除了，那么cnt就要
        自增1，参见代码如下：
        解法三：
    */
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), cnt = n1, left = 0;
        vector<int> m(128);
        for (char c : s1) ++m[c];
        for (int right = 0; right < n2; ++right) {
            if (m[s2[right]]-- > 0) --cnt;
            while (cnt == 0) {
                if (right - left + 1 == n1) return true;
                if (++m[s2[left++]] > 0) ++cnt;
            }
        }
        return false;
    }
};


class Solution95 {
public:
    // 2022.8.27, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/permutation-in-string.cpp
    // Time:  O(n)
    // Space: O(1)
    bool checkInclusion(string s1, string s2) {
        vector<int> counts(256);
        for (const auto& c : s1) {
            ++counts[c];
        }
        for (int i = 0, l = s1.length(); i < s2.length(); ++i) {
            if (counts[s2[i]]-- > 0) {
                --l;
            }
            if (l == 0) {
                return true;
            }
            int start = i + 1 - s1.length();
            if (start >= 0 && ++counts[s2[start]] > 0) {
                ++l;
            }
        }
        return false;
    }
};


class Solution94 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/567.%20Permutation%20in%20String
    // OJ: https://leetcode.com/problems/permutation-in-string/
    // Author: github.com/lzl124631x
    // Time: O(B)
    // Space: O(1)
    /*
        Solution 1. Fixed-length Sliding Window
        Store the counts of letters of a in cnts array.

        When we consume a letter b[i], we decrement its count.
        When we pop a letter b[i - N], we increment its count. We start popping when i - N >= 0 to make sure the 
        sliding window is at most as long as a. Once all the counts in cnts array are zeros, we return true. If we 
        reached end of array and still haven't clear out the cnts, return false.

        The time complexity is O(26 * S2) = O(S2).
    */
    bool checkInclusion(string a, string b) {
        if (a.size() > b.size()) return false;
        int N = a.size(), cnts[26] = {};
        for (char c : a) cnts[c - 'a']++;
        for (int i = 0; i < b.size(); ++i) {
            cnts[b[i] - 'a']--;
            if (i - N >= 0) cnts[b[i - N] - 'a']++;
            bool match = true;
            for (int j = 0; j < 26 && match; ++j) {
                if (cnts[j]) match = false;
            }
            if (match) return true;
        }
        return false;
    }
};


class Solution93 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/567.%20Permutation%20in%20String
    // OJ: https://leetcode.com/problems/permutation-in-string/
    // Author: github.com/lzl124631x
    // Time: O(B)
    // Space: O(1)
    /*
        Solution 2. Fixed-length Sliding Window
        Similar to Solution 1, we keep a sliding window of size a.size(). Instead of checking the count for 26 characters, 
        we just use a matched variable to store the number of matched characters within the sliding window.
    */
    bool checkInclusion(string a, string b) {
        if (a.size() > b.size()) return false;
        int cnt[26] = {}, matched = a.size(), N = a.size();
        for (char c : a) cnt[c - 'a']++;
        for (int i = 0; i < b.size(); ++i) {
            if (i >= N) matched += cnt[b[i - N] - 'a']++ >= 0;
            matched -= cnt[b[i] - 'a']-- > 0;
            if (!matched) return true;
        }
        return false;
    }
};


class Solution92 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/567.%20Permutation%20in%20String
    // OJ: https://leetcode.com/problems/permutation-in-string/
    // Author: github.com/lzl124631x
    // Time: O(S2)
    // Space: O(1)
    /*
        Solution 3. Variable-length Sliding Window
        We keep the counts of letters of s1 in goal array. And we use two pointers i and j to consume s2, 
        and store the counts of letters within range [i, j) in cnt array.

        We keep incrementing j and the corresponding count cnt[s2[j]] until it reaches the end or 
        cnt[s2[j]] + 1 <= goal[s2[j]]. Let X be s2[j] then X is the letter we don't want to consume.
        If the gap between i and j is the length of s1, then we've found match and just return true.
        Since s2[j] is unwanted, we keep popping s2[i] by incrementing i until s2[i] == s2[j], meanwhile, 
        we decrement cnt[s2[i]].
        Now s[i] and s[j] are all pointing to the unwanted letter X, increment i and j both so that the 
        cnt[X] will be unchanged. Go to Step 1 until j reaches end.
    */
    bool checkInclusion(string s1, string s2) {
        int M = s1.size(), N = s2.size(), i = 0, j = 0, goal[26] = {0}, cnt[26] = {0};
        for (char c : s1) goal[c - 'a']++;
        for (; j < N; ++i, ++j) {
            while (j < N && cnt[s2[j] - 'a'] + 1 <= goal[s2[j] - 'a']) cnt[s2[j++] - 'a']++;
            if (j - i == M) return true;
            while (j < N && i < j && s2[i] != s2[j]) cnt[s2[i++] - 'a']--;
        }
        return false;
    }
};


class Solution91 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/567.%20Permutation%20in%20String
    // OJ: https://leetcode.com/problems/permutation-in-string/
    // Author: github.com/lzl124631x
    // Time: O(B)
    // Space: O(1)
    bool checkInclusion(string a, string b) {
        if (a.size() > b.size()) return false;
        int cnt[26] = {};
        for (char c : a) cnt[c - 'a']++;
        for (int i = 0, j = 0; j < b.size(); ++j) {
            if (--cnt[b[j] - 'a'] < 0) { // We can't have this `b[j]` in the window
                while (b[i] != b[j]) cnt[b[i++] - 'a']++; // keep skipping until `b[i] == b[j]`
                cnt[b[i++] - 'a']++; // remove `b[i]` from the window
            }
            if (j - i + 1 == a.size()) return true; // If the window has the same length as `a`, return true
        }
        return false;
    }
};


class Solution90 {
public:
    // 2022.8.27, from https://walkccc.me/LeetCode/problems/0567/
    // Time: O(∣s1∣+∣s2∣)
    // Space: O(128)=O(1)
    bool checkInclusion(string s1, string s2) {
        vector<int> count(128);
        int required = s1.length();

        for (const char c : s1)
        ++count[c];

        for (int l = 0, r = 0; r < s2.length(); ++r) {
            if (--count[s2[r]] >= 0)
                --required;
            while (required == 0) {
                if (r - l + 1 == s1.length())
                return true;
                if (++count[s2[l++]] > 0)
                ++required;
            }
        }

        return false;
    }
};


class Solution89 {
public:
    // 2022.8.27, from https://walkccc.me/LeetCode/problems/0567/
    // Time: O(∣s1∣+∣s2∣)
    // Space: O(128)=O(1)
    bool checkInclusion(string s1, string s2) {
        vector<int> count(128);
        int required = s1.length();

        for (const char c : s1)
        ++count[c];

        for (int r = 0; r < s2.length(); ++r) {
        if (--count[s2[r]] >= 0)
            --required;
        if (r >= s1.length())  // the window is oversized
            if (++count[s2[r - s1.length()]] > 0)
            ++required;
        if (required == 0)
            return true;
        }

        return false;
    }
};


class Solution88 {
public:
    // 2022.8.27, from https://ke.algomooc.com/detail/v_62c24811e4b00a4f37219707/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_62b96d90e4b00a4f371ee3ad
    bool checkInclusion(string s1, string s2) {
        // 滑动窗口模板化解题，五步走策略

        // 【1、定义需要维护的变量】

        // 题目要求返回这些子串的起始索引，因此使用数组来保存结果，存储的是整型
        vector<int> res;

        // 由于都是小写字母，因此直接用 26 个长度的数组代替原来的 HashMap ，比直接使用 HashMap 更优秀
        // needs 代表 p 中每个字符出现的频次
        vector<int> needs(26, 0);
        

        for(auto& ch : s1){
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
        for(int end = 0; end < s2.size(); end++){

            // 【3、更新需要维护的变量, 有的变量需要一个 if 语句来维护 (比如最大最小长度)】

            // 获取此时将要加入到滑动窗口的元素
            auto cur = s2[end];

            // 这个字符的频次需要发生变化
            window[cur - 'a']++;

            // 加入之后，去对比一下 window 中 cur 这个字符是否满足要求
            if(window == needs){
                
                // 相同情况下，找到了满足条件的一个解，返回 true
                return true;
            } 
            

            // 【4、如果题目的窗口长度固定：用一个 if 语句判断一下当前窗口长度是否达到了限定长度 】

            // 4.1、如果达到了，窗口左指针前移一个单位，从而保证下一次右指针右移时，窗口长度保持不变,
            if( end >= s1.size() - 1 ){
                
                // 4.2、更新 (部分或所有) 维护变量 
                auto chr = s2[start];

                // 最左端那个元素的频次发生变化
                window[chr - 'a']--;

                // 4.3、窗口左指针前移一个单位保证下一次右指针右移时窗口长度保持不变
                start++;
                
            }

        }

        // 【5、返回所需要的答案】
        return false;

    }
};


class Solution87 {
public:
    // 2022.8.27, from https://medium.com/leetcode-patterns/leetcode-pattern-2-sliding-windows-for-strings-e19af105316b
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> table;
        
        for(char c : s1){
            table[c]++;
        }
        
        int begin = 0, end = 0, counter = table.size();
        
        while(end < s2.length()){
            char endchar = s2[end];
            
            if(table.count(endchar) == 1){
                table[endchar]--;
                if(table[endchar] == 0) counter--;
            }
            
            end++;
            
            while(counter == 0){
                if(end - begin == s1.length()) return true;
                
                char startchar = s2[begin];
                
                if(table.count(startchar) == 1){
                    table[startchar]++;
                    if(table[startchar] > 0) counter++;
                }
                
                begin++;
            }
        }
        
        return false;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


class Solution {
    public:
        // 2022.9.2, from https://leetcode-solution.cn/book
        bool checkInclusion(string s1, string s2) {
            vector<int> cnts(256, 0);
            for (char ch: s1)
                cnts[ch]++;

            int left = s1.size();
            for (int i = 0, j = 0; j < s2.size(); j++) {
                if (cnts[s2[j]]-- > 0)
                    left--;

                while (left == 0) {
                    if (j + 1 - i == s1.size())
                        return true;
                    if (++cnts[s2[i++]] > 0)
                        left++;
                }
            }

            return false;
        }
};


// @lc code=end

