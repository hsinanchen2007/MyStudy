/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

/*

https://leetcode.cn/problems/longest-repeating-character-replacement/

424. 替换后的最长重复字符
给你一个字符串 s 和一个整数 k 。你可以选择字符串中的任一字符，并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。

在执行上述操作后，返回包含相同字母的最长子字符串的长度。
 

示例 1：

输入：s = "ABAB", k = 2
输出：4
解释：用两个'A'替换为两个'B',反之亦然。

示例 2：

输入：s = "AABABBA", k = 1
输出：4
解释：
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。
 

提示：

1 <= s.length <= 105
s 仅由大写英文字母组成
0 <= k <= s.length
通过次数74,817提交次数137,835

*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    2022.8.29
        The key condition to check is, when (end - start + 1 - max # of repeated ones > k), then we need to move 
        start pointer.

    Solution100 uses two for loop, by A-Z and by string s's beginning to end, to check if the window contains over
    # of can be replaced characters K, then move j (start pointer). As this solution has two for loops, not a 
    good one

    


*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @lc code=start
class Solution100 {
public:
    // 2022.8.26, from https://www.acwing.com/activity/content/code/content/535852/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/535852/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int characterReplacement(string s, int k) {
        int res = 0;
        for (char c = 'A'; c <= 'Z'; c ++ ) {
            for (int i = 0, j = 0, cnt = 0; i < s.size(); i ++ ) {
                if (s[i] == c) cnt ++ ;
                while (i - j + 1 - cnt > k) {
                    if (s[j] == c) cnt -- ;
                    j ++ ;
                }
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};


class Solution99 {
public:
    // 2022.8.26, from https://github.com/grandyang/leetcode/issues/424
    /*
        这道题给我们了一个字符串，说我们有k次随意置换任意字符的机会，让我们找出最长的重复字符的字符串。
        这道题跟之前那道 Longest Substring with At Most K Distinct Characters 很像，都需要用
        滑动窗口 Sliding Window 来解。我们首先来想，如果没有k的限制，让我们求把字符串变成只有一个字
        符重复的字符串需要的最小置换次数，那么就是字符串的总长度减去出现次数最多的字符的个数。如果加上k
        的限制，我们其实就是求满足 (子字符串的长度减去出现次数最多的字符个数)<=k 的最大子字符串长度即
        可，搞清了这一点，我们也就应该知道怎么用滑动窗口来解了吧。我们用一个变量 start 记录滑动窗口左
        边界，初始化为0，然后遍历字符串，每次累加出现字符的个数，然后更新出现最多字符的个数，然后我们判
        断当前滑动窗口是否满足之前说的那个条件，如果不满足，我们就把滑动窗口左边界向右移动一个，并注意
        去掉的字符要在 counts 里减一，直到满足条件，我们更新结果 res 即可。需要注意的是，当滑动窗口
        的左边界向右移动了后，窗口内的相同字母的最大个数貌似可能会改变啊，为啥这里不用更新 maxCnt 呢？
        这是个好问题，原因是此题让求的是最长的重复子串，maxCnt 相当于卡了一个窗口大小，我们并不希望窗
        口变小，虽然窗口在滑动，但是之前是出现过跟窗口大小相同的符合题意的子串，缩小窗口没有意义，并不
        会使结果 res 变大，所以我们才不更新 maxCnt 的，参见代码如下：
    */
    int characterReplacement(string s, int k) {
        int res = 0, maxCnt = 0, start = 0;
        vector<int> counts(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            maxCnt = max(maxCnt, ++counts[s[i] - 'A']);
            while (i - start + 1 - maxCnt > k) {
                --counts[s[start] - 'A'];
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};


class Solution98 {
public:
    // 2022.8.26, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-repeating-character-replacement.cpp
    // Time:  O(n)
    // Space: O(1)
    int characterReplacement(string s, int k) {
        int result = 0, max_count = 0;
        unordered_map<char, int> count;
        for (int i = 0; i < s.length(); ++i) {
            ++count[s[i]];
            max_count = max(max_count, count[s[i]]);
            if (result - max_count >= k) {
                --count[s[i - result]];
            } else {
                ++result;
            }
        }
        return result;
    }
};


class Solution97 {
public:
    // 2022.8.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/424.%20Longest%20Repeating%20Character%20Replacement
    // OJ: https://leetcode.com/problems/longest-repeating-character-replacement/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Solution 1. Sliding Window
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, cnt[26] = {}, ans = 0, N = s.size();
        while (j < N) {
            cnt[s[j++] - 'A']++;
            while (j - i - *max_element(cnt, cnt + 26) > k) cnt[s[i++] - 'A']--;
            ans = max(ans, j - i);
        }
        return ans;
    }
};


class Solution96 {
public:
    // 2022.8.26, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/424.%20Longest%20Repeating%20Character%20Replacement
    // OJ: https://leetcode.com/problems/longest-repeating-character-replacement/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Solution 2. Non-shrinkable Sliding Window:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, cnt[26] = {}, N = s.size();
        while (j < N) {
            cnt[s[j++] - 'A']++;
            if (j - i - *max_element(cnt, cnt + 26) > k) cnt[s[i++] - 'A']--;
        }
        return j - i;
    }
};


class Solution95 {
public:
    // 2022.8.26, from https://walkccc.me/LeetCode/problems/0424/
    // Time: O(n)
    // Space: O(128)=O(1)
    int characterReplacement(string s, int k) {
        int ans = 0;
        int maxCount = 0;
        vector<int> count(128);

        for (int l = 0, r = 0; r < s.length(); ++r) {
        maxCount = max(maxCount, ++count[s[r]]);
        while (maxCount + k < r - l + 1)
            --count[s[l++]];
        ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


class Solution94 {
    vector<int>count;
public:
    // 2022.8.26, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/424.Longest-Repeating-Character-Replacement/424.Longest-Repeating-Character-Replacement_v1.cpp
    /*
        424.Longest-Repeating-Character-Replacement
        本题的本质就是用一个滑动窗口，查找最长的subarray，使得其最多含有ｋ个与majority不相同的字符．
        这里majority指的是窗口中出现最多的那个字符．

        很显然，我们需要一个hash map或者字典来存放每个字符出现的次数．在不断拓宽窗口的过程中保持

        窗口长度数L - majority元素的个数M <= K
        如果不满足这个条件，那么就需要移动左指针一位，以缩短窗口．然后再尝试拓展右边界j。

        细节分析：

        １．为什么左指针移动之后不用更新结果？

        这是因为，我们移动左指针的起因是之前s[j]的引入，它必然是一个非majority的字符（否则整个窗口应该会继续保持合法），
        而无论左指针弹出的是否majority元素，都不会得到更好的结果，最多持平，所以我们不需要更新结果。

        ２．为什么左指针移动只需要一步？

        因为我们求最长的窗口，左指针的移动不用太大．事实上，只要移动左指针一步，那么整个窗口还是有机会通过移动右指针找到
        下一个可能的窗口．参看上面的那个公式．
    */
    int characterReplacement(string s, int k) 
    {        
        int ret = 0;
        int j = 0;
        count.resize(26);
        for (int i=0; i<s.size(); i++)
        {
            while (j<s.size() && checkOK(s, j, j-i+1, k))
                j++;
            ret = max(ret, j-i);
            count[s[i]-'A']--;
        }
        return ret;
    }

    bool checkOK(string&s, int j, int total, int k)
    {
        count[s[j]-'A']++;
        int maxCount = *max_element(count.begin(), count.end());
        if (total - maxCount <= k)
            return true;
        else
        {
            count[s[j]-'A']--;
            return false;
        }
    }
};


class Solution93 {
public:
    // 2022.8.26, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/424.Longest-Repeating-Character-Replacement/424.Longest-Repeating-Character-Replacement_v2.cpp
    int characterReplacement(string s, int k) 
    {
        vector<int>count(26,0);
        
        int i = 0;        
        int result = 0;
        
        for (int j=0; j<s.size(); j++)
        {
            count[s[j]-'A']++;
            
            while (j-i+1 - *max_element(count.begin(),count.end()) > k)
            {
                count[s[i]-'A']--;
                i++;                       
            }
            result = max(result, j-i+1);                                    
        }
        return result;
    }
};


class Solution92 {
    // 2022.8.26, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/0001-0500/0424-Longest-Repeating-Character-Replacement/cpp-0424/main.cpp
    // Two Pointers
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int characterReplacement(string s, int k) {

        int res = 0;
        for(char c = 'A'; c <= 'Z'; c ++)
            res = max(res, solve(s, k, c));
        return res;
    }

private:
    int solve(const string& s, int k, char c){

        int n = s.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + (s[i] == c);

        int l = 0, r = 0, res = 0;
        while(l <= n){
            if(r + 1 <= n && presum[r + 1] - presum[l] + k >= r + 1 - l)
                r ++, res = max(res, r - l);
            else
                l ++;
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


class Solution91 {
public:
    // 2022.8.27, a copy my code at https://www.educative.io/courses/grokking-the-coding-interview/R8DVgjq78yR
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        // TODO: Write your code here
        int start = 0;
        int maxRepeat = 0;
        unordered_map<char, int> hashTbl;
        for (int end = 0; end < s.size(); end++) {
            hashTbl[s[end]]++;
            maxRepeat = max(maxRepeat, hashTbl[s[end]]);
            if (end - start + 1 - maxRepeat > k) {
                hashTbl[s[start]]--;
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};


class Solution90 {
public:
    // 2022.8.27, a copy official code at https://www.educative.io/courses/grokking-the-coding-interview/R8DVgjq78yR
    static int characterReplacement(const string &str, int k) {
        int windowStart = 0, maxLength = 0, maxRepeatLetterCount = 0;
        unordered_map<char, int> letterFrequencyMap;
        // try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            char rightChar = str[windowEnd];
            letterFrequencyMap[rightChar]++;

            // we don't need to place the maxRepeatLetterCount under the below 'if', see the 
            // explanation in the 'Solution' section above.
            maxRepeatLetterCount = max(maxRepeatLetterCount, letterFrequencyMap[rightChar]);

            // current window size is from windowStart to windowEnd, overall we have a letter which is
            // repeating 'maxRepeatLetterCount' times, this means we can have a window which has one
            // letter repeating 'maxRepeatLetterCount' times and the remaining letters we should replace.
            // if the remaining letters are more than 'k', it is the time to shrink the window as we
            // are not allowed to replace more than 'k' letters
            if (windowEnd - windowStart + 1 - maxRepeatLetterCount > k) {
                char leftChar = str[windowStart];
                letterFrequencyMap[leftChar]--;
                windowStart++;
            }

            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};


class Solution89 {
    public:
        // 2022.9.2, from https://leetcode-solution.cn/book
        int characterReplacement(string s, int k) {
            int res = 0, left = 0, right = 0, size = s.size(), localMaxFreq = 0;

            vector<int> count(26, 0);
            for (; right < size; right++) {
                count[s[right] - 'A'] += 1;
                localMaxFreq = max(localMaxFreq, count[s[right] - 'A']);

                if ((right - left + 1) - localMaxFreq > k) {
                    res = max(res, (right - left));
                    count[s[left] - 'A'] -= 1;
                    left += 1;
                    localMaxFreq = *(max_element(count.begin(), count.end()));
                }
            }

            return max(res, right - left);
        }
};


class Solution {
    public:
        // 2022.9.2, from https://leetcode-solution.cn/book
        int characterReplacement(string s, int k) {
            int res = 0;
            int maxf = 0;
            vector<int> count(26, 0);
            
            for (int i = 0; i < s.size(); i++) {
                count[s[i] - 'A'] += 1;
                maxf = max(maxf, count[s[i] - 'A']);
                
                if (res - maxf < k)
                    res += 1;
                else
                    count[s[i - res] - 'A'] -= 1;
            }

            return res;
        }
};


// @lc code=end

