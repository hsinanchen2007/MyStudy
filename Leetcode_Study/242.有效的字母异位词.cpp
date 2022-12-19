/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

/*

https://leetcode.cn/problems/valid-anagram/

242. 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true

示例 2:

输入: s = "rat", t = "car"
输出: false
 

提示:

1 <= s.length, t.length <= 5 * 104
s 和 t 仅包含小写字母
 

进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

通过次数457,684提交次数698,332

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.23, by Hsinan, reference https://github.com/lzl124631x/LeetCode/tree/master/leetcode/242.%20Valid%20Anagram
    bool isAnagram(string s, string t) {
        // quick sanity check, if the size is already different, they musy be different
        if (s.size() != t.size()) return false;

        // question already says only 仅包含小写字母
        // use cnt, one ++, another --, and the end, they should be all 0, 
        // otherwise that means some differences in two strings
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;

        // final check
        for (int n : cnt) {
            // difference
            if (n) return false;
        }
        return true;
    }
};


class Solution99 {
public:
    // 2022.7.23, from https://walkccc.me/LeetCode/problems/0242/
    // different size is handled at the beginning
    // if any different happened from 2nd string, it will be < 0 value 
    // as it didn't show up in 1st string
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
        return false;

        vector<int> count(128);

        for (const char c : s)
        ++count[c];

        for (const char c : t)
        if (--count[c] < 0)
            return false;

        return true;
    }
};


class Solution98 {
public:
    // 2022.7.23, from 程序员吴师兄
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 有效的字母异位词（LeetCode 242）：https://leetcode.cn/problems/valid-anagram/
    bool isAnagram(string s, string t) {
        // 如果两个字符串的长度都不一致，那么肯定是无法成为字母异位词的
        if(s.length() != t.length()){

            // 直接返回 false
            return false;

        }

        // 让 a - z 这 26 个字母对应的下标变成 0 - 25 方便存到数组中
        // 比如 a 对应的索引就是 0 
        // b 对应的索引就是 1
        vector<int> table(26, 0);

        // 从头到尾遍历字符串 s
        for( int i = 0 ; i < s.length() ; i++){

            // 把访问的字符转换为整数的形式
            // 比如访问字母 a，那么 -'a' 之后就是 0，就是 a 对应的索引为 0 
            int index = s[i] - 'a';

            // 那么意味着这个字母出现的频次需要加 1
            table[index]++;

        }

        for( int i = 0 ; i < t.length() ; i++){

            // 把访问的字符转换为整数的形式
            // 比如访问字母 a，那么 -'a' 之后就是 0，就是 a 对应的索引为 0 
            int index = t[i] - 'a';

            // 那么意味着这个字母出现的频次需要减 1 
            table[index]--;

            // 如果说发现这个字母出现的频次小于了 0 
            // 说明 t 中出现了 s 中不曾用的字母
            if(table[index] < 0){

                // 那就不是字母异位词
                return false;

            }

        }

        // 否则，说明是字母异位词
        return true;
    }
};


class Solution97 {
public:
    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.md
    /*
        本题B站视频讲解版：学透哈希表，数组使用有技巧！Leetcode：242.有效的字母异位词

        先看暴力的解法，两层for循环，同时还要记录字符是否重复出现，很明显时间复杂度是 O(n^2)。
        暴力的方法这里就不做介绍了，直接看一下有没有更优的方式。

        数组其实就是一个简单哈希表，而且这道题目中字符串只有小写字符，那么就可以定义一个数组，来记录字符串s里字符出现的次数。
        如果对哈希表的理论基础关于数组，set，map不了解的话可以看这篇：关于哈希表，你该了解这些！

        需要定义一个多大的数组呢，定一个数组叫做record，大小为26 就可以了，初始化为0，因为字符a到字符z的ASCII也是26个连续的数值。
        为了方便举例，判断一下字符串s= "aee", t = "eae"。

        操作动画如下：

        242.有效的字母异位词

        定义一个数组叫做record用来上记录字符串s里字符出现的次数。

        需要把字符映射到数组也就是哈希表的索引下标上，因为字符a到字符z的ASCII是26个连续的数值，所以字符a映射为下标0，
        相应的字符z映射为下标25。再遍历 字符串s的时候，只需要将 s[i] - ‘a’ 所在的元素做+1 操作即可，并不需要记住字符a的ASCII，
        只要求出一个相对数值就可以了。 这样就将字符串s中字符出现的次数，统计出来了。

        那看一下如何检查字符串t中是否出现了这些字符，同样在遍历字符串t的时候，对t中出现的字符映射哈希表索引上的数值再做-1的操作。
        那么最后检查一下，record数组如果有的元素不为零0，说明字符串s和t一定是谁多了字符或者谁少了字符，return false。

        最后如果record数组所有元素都为零0，说明字符串s和t是字母异位词，return true。
        时间复杂度为O(n)，空间上因为定义是的一个常量大小的辅助数组，所以空间复杂度为O(1)。

        C++ 代码如下：
    */
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        // record数组所有元素都为零0，说明字符串s和t是字母异位词
        return true;
    }
};


class Solution96 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/valid-anagram.cpp
    // Time:  O(n)
    // Space: O(1)
    bool isAnagram(string s, string t) {
        if (size(s) != size(t)) {
            return false;
        }

        unordered_map<char, int> count;
        for (const auto& c: s) {
            ++count[c];
        }
        for (const auto& c: t) {
            --count[c];
            if (count[c] < 0) {
                return false;
            }
        }
        return true;
    }
};


class Solution95 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/valid-anagram.cpp
    // Time:  O(nlogn)
    // Space: O(1)
    bool isAnagram(string s, string t) {
        if (size(s) != size(t)) {
            return false;
        }

        sort(begin(s), end(s));
        sort(begin(t), end(t));
        return s == t;
    }
};


class Solution94 {
public:
    // 2022.7.23, from AcWing https://www.acwing.com/activity/content/code/content/445280/
    // use C++ STL's build-in "==" to check the difference
    bool isAnagram(string s, string t) {
        unordered_map<char, int> a, b;
        for (auto c: s) a[c] ++ ;
        for (auto c: t) b[c] ++ ;
        return a == b;
    }
};


// OJ: https://leetcode.com/problems/valid-anagram/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(C)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;
        for (int n : cnt) {
            if (n) return false;
        }
        return true;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

