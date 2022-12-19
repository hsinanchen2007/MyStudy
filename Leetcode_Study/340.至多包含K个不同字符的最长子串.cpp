/*

https://leetcode.cn/problems/longest-substring-with-at-most-k-distinct-characters/

340. 至多包含 K 个不同字符的最长子串
给你一个字符串 s 和一个整数 k ，请你找出 至多 包含 k 个 不同 字符的最长子串，并返回该子串的长度。
 

示例 1：

输入：s = "eceba", k = 2
输出：3
解释：满足题目要求的子串是 "ece" ，长度为 3 。
示例 2：

输入：s = "aa", k = 1
输出：2
解释：满足题目要求的子串是 "aa" ，长度为 2 。
 

提示：

1 <= s.length <= 5 * 104
0 <= k <= 50
通过次数20,849提交次数41,008

*/

class Solution100 {
public:
    // 2022.8.20, by Hsinan
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> hashTbl;
        int start = 0;
        int size = numeric_limits<int>::min();
        for (int end = 0; end < s.size(); end++) {
            hashTbl[s[end]]++;
            while (hashTbl.size() > k) {
                hashTbl[s[start]]--;
                if (hashTbl[s[start]] == 0) {
                    hashTbl.erase(s[start]);
                }
                start++;
            }
            size = std::max(size, end - start + 1);
        }
        return size;
    }
};


class Solution99 {
public:
    // 2022.8.20, from https://github.com/grandyang/leetcode/issues/340
    /*
        这道题是之前那道Longest Substring with At Most Two Distinct Characters的拓展，
        而且那道题中的解法一和解法二直接将2换成k就行了，具体讲解请参考之前那篇博客：
    */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
            while (m.size() > k) {
                if (--m[s[left]] == 0) m.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};


class Solution98 {
public:
    // 2022.8.20, from https://github.com/grandyang/leetcode/issues/340
    /*
        具体讲解请参考之前那篇博客Longest Substring with At Most Two Distinct Characters，
        参见代码如下：
    */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]] = i;
            while (m.size() > k) {
                if (m[s[left]] == left) m.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};


class Solution97 {
public:
    // 2022.8.20, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-substring-with-at-most-k-distinct-characters.cpp
    // Time:  O(n)
    // Space: O(1)
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int longest = 0, start = 0, distinct_count = 0;
        array<int, 256> visited = {0};
        for (int i = 0; i < s.length(); ++i) {
            if (visited[s[i]] == 0) {
                ++distinct_count;
            }
            ++visited[s[i]];
            while (distinct_count > k) {
                --visited[s[start]];
                if (visited[s[start]] == 0) {
                    --distinct_count;
                }
                ++start;
            }
            longest = max(longest, i - start + 1);
        }
        return longest;
    }
};


class Solution96 {
public:
    // 2022.8.20, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/340.%20Longest%20Substring%20with%20At%20Most%20K%20Distinct%20Characters
    // OJ: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int cnt[128] = {}, distinct = 0, i = 0, j = 0, ans = 0, N = s.size();
        while (j < N) {
            distinct += cnt[s[j++]]++ == 0;
            while (distinct > k) distinct -= --cnt[s[i++]] == 0;
            ans = max(ans, j - i);
        }
        return ans;
    }
};


class Solution95 {
public:
    // 2022.8.20, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/340.%20Longest%20Substring%20with%20At%20Most%20K%20Distinct%20Characters
    // OJ: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int cnt[128] = {}, distinct = 0, i = 0, j = 0, N = s.size();
        while (j < N) {
            distinct += cnt[s[j++]]++ == 0;
            if (distinct > k) distinct -= --cnt[s[i++]] == 0;
        }
        return j - i;
    }
};


class Solution94 {
public:
    // 2022.8.20, from https://walkccc.me/LeetCode/problems/0340/
    // Time: O(n)
    // Space: O(128) = O(1)
    // Approach 1: Sliding Window
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;
        int distinct = 0;
        vector<int> count(128);

        for (int l = 0, r = 0; r < s.length(); ++r) {
        if (++count[s[r]] == 1)
            ++distinct;
        while (distinct == k + 1)
            if (--count[s[l++]] == 0)
            --distinct;
        ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


class Solution93 {
public:
    // 2022.8.20, from https://walkccc.me/LeetCode/problems/0340/
    // Time: O(nlogk)
    // Space: O(n)
    // Approach 2: Ordered Map
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;
        map<int, char> lastSeen;          // {last index: char}
        unordered_map<char, int> window;  // {char: index}

        for (int l = 0, r = 0; r < s.length(); ++r) {
        const int inChar = s[r];
        if (window.count(inChar))
            lastSeen.erase(window[inChar]);
        lastSeen[r] = inChar;
        window[inChar] = r;
        if (window.size() > k) {
            const auto [lastIndex, outChar] = *begin(lastSeen);
            lastSeen.erase(begin(lastSeen));
            window.erase(outChar);
            l = lastIndex + 1;
        }
        ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


class Solution92 {
public:
    // 2022.8.20, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/340.Longest-Substring-with-At-Most-K-Distinct-Characters/340.Longest-Substring-with-At-Most-K-Distinct-Characters_v1.cpp
    /*
        解法1：固定左边界，探索右边界(开区间)
                for (int i=0; i<n; i++)
                {
                    while (j<n && count + (freq[s[j]]+1 == 1) <= k)
                    {
                        freq[s[j]]++;
                        count += (freq[s[j]] == 1);
                        j++;
                    }
                    ret = max(ret, j-i);
                    
                    freq[s[i]]--;
                    count -= (freq[s[i]] == 0);
                }
    */
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        vector<int>freq(256,0);
        int n = s.size();
        int j = 0;
        int ret = 0;
        int count = 0;
        for (int i=0; i<n; i++)
        {
            while (j<n && count + (freq[s[j]]+1 == 1) <= k)
            {
                freq[s[j]]++;
                count += (freq[s[j]] == 1);
                j++;
            }
            ret = max(ret, j-i);
            
            freq[s[i]]--;
            count -= (freq[s[i]] == 0);
        }
        return ret;        
    }
};


class Solution91 {
public:
    // 2022.8.20, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/340.Longest-Substring-with-At-Most-K-Distinct-Characters/340.Longest-Substring-with-At-Most-K-Distinct-Characters_v2.cpp
    /*
        解法2：固定右边界，探索左边界(闭区间)
                for (int j=0; j<s.size(); j++)
                {                        
                    freq[s[j]]++;
                    if (freq[s[j]]==1) count++;
                    
                    while (count>k)
                    {
                        freq[s[i]]--;
                        if (freq[s[i]]==0)
                            count--;
                        i++;
                    }
                    ret = max(ret, j-i+1);            
                }
    */
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        vector<int>freq(256,0);
        int count = 0;
        int i = 0;
        int ret = 0;
        for (int j=0; j<s.size(); j++)
        {                        
            freq[s[j]]++;
            if (freq[s[j]]==1) count++;
            
            while (count>k)
            {
                freq[s[i]]--;
                if (freq[s[i]]==0)
                    count--;
                i++;
            }
            ret = max(ret, j-i+1);            
        }
        return ret;        
    }
};


// Longest Substring with At Most K Distinct Characters
class Solution90 {
public:
    // 2022.8.20, from https://github.com/MaskRay/LeetCode/blob/master/longest-substring-with-at-most-k-distinct-characters.cc
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int c[127] = {}, x = 0, r = 0;
        for (int j = 0, i = 0; i < s.size(); i++) {
        x += ! c[s[i]]++;
        while (x > k)
            x -= ! --c[s[j++]];
        r = max(r, i-j+1);
        }
        return r;
    }
};


class Solution {
public:
    // 2022.8.20, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/0001-0500/0340-Longest-Substring-with-At-Most-K-Distinct-Characters/cpp-0340/main2.cpp
    // Sliding Window (Another implement version)
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int lengthOfLongestSubstringKDistinct(string s, int k) {

        if(!k) return 0;

        int l = 0, r = -1, res = 0;
        unordered_map<char, int> freq;
        while(r + 1 < s.size()){

            if(freq.size() < k || freq.count(s[r + 1]))
                freq[s[r + 1]] ++, r ++;
            else{
                freq[s[l]] --;
                if(freq[s[l]] == 0) freq.erase(s[l]);
                l ++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/



