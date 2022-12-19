/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

/*

https://leetcode.cn/problems/longest-substring-without-repeating-characters/

3. 无重复字符的最长子串
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。


示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
通过次数1,918,929提交次数4,924,329

*/

// @lc code=start
class Solution100 {
public:
    int lengthOfLongestSubstring(string s) {
        // 2022.8.14, from https://www.acwing.com/solution/content/49/
        //  作者：yxc
        //  链接：https://www.acwing.com/solution/content/49/
        //  来源：AcWing
        //  著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
        /*
            算法
            (双指针扫描) O(n)O(n)
            定义两个指针 i,j(i<=j)i,j(i<=j)，表示当前扫描到的子串是 [i,j][i,j] (闭区间)。扫描过程中维护一个哈希表
            unordered_map<char,int> hash，表示 [i,j][i,j]中每个字符出现的次数。线性扫描时，每次循环的流程如下：

            指针 jj 向后移一位, 同时将哈希表中 s[j]s[j] 的计数加一: hash[s[j]]++;
            假设 jj 移动前的区间 [i,j][i,j] 中没有重复字符，则 jj 移动后，只有 s[j]s[j] 可能出现2次。因此我们不断
            向后移动 ii，直至区间 [i,j][i,j]中 s[j]s[j] 的个数等于1为止；
            复杂度分析：由于 i,ji,j 均最多增加n次，且哈希表的插入和更新操作的复杂度都是 O(1)O(1)，因此，总时间复杂度 
            O(n)
        */
        unordered_map<char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j ++ )
        {
            hash[s[j]] ++ ;
            while (hash[s[j]] > 1) hash[s[i ++ ]] -- ;
            res = max(res, j - i + 1);
        }
        return res;
    }
};


class Solution99 {
public:
    // 2022.8.14, from https://github.com/grandyang/leetcode/issues/3
    /*
        这道求最长无重复子串的题和之前那道 Isomorphic Strings 很类似，属于 LeetCode 早期经典题目，博主认为是可以跟 
        Two Sum 媲美的一道题。给了我们一个字符串，让求最长的无重复字符的子串，注意这里是子串，不是子序列，所以必须是连续的。
        先不考虑代码怎么实现，如果给一个例子中的例子 "abcabcbb"，让你手动找无重复字符的子串，该怎么找。博主会一个字符一个
        字符的遍历，比如 a，b，c，然后又出现了一个a，那么此时就应该去掉第一次出现的a，然后继续往后，又出现了一个b，则应该
        去掉一次出现的b，以此类推，最终发现最长的长度为3。所以说，需要记录之前出现过的字符，记录的方式有很多，最常见的是统计
        字符出现的个数，但是这道题字符出现的位置很重要，所以可以使用 HashMap 来建立字符和其出现位置之间的映射。进一步考虑，
        由于字符会重复出现，到底是保存所有出现的位置呢，还是只记录一个位置？我们之前手动推导的方法实际上是维护了一个滑动窗口，
        窗口内的都是没有重复的字符，需要尽可能的扩大窗口的大小。由于窗口在不停向右滑动，所以只关心每个字符最后出现的位置，
        并建立映射。窗口的右边界就是当前遍历到的字符的位置，为了求出窗口的大小，需要一个变量 left 来指向滑动窗口的左边界，
        这样，如果当前遍历到的字符从未出现过，那么直接扩大右边界，如果之前出现过，那么就分两种情况，在或不在滑动窗口内，如果
        不在滑动窗口内，那么就没事，当前字符可以加进来，如果在的话，就需要先在滑动窗口内去掉这个已经出现过的字符了，去掉的
        方法并不需要将左边界 left 一位一位向右遍历查找，由于 HashMap 已经保存了该重复字符最后出现的位置，所以直接移动 
        left 指针就可以了。维护一个结果 res，每次用出现过的窗口大小来更新结果 res，就可以得到最终结果啦。

        这里可以建立一个 HashMap，建立每个字符和其最后出现位置之间的映射，然后需要定义两个变量 res 和 left，其中 res 
        用来记录最长无重复子串的长度，left 指向该无重复子串左边的起始位置的前一个，由于是前一个，所以初始化就是 -1，然后遍历
        整个字符串，对于每一个遍历到的字符，如果该字符已经在 HashMap 中存在了，并且如果其映射值大于 left 的话，那么更新 
        left 为当前映射值。然后映射值更新为当前坐标i，这样保证了 left 始终为当前边界的前一个位置，然后计算窗口长度的时候，
        直接用 i-left 即可，用来更新结果 res。

        这里解释下程序中那个 if 条件语句中的两个条件 m.count(s[i]) && m[s[i]] > left，因为一旦当前字符 s[i] 在 HashMap 
        已经存在映射，说明当前的字符已经出现过了，而若 m[s[i]] > left 成立，说明之前出现过的字符在窗口内，那么如果要加上
        当前这个重复的字符，就要移除之前的那个，所以让 left 赋值为 m[s[i]]，由于 left 是窗口左边界的前一个位置（这也是 
        left 初始化为 -1 的原因，因为窗口左边界是从0开始遍历的），所以相当于已经移除出滑动窗口了。举一个最简单的例子 "aa"，
        当 i=0 时，建立了 a->0 的映射，并且此时结果 res 更新为1，那么当 i=1 的时候，发现a在 HashMap 中，并且映射值0大于 
        left 的 -1，所以此时 left 更新为0，映射对更新为 a->1，那么此时 i-left 还为1，不用更新结果 res，那么最终结果 res 
        还为1，正确，代码如下：
    */
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = -1, n = s.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (m.count(s[i]) && m[s[i]] > left) {
                left = m[s[i]];  
            }
            m[s[i]] = i;
            res = max(res, i - left);            
        }
        return res;
    }
};


class Solution98 {
public:
    // 2022.8.14, from https://github.com/grandyang/leetcode/issues/3
    /*
        下面这种写法是上面解法的精简模式，这里我们可以建立一个 256 位大小的整型数组来代替 HashMap，这样做的原因是 ASCII 
        表共能表示 256 个字符，但是由于键盘只能表示 128 个字符，所以用 128 也行，然后全部初始化为 -1，这样的好处是不用像
        之前的 HashMap 一样要查找当前字符是否存在映射对了，对于每一个遍历到的字符，直接用其在数组中的值来更新 left，因为
        默认是 -1，而 left 初始化也是 -1，所以并不会产生错误，这样就省了 if 判断的步骤，其余思路都一样：
    */
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, -1);
        int res = 0, left = -1;
        for (int i = 0; i < s.size(); ++i) {
            left = max(left, m[s[i]]);
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};


class Solution97 {
public:
    // 2022.8.14, from https://github.com/grandyang/leetcode/issues/3
    /*
        下面这种解法使用了 HashSet，核心算法和上面的很类似，把出现过的字符都放入 HashSet 中，遇到 HashSet 中没有的字符
        就加入 HashSet 中并更新结果 res，如果遇到重复的，则从左边开始删字符，直到删到重复的字符停止：
    */
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = 0, i = 0, n = s.size();
        unordered_set<char> t;
        while (i < n) {
            if (!t.count(s[i])) {
                t.insert(s[i++]);
                res = max(res, (int)t.size());
            }  else {
                t.erase(s[left++]);
            }
        }
        return res;
    }
};


class Solution96 {
public:
    // 2022.8.14, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-substring-without-repeating-characters.cpp
    // Time:  O(n)
    // Space: O(1)
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_map<char, int> lookup;
        for (int left = 0, right = 0; right < s.length(); ++right) {
            if (lookup.count(s[right])) {
                left = max(left, lookup[s[right]] + 1);
            }
            lookup[s[right]] = right;
            result = max(result, right - left + 1);
        }
        return result;
    }
};


class Solution95 {
public:
    // 2022.8.14, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/3.%20Longest%20Substring%20Without%20Repeating%20Characters
    // OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(C) where C is the range of character set
    // Ref: https://discuss.leetcode.com/topic/24739/c-code-in-9-lines
    int lengthOfLongestSubstring(string s) {
        int ans = 0, start = -1;
        vector<int> m(128, -1);
        for (int i = 0; i < s.size(); ++i) {
            start = max(start, m[s[i]]);
            m[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};


class Solution94 {
public:
    // 2022.8.14, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/3.%20Longest%20Substring%20Without%20Repeating%20Characters
    // OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(C)
    // Shrinkable Sliding Window
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, N = s.size(), cnt[128] = {}, dup = 0, ans = 0;
        while (j < N) {
            dup += ++cnt[s[j++]] == 2;
            while (dup) dup -= --cnt[s[i++]] == 1;
            ans = max(ans, j - i);
        }
        return ans;
    }
};



class Solution93 {
public:
    // 2022.8.14, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/3.%20Longest%20Substring%20Without%20Repeating%20Characters
    // OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(C)
    // Non-shrinable Sliding Window
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, N = s.size(), cnt[128] = {}, dup = 0;
        while (j < N) {
            dup += ++cnt[s[j++]] == 2;
            if (dup) dup -= --cnt[s[i++]] == 1;
        }
        return j - i;
    }
};


class Solution92 {
public:
    // 2022.8.14, from https://walkccc.me/LeetCode/problems/0003/
    // Time: O(n)
    // Space: O(128) = O(1)
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        vector<int> count(128);

        for (int l = 0, r = 0; r < s.length(); ++r) {
            ++count[s[r]];
            while (count[s[r]] > 1)
                --count[s[l++]];
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


class Solution91 {
public:
    // 2022.8.14, from https://github.com/wisdompeak/LeetCode/tree/master/Two_Pointers/003.Longest%20Substring%20Without%20Repeating%20Characters
    /*
        对于上述的方法，左指针的前移其实可以跳跃，以加快效率。
        对于Map[s[j]]已经有记录的情况，此时左指针可以调到Map[s[j]]+1的地方。但是注意，这个地方可能还不及i本身，
        所以最终左指针的跳跃应该是max(i,Map[s[j]]+1)
    */
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<int,int>Map;
        int i=0;
        int result = 0;
        for (int j=0; j<s.size(); j++)
        {
            if (Map.find(s[j])!=Map.end())
                i = max(i,Map[s[j]]+1);
            Map[s[j]] = j;            
            result = max(result,j-i+1);
        }
        return result;
    }
};


class Solution90 {
public:
    // 2022.8.14, from https://github.com/wisdompeak/LeetCode/tree/master/Two_Pointers/003.Longest%20Substring%20Without%20Repeating%20Characters
    /*
        双指针的基础题。用vector<int>Map(256,0)来模拟字符的Hash表。
        如果Map[s[j]]==0，移动右指针将Map[s[j]]=1； 否则移动左指针，将Map[s[i]]=0。
    */
    int lengthOfLongestSubstring(string s) 
    {
        vector<int>Map(256,0);
        int i=0;
        int j=0;
        int result=0;
        
        while (j<s.size())
        {
            if (Map[s[j]]==0)
            {
                Map[s[j]]=1;
                j++;
            }
            else if (Map[s[j]]==1)
            {
                Map[s[i]]=0;
                i++;
            }
            
            result = max(result,j-i);
        }
        
        return result;
        
    }
};


/************************************************************************************************************/
/************************************************************************************************************/

/*
    0 ~ 6 months
    Amazon 58
    Bloomberg 25
    Microsoft 23
    Apple 20
    Facebook 15
    Google 13
    Adobe 9
    Spotify 9
    Uber 7
    Goldman Sachs 6
    VMware 5
    Yahoo 4
    Walmart Global Tech 4
    Yandex 4
    Paypal 3
    eBay 3
    Oracle 3
    Zoho 3
    PayTM 3
    tiktok 3
    Cisco 2
    Twitch 2
    Expedia 2
    Intuit 2
    Salesforce 2
    Visa 2
    Qualcomm 2
    Zillow 2
    Docusign 2
    JPMorgan 2
*/

class Solution89 {
public:
    // 2022.8.14, by Hsinan
    int lengthOfLongestSubstring(string s) {
        int maxSize = 0;
        unordered_map<char, int> hashTbl;
        for (int i = 0, j = 0; j < s.size(); j++) {
            hashTbl[s[j]]++;
            while (hashTbl[s[j]] > 1) hashTbl[s[i++]]--;
            maxSize = max(maxSize, j - i + 1);
        }
        return maxSize;
    }
};


class Solution {
public:
    // 2022.8.27, from https://medium.com/leetcode-patterns/leetcode-pattern-2-sliding-windows-for-strings-e19af105316b
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        
        int begin = 0, end = 0;
        int len = 0;
        
        string ans = "";
        
        while(end < s.length()){
            char current = s[end];
            
            if(seen.count(current) == 1 && seen[current] >= begin){
                begin = seen[current] + 1;
            }
            else{
                seen[current] = end;
                end++;            
            }
            
            if(end - begin > len){
                len = end - begin;
                ans = s.substr(begin, end - begin);
            }
        }
        
        return len;
    }
};


// @lc code=end

