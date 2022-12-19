/*

https://leetcode.cn/problems/longest-substring-with-at-most-two-distinct-characters/

159. 至多包含两个不同字符的最长子串
给你一个字符串 s ，请你找出 至多 包含 两个不同字符 的最长子串，并返回该子串的长度。
 

示例 1：

输入：s = "eceba"
输出：3
解释：满足题目要求的子串是 "ece" ，长度为 3 。

示例 2：

输入：s = "ccaabbb"
输出：5
解释：满足题目要求的子串是 "aabbb" ，长度为 5 。
 

提示：

1 <= s.length <= 105
s 由英文字母组成
通过次数25,920提交次数46,434

*/

class Solution100 {
public:
    // 2022.8.27, by Hsinan
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0;
        int maxSize = 0;
        unordered_map<char, int> hashTbl;
        for (int end = 0; end < s.size(); end++) {
            hashTbl[s[end]]++;
            while (hashTbl.size() > 2) {
                // take out from start
                hashTbl[s[start]]--;
                if (hashTbl[s[start]] == 0) {
                    hashTbl.erase(s[start]);
                }
                start++;
            }
            maxSize = max(maxSize, end - start + 1);
        }
        return maxSize;
    }
};


class Solution99 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/159
    /*
        这道题给我们一个字符串，让求最多有两个不同字符的最长子串。那么首先想到的是用 HashMap 来做，HashMap 
        记录每个字符的出现次数，然后如果 HashMap 中的映射数量超过两个的时候，这里需要删掉一个映射，比如此时 
        HashMap 中e有2个，c有1个，此时把b也存入了 HashMap，那么就有三对映射了，这时 left 是0，先从e开始，
        映射值减1，此时e还有1个，不删除，left 自增1。这时 HashMap 里还有三对映射，此时 left 是1，那么到
        c了，映射值减1，此时e映射为0，将e从 HashMap 中删除，left 自增1，然后更新结果为 i - left + 1，
        以此类推直至遍历完整个字符串，参见代码如下：

        解法一：
    */
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
            while (m.size() > 2) {
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
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/159
    /*
        我们除了用 HashMap 来映射字符出现的个数，还可以映射每个字符最新的坐标，比如题目中的例子 "eceba"，
        遇到第一个e，映射其坐标0，遇到c，映射其坐标1，遇到第二个e时，映射其坐标2，当遇到b时，映射其坐标3，
        每次都判断当前 HashMap 中的映射数，如果大于2的时候，那么需要删掉一个映射，还是从 left=0 时开始向
        右找，看每个字符在 HashMap 中的映射值是否等于当前坐标 left，比如第一个e，HashMap 此时映射值为2，
        不等于 left 的0，那么 left 自增1，遇到c的时候，HashMap 中c的映射值是1，和此时的 left 相同，
        那么我们把c删掉，left 自增1，再更新结果，以此类推直至遍历完整个字符串，参见代码如下：

        解法二：
    */
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]] = i;
            while (m.size() > 2) {
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
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/159
    /*
        后来又在网上看到了一种解法，这种解法是维护一个 sliding window，指针 left 指向起始位置，right 
        指向 window 的最后一个位置，用于定位 left 的下一个跳转位置，思路如下：

        1. 若当前字符和前一个字符相同，继续循环。

        2. 若不同，看当前字符和 right 指的字符是否相同

            (1) 若相同，left 不变，右边跳到 i - 1

            (2) 若不同，更新结果，left 变为 right+1，right 变为 i - 1

        最后需要注意在循环结束后，还要比较结果 res 和 s.size() - left 的大小，返回大的，这是由于如果字符串是 
        "ecebaaa"，那么当 left=3 时，i=5,6 的时候，都是继续循环，当i加到7时，跳出了循环，而此时正确答案应为 
        "baaa" 这4个字符，而我们的结果 res 只更新到了 "ece" 这3个字符，所以最后要判断 s.size() - left 和
        结果 res 的大小。

        另外需要说明的是这种解法仅适用于于不同字符数为2个的情况，如果为k个的话，还是需要用上面两种解法。

        解法三：
    */
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0, right = -1, res = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) continue;
            if (right >= 0 && s[right] != s[i]) {
                res = max(res, i - left);
                left = right + 1;
            }
            right = i - 1;
        }
        return max(s.size() - left, res);
    }
};


class Solution96 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/159
    /*
        还有一种不使用 HashMap 的解法，是在做 Fruit Into Baskets 这道题的时候在论坛上看到的，其实这两道题除了
        背景设定之外没有任何的区别，代码基本上都可以拷来直接用的。这里使用若干的变量，其中 cur 为当前最长子串的长度，
        first 和 second 为当前候选子串中的两个不同的字符，cntLast 为 second 字符的连续长度。遍历所有字符，假如
        遇到的字符是 first 和 second 中的任意一个，那么 cur 可以自增1，否则 cntLast 自增1，因为若是新字符的话，
        默认已经将 first 字符淘汰了，此时候选字符串由 second 字符和这个新字符构成，所以当前长度是 cntLast+1。
        然后再来更新 cntLast，假如当前字符等于 second 的话，cntLast 自增1，否则均重置为1，因为 cntLast 统计的
        就是 second 字符的连续长度。然后再来判断若当前字符不等于 second，则此时 first 赋值为 second， second 
        赋值为新字符。最后不要忘了用 cur 来更新结果 res，参见代码如下：

        解法四：
    */
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, cur = 0, cntLast = 0;
        char first, second;
        for (char c : s) {
            cur = (c == first || c == second) ? cur + 1 : cntLast + 1;
            cntLast = (c == second) ? cntLast + 1 : 1;
            if (c != second) {
                first = second; second = c;
            }
            res = max(res, cur);
        }
        return res;
    }
};


class Solution95 {
public:
    // 2022.8.27, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-substring-with-at-most-two-distinct-characters.cpp
    // Time:  O(n)
    // Space: O(1)
    int lengthOfLongestSubstringTwoDistinct(string s) {
        const int k = 2;
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



class Solution94 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/159.%20Longest%20Substring%20with%20At%20Most%20Two%20Distinct%20Characters
    // OJ: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(C) 
    // Shrinkable Sliding Window:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> m(128, 0);
        int i = 0, j = 0, ans = 0, cnt = 0;
        while (j < s.size()) {
            if (m[s[j++]]++ == 0) ++cnt;
            while (cnt > 2) {
                if (m[s[i++]]-- == 1) --cnt;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};


class Solution93 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/159.%20Longest%20Substring%20with%20At%20Most%20Two%20Distinct%20Characters
    // OJ: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(C)
    // Non-shrinkable Sliding Window:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int distinct = 0, cnt[128] = {}, N = s.size(), i = 0, j = 0;
        while (j < N) {
            distinct += ++cnt[s[j++]] == 1;
            if (distinct > 2) distinct -= --cnt[s[i++]] == 0;
        }
        return j - i;
    }
};


class Solution92 {
public:
    // 2022.8.27, from https://walkccc.me/LeetCode/problems/0159/
    // Time: O(n)
    // Space: O(128)=O(1)
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = 0;
        int distinct = 0;
        vector<int> count(128);

        for (int l = 0, r = 0; r < s.length(); ++r) {
        if (++count[s[r]] == 1)
            ++distinct;
        while (distinct == 3)
            if (--count[s[l++]] == 0)
            --distinct;
        ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


class Solution91 {
public:
    // 2022.8.27, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/159.Longest-Substring-with-At-Most-Two-Distinct-Characters/159.%20Longest%20Substring%20with%20At%20Most%20Two%20Distinct%20Characters.cpp
    /*
        159. Longest-Substring-with-At-Most-Two-Distinct Characters
        需要一个记录每种字符出现次数的映射，这里为了加快效率，我们不用Map，而是直接用一个数组 vectorMap(128,0)，
        用字符的ascii码作为index，注意需要开辟至少256个空间才能装下所有字母字符。

        另外还需要一个计数器count还记载目前指针范围内有几种字符。

        按照个人的习惯，最外层用for循环来遍历j。然后分情况讨论：

        Map[s[j]]>0，说明s[j]已经被合法收录，故可继续往后遍历j。
        Map[s[j]]==0 && count<2，说明s[j]可以被合法收录，故可继续往后遍历j。
        Map[s[j]]==0 && count==2，说明i~j已经包含两种字符了，故需要不断退s[i]直至count<2。注意此时仍要收录s[j]。 
        在每种情况下，i~j都是包含两种字符的合法子串，故都要update一下result。
    */
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        vector<int>Map(256,0);
        int count=0;
        int result=0;
        int i=0;
        int j=0;
        
        for (int j=0; j<s.size(); j++)
        {
            if (Map[s[j]]>0)
            {
                Map[s[j]]++;
            }                
            else if (Map[s[j]]==0 && count<2)
            {
                Map[s[j]]++;
                count++;
            }
            else if (Map[s[j]]==0 && count==2)
            {
                while (count==2)
                {
                    Map[s[i]]--;
                    if (Map[s[i]]==0)
                        count--;
                    i++;
                }                    
                Map[s[j]]++;
                count++;
            }
            
            result=max(result,j-i+1);            
        }
        
        return result;
    }
};


class Solution90 {
public:
    // 2022.8.27, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/0001-0500/0159-Longest-Substring-with-At-Most-Two-Distinct-Characters/cpp-0159/main1.cpp
    // Two Pointers + HashMap
    // Recording how many different characters in the current string by map.
    //
    // Time Complexity:  O(n)
    // Space Complexity: O(1)
    int lengthOfLongestSubstringTwoDistinct(string s) {

        unordered_map<char, int> map;
        int l = 0, r = 0;
        int res = 0;
        while(r <= s.size()){
            if(r == s.size() || (map.size() == 2 && map.find(s[r]) == map.end())){
                res = max(res, r-l);
                while(map.size() >= 2){
                    if(map[s[l]] == 1)
                        map.erase(s[l]);
                    else
                        map[s[l]] --;
                    l ++;
                }

                if( r == s.size() )
                    break;
            }
            else{
                if(map.find(s[r]) == map.end())
                    map[s[r]] = 1;
                else
                    map[s[r]] += 1;
                r ++;
            }
        }

        return res;
    }
};


class Solution89 {
public:
    // 2022.8.27, from https://github.com/liuyubobobo/Play-Leetcode/blob/master/0001-0500/0159-Longest-Substring-with-At-Most-Two-Distinct-Characters/cpp-0159/main2.cpp
    // Two Pointers + Static Array as HashMap
    // Using self-built hashtable to record how many different characters in the current string
    //
    // Time Complexity:  O(n)
    // Space Complexity: O(1)
    int lengthOfLongestSubstringTwoDistinct(string s) {

        int hashtable[256] = {0};
        int l = 0, r = 0;
        int res = 0;
        int count = 0;
        while(r <= s.size()){
            if(r == s.size() || (count == 2 && !hashtable[s[r]])){
                res = max(res, r-l);
                while(count >= 2){
                    hashtable[s[l]] --;
                    if(hashtable[s[l]] == 0)
                        count --;
                    l ++;
                }

                if(r == s.size())
                    break;
            }
            else{
                hashtable[s[r]] ++;
                if(hashtable[s[r]] == 1)
                    count ++;
                r ++;
            }
        }

        return res;
    }
};


class Solution {
public:
    // 2022.8.27, from https://medium.com/leetcode-patterns/leetcode-pattern-2-sliding-windows-for-strings-e19af105316b
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.length() == 0) return 0;
        
        unordered_map<char, int> table;
        int begin = 0, end = 0, len = 0, counter = 0;
        
        while(end < s.length()){
            char current = s[end];
            
            table[current]++;
            if(table[current] == 1) counter++;
            
            end++;
            
            while(counter > 2){
                char startchar = s[begin];
                
                if(table.count(startchar) == 1){
                    table[startchar]--;
                    if(table[startchar] == 0) counter--;
                }
                
                begin++;
            }
            
            len = max(len, end - begin);
        }
        
         return len;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/

