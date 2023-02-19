/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */

/*

https://leetcode.cn/problems/unique-substrings-in-wraparound-string/

467. 环绕字符串中唯一的子字符串

中等
371
company
字节跳动

定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串，所以 base 看起来是这样的：

"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现。

示例 1：

输入：s = "a"
输出：1
解释：字符串 s 的子字符串 "a" 在 base 中出现。

示例 2：

输入：s = "cac"
输出：2
解释：字符串 s 有两个子字符串 ("a", "c") 在 base 中出现。

示例 3：

输入：s = "zab"
输出：6
解释：字符串 s 有六个子字符串 ("z", "a", "b", "za", "ab", and "zab") 在 base 中出现。 

提示：

1 <= s.length <= 105
s 由小写英文字母组成

*/

// @lc code=start
class Solution100 {
public:
    int findSubstringInWraproundString(string s) {
        // 2023.2.19, from https://github.com/grandyang/leetcode/issues/467
        /*
            这道题说有一个无限长的封装字符串，然后又给了我们另一个字符串p，问我们p有多少非空子字符串在封装字符串中。
            我们通过观察题目中的例子可以发现，由于封装字符串是26个字符按顺序无限循环组成的，那么满足题意的p的子字符串
            要么是单一的字符，要么是按字母顺序的子字符串。这道题遍历p的所有子字符串会TLE，因为如果p很大的话，子字符串
            很多，会有大量的满足题意的重复子字符串，必须要用到trick，而所谓技巧就是一般来说你想不到的方法。我们看abcd
            这个字符串，以d结尾的子字符串有abcd, bcd, cd, d，那么我们可以发现bcd或者cd这些以d结尾的字符串的子字符串
            都包含在abcd中，那么我们知道以某个字符结束的最大字符串包含其他以该字符结束的字符串的所有子字符串，说起来
            很拗口，但是理解了我上面举的例子就行。那么题目就可以转换为分别求出以每个字符(a-z)为结束字符的最长连续字符串
            就行了，我们用一个数组cnt记录下来，最后在求出数组cnt的所有数字之和就是我们要的结果啦，参见代码如下：        
        */
        vector<int> cnt(26, 0);
        int len = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && (s[i] == s[i - 1] + 1 || s[i - 1] - s[i] == 25)) {
                ++len;
            } else {
                len = 1;
            }
            cnt[s[i] - 'a'] = max(cnt[s[i] - 'a'], len);
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};


class Solution99 {
public:
    // 2023.2.19, from https://github.com/grandyang/leetcode/issues/467
    /*
        下面这种方法跟上面的基本一样，就是在更新每个最大长度时，把差值累加到结果中，这跟最后统一加上最大值的效果一样，
        参见代码如下：
    */
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26, 0);
        int res = 0, len = 0;
        for (int i = 0; i < p.size(); ++i) {
            int cur = p[i] - 'a';
            if (i > 0 && p[i - 1] != (cur + 26 - 1) % 26 + 'a') len = 0;
            if (++len > cnt[cur]) {
                res += len - cnt[cur];
                cnt[cur] = len;
            }
        }
        return res;
    }
};


class Solution98 {
public:
    // 2023.2.19, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/unique-substrings-in-wraparound-string.cpp
    // Time:  O(n)
    // Space: O(1)
    int findSubstringInWraproundString(string p) {
        vector<int> letters(26, 0);
        int result = 0, len = 0;
        for (int i = 0; i < p.length(); ++i) {
            int curr = p[i] - 'a';
            if (i > 0 && p[i - 1] != (curr + 26 - 1) % 26 + 'a') {
                len = 0;
            }
            if (++len > letters[curr]) {
                result += len - letters[curr];
                letters[curr] = len;
            }
        }
        return result;
    }
};


class Solution97 {
public:
    // 2023.2.19, from https://github.com/lzl124631x/LeetCode/blob/master/leetcode/467.%20Unique%20Substrings%20in%20Wraparound%20String/s1.cpp
    int findSubstringInWraproundString(string p) {
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            int maxLen = 0;
            for (int j = 0; j < p.size(); ++j) {
                if (p[j] == 'a' + i) {
                    int start = j;
                    while (j + 1 < p.size() && (p[j + 1] - 'a') == (p[j] - 'a' + 1) % 26) ++j;
                    maxLen = max(maxLen, j - start + 1);
                }
            }
            cnt += maxLen;
        }
        return cnt;
    }
};


class Solution96 {
public:
    int findSubstringInWraproundString(string p) {
        int cnt[26] = {0};
        int len, res = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && (p[i - 1] - 'a' + 1) % 26 == p[i] - 'a') ++len;
            else len = 1;
            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], len);
        }
        for (int n : cnt) res += n;
        return res;
    }
};

// Slightly different solution
// class Solution {
// public:
//     int findSubstringInWraproundString(string p) {
//         int cnt[26] = {0};
//         int len, res = 0;
//         for (int i = 0; i < p.size(); ++i) {
//             if (i > 0 && (p[i - 1] - 'a' + 1) % 26 == p[i] - 'a') ++len;
//             else len = 1;
//             int index = p[i] - 'a';
//             if (len > cnt[index]) {
//                 res += len - cnt[index];
//                 cnt[index] = len;
//             }
//         }
//         return res;
//     }
// };


class Solution95 {
public:
    // 2023.2.19, from https://walkccc.me/LeetCode/problems/0467/
    int findSubstringInWraproundString(string p) {
        int maxLength = 1;
        vector<int> count(26);  // Substrings end at i

        for (int i = 0; i < p.length(); ++i) {
            if (i > 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25))
                ++maxLength;
            else
                maxLength = 1;
            const int index = p[i] - 'a';
            count[index] = max(count[index], maxLength);
        }

        return accumulate(begin(count), end(count), 0);
    }
};


class Solution94 {
public:
    // 2023.2.19, from https://github.com/wisdompeak/LeetCode/blob/master/String/467.Unique-Substrings-in-Wraparound-String/467.Unique-Substrings-in-Wraparound-String.cpp
    /*
        467.Unique-Substrings-in-Wraparound-String
        注意s串的性质，其子串必然是递增的。发现这一点后，只要是在p中的所有递增子串，都是s的字串。

        那么p中有多少不同的递增子串呢？任何不同的递增字串，只需要两个参数就能确定其独特性。一个是起始字符，另一个是字串的长度。
        于是只要遍历p的每一个字符，找出以其为开头的最长递增字串即可。比如说p中以'a'开头的递增字串的最大长度是n，那么就有n种不同
        的以'a'开头的递增字串。

        创建一个Hash表，遍历p[i]。以遍历的字符p[i]作为key，记录以p[i]开头的递增字串的最大长度（这个value会随着p的遍历而不断被
        更新）。最终结果就是把所有key的value都加起来。    
    */
    int findSubstringInWraproundString(string p) 
    {
        unordered_map<char,int>Map;
        
        for (int i=0; i<p.size(); i++)
        {
            int i0=i;
            while (i+1<p.size() && (p[i+1]==p[i]+1 || p[i]=='z' && p[i+1]=='a'))
                i++;
            for (int k=i0; k<=i; k++)            
                Map[p[k]]=max(Map[p[k]],i-k+1);            
        }
        
        int count=0;        
        for (auto a:Map)
            count+=a.second;
        
        return count;
    }
};


class Solution {
public:
    // 2023.2.19, from https://www.acwing.com/activity/content/code/content/555940/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/555940/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int findSubstringInWraproundString(string p) {
        unordered_map<char, int> cnt;
        for (int i = 0; i < p.size();) {
            int j = i + 1;
            while (j < p.size() && (p[j] - p[j - 1] == 1 || p[j] == 'a' && p[j - 1] == 'z')) j ++ ;
            while (i < j) cnt[p[i]] = max(cnt[p[i]], j - i), i ++ ;
        }
        int res = 0;
        for (auto [a, b]: cnt) res += b;
        return res;
    }
};


// @lc code=end

