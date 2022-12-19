/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

/*

https://leetcode.cn/problems/minimum-window-substring/

76. 最小覆盖子串
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 
t 所有字符的子串，则返回空字符串 "" 。
 

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"

示例 2：

输入：s = "a", t = "a"
输出："a"

示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成
 

进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
通过次数337,063提交次数753,314

*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    2022.8.29
        For sure we need a slidding window with different size, and a hash table to keep tracking the elements in 
        the slidding window, and when the window contains all elements from pattern, get its size and see if the
        string is smallest one. Since we won't know what's the final one, the returned string may keep changing. 

        Solution100 is tricky and hard to understand at first time to read.

        Solution99 is more clear, "先扩展，再收缩，就好像一个窗口一样，先扩大右边界，然后再收缩左边界". 为啥要用 HashMap，而不是 
        HashSet，现在应该很显而易见了吧，因为要统计T串中字母的个数，而不是仅仅看某个字母是否在T串中出现。如果减1后的映射值仍大于等于0，
        说明当前遍历到的字母是T串中的字母，使用一个计数器 cnt，使其自增1。当 cnt 和T串字母个数相等时，说明此时的窗口已经包含了T串中的
        所有字母

        Stop reading different solutions as it's difficult to be able to finish code in short time yet. Leave it
        as TODO now.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @lc code=start
class Solution100 {
public:
    // 2022.8.27, from https://www.acwing.com/solution/content/160/
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/160/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        题目描述
        给定两个字符串：S 和 T，请找到 S 中最短的一段，包含 T 中所有字符。

        注意：

        如果 S 中不存在这样的方案，则返回 ""；
        如果 S 中存在这样的方案，则数据保证答案一定唯一；
        样例
        输入：S = "ADOBECODEBANC", T = "ABC"
        输出："BANC"
        
        算法
        (滑动窗口) O(n)
        首先用哈希表统计出 T 中所有字符出现的次数，哈希表可以用C++中的 unordered_map，不了解用法的同学可以点这里。
        然后我们用两个指针 i,j(i≥j)来扫描整个字符串，同时用一个哈希表统计 i,j之间每种字符出现的次数，
        每次遍历需要的操作如下：

        加入 s[i]，同时更新哈希表；
        检查 s[j] 是否多余，如果是，则移除 s[j]；
        检查当前窗口是否已经满足 T 中所有字符，如果是，则更新答案；
        时间复杂度分析：两个指针都严格递增，最多移动 n 次，所以总时间复杂度是 O(n)
    */
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        int cnt = 0;
        for (auto c : t)
        {
            if (!hash[c]) cnt ++ ;
            hash[c] ++ ;
        }

        string res = "";
        for (int i = 0, j = 0, c = 0; i < s.size(); i ++ )
        {
            if (hash[s[i]] == 1) c ++ ;
            hash[s[i]] -- ;
            while (c == cnt && hash[s[j]] < 0) hash[s[j ++ ]] ++ ;
            if (c == cnt)
            {
                if (res.empty() || res.size() > i - j + 1) res = s.substr(j, i - j + 1);
            }
        }

        return res;
    }
};


class Solution99 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/76
    /*
        这道题给了我们一个原字符串S，还有一个目标字符串T，让在S中找到一个最短的子串，使得其包含了T中的所有的字母，
        并且限制了时间复杂度为 O(n)。这道题的要求是要在 O(n) 的时间度里实现找到这个最小窗口字串，暴力搜索 Brute 
        Force 肯定是不能用的，因为遍历所有的子串的时间复杂度是平方级的。那么来想一下，时间复杂度卡的这么严，说明
        必须在一次遍历中完成任务，当然遍历若干次也是 O(n)，但不一定有这个必要，尝试就一次遍历拿下！那么再来想，
        既然要包含T中所有的字母，那么对于T中的每个字母，肯定要快速查找是否在子串中，既然总时间都卡在了 O(n)，肯定
        不想在这里还浪费时间，就用空间换时间（也就算法题中可以这么干了，七老八十的富翁就算用大别野也换不来时间啊。
        依依东望，望的就是时间呐 T.T），使用 HashMap，建立T中每个字母与其出现次数之间的映射，那么你可能会有疑问，
        为啥不用 HashSet 呢，别急，讲到后面你就知道用 HashMap 有多妙，简直妙不可言～

        目前在脑子一片浆糊的情况下，我们还是从简单的例子来分析吧，题目例子中的S有点长，换个短的 S = "ADBANC"，
        T = "ABC"，那么肉眼遍历一遍S呗，首先第一个是A，嗯很好，T中有，第二个是D，T中没有，不理它，第三个是B，
        嗯很好，T中有，第四个又是A，多了一个，礼多人不怪嘛，收下啦，第五个是N，一边凉快去，第六个终于是C了，那么貌
        似好像需要整个S串，其实不然，注意之前有多一个A，就算去掉第一个A，也没事，因为第四个A可以代替之，第二个D也
        可以去掉，因为不在T串中，第三个B就不能再去掉了，不然就没有B了。所以最终的答案就"BANC"了。通过上面的描述，
        你有没有发现一个有趣的现象，先扩展，再收缩，就好像一个窗口一样，先扩大右边界，然后再收缩左边界，上面的例子
        中右边界无法扩大了后才开始收缩左边界，实际上对于复杂的例子，有可能是扩大右边界，然后缩小一下左边界，然后再
        扩大右边界等等。这就很像一个不停滑动的窗口了，这就是大名鼎鼎的滑动窗口 Sliding Window 了，简直是神器啊，
        能解很多子串，子数组，子序列等等的问题，是必须要熟练掌握的啊！

        下面来考虑用代码来实现，先来回答一下前面埋下的伏笔，为啥要用 HashMap，而不是 HashSet，现在应该很显而易见
        了吧，因为要统计T串中字母的个数，而不是仅仅看某个字母是否在T串中出现。统计好T串中字母的个数了之后，开始遍历
        S串，对于S中的每个遍历到的字母，都在 HashMap 中的映射值减1，如果减1后的映射值仍大于等于0，说明当前遍历到
        的字母是T串中的字母，使用一个计数器 cnt，使其自增1。当 cnt 和T串字母个数相等时，说明此时的窗口已经包含了
        T串中的所有字母，此时更新一个 minLen 和结果 res，这里的 minLen 是一个全局变量，用来记录出现过的包含T串
        所有字母的最短的子串的长度，结果 res 就是这个最短的子串。然后开始收缩左边界，由于遍历的时候，对映射值减了1，
        所以此时去除字母的时候，就要把减去的1加回来，此时如果加1后的值大于0了，说明此时少了一个T中的字母，那么 cnt 
        值就要减1了，然后移动左边界 left。你可能会疑问，对于不在T串中的字母的映射值也这么加呀减呀的，真的大丈夫
        （带胶布）吗？其实没啥事，因为对于不在T串中的字母，减1后，变-1，cnt 不会增加，之后收缩左边界的时候，映射值
        加1后为0，cnt 也不会减少，所以并没有什么影响啦，下面是具体的步骤啦：

        - 先扫描一遍T，把对应的字符及其出现的次数存到 HashMap 中。

        - 然后开始遍历S，就把遍历到的字母对应的 HashMap 中的 value 减一，如果减1后仍大于等于0，cnt 自增1。

        - 如果 cnt 等于T串长度时，开始循环，纪录一个字串并更新最小字串值。然后将子窗口的左边界向右移，如果某个移
          除掉的字母是T串中不可缺少的字母，那么 cnt 自减1，表示此时T串并没有完全匹配。

        解法一：
    */
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++letterCnt[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return res;
    }
};


class Solution98 {
public:
    // 2022.8.27, from https://github.com/grandyang/leetcode/issues/76
    /*
        这道题也可以不用 HashMap，直接用个 int 的数组来代替，因为 ASCII 只有256个字符，所以用个大小为 256 的 int 
        数组即可代替 HashMap，但由于一般输入字母串的字符只有 128 个，所以也可以只用 128，其余部分的思路完全相同，
        虽然只改了一个数据结构，但是运行速度提高了一倍，说明数组还是比 HashMap 快啊。在热心网友 chAngelts 的提醒下，
        还可以进一步的优化，没有必要每次都计算子串，只要有了起始位置和长度，就能唯一的确定一个子串。这里使用一个全局变量 
        minLeft 来记录最终结果子串的起始位置，初始化为 -1，最终配合上 minLen，就可以得到最终结果了。注意在返回的时候
        要检测一下若 minLeft 仍为初始值 -1，需返回空串，参见代码如下：

        解法二：
    */
    string minWindow(string s, string t) {
        vector<int> letterCnt(128, 0);
        int left = 0, cnt = 0, minLeft = -1, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    minLeft = left;
                }
                if (++letterCnt[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return minLeft == -1 ? "" : s.substr(minLeft, minLen);
    }
};


class Solution97 {
public:
    // 2022.8.27, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/minimum-window-substring.cpp
    // Time:  O(n)
    // Space: O(k)
    string minWindow(string s, string t) {
        unordered_map<int, int> count;
        for (const auto& c : t) {
            ++count[c];
        }
        int remain = t.length();
        int left = -1, right = -1;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            remain -= count[s[j]]-- > 0;
            if (remain) {
                continue;
            }
            while (count[s[i]] < 0) {
                ++count[s[i++]];
            }
            if (right == -1 || j - i + 1 < right - left + 1) {
                left = i;
                right = j;
            }
        }
        return left >= 0 ? s.substr(left, right - left + 1) : "";
    }
};


class Solution96 {
public:
    // 2022.8.27, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/minimum-window-substring.cpp
    // Time:  O(n)
    // Space: O(k)
    string minWindow(string s, string t) {
        if (s.empty() || s.length() < t.length()) {
            return "";
        }

        const int ASCII_MAX = 256;
        vector<int> exp_cnt(ASCII_MAX, 0);
        vector<int> cur_cnt(ASCII_MAX, 0);

        int cnt = 0;
        int start = 0;
        int min_start = 0;
        int min_width = numeric_limits<int>::max();

        for (const auto& c : t) {
            ++exp_cnt[c];
        }

        for (int i = 0; i < s.length(); ++i) {
            if (exp_cnt[s[i]] > 0) {
                ++cur_cnt[s[i]];
                if (cur_cnt[s[i]] <= exp_cnt[s[i]]) {  // Counting expected elements.
                    ++cnt;
                }
            }
            if (cnt == t.size()) {  // If window meets the requirement.
                while (exp_cnt[s[start]] == 0 ||  // Adjust left bound of window.
                       cur_cnt[s[start]] > exp_cnt[s[start]]) {
                    --cur_cnt[s[start]];
                    ++start;
                }

                if (min_width > i - start + 1) {  // Update minimum window.
                    min_width = i - start + 1;
                    min_start = start;
                }
            }
        }

        if (min_width == numeric_limits<int>::max()) {
            return "";
        }

        return s.substr(min_start, min_width);
    }
};


class Solution95 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/76.%20Minimum%20Window%20Substring
    // OJ: https://leetcode.com/problems/minimum-window-substring/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(C) where C is the range of characters
    // Solution 1. Minimum Sliding Window
    string minWindow(string s, string t) {
        unordered_map<char, int> target, cnt;
        int len = INT_MAX, i = 0, N = s.size(), matched = 0, begin = 0;
        for (char c : t) target[c]++;
        for (int j = 0; j < N; ++j) {
            if (++cnt[s[j]] <= target[s[j]]) ++matched;
            while (matched == t.size()) {
                if (j - i + 1 < len) {
                    len = j - i + 1;
                    begin = i;
                }
                if (--cnt[s[i]] < target[s[i]]) --matched;
                ++i;
            }
        }
        return len == INT_MAX ? "" : s.substr(begin, len);
    }
};


class Solution94 {
public:
    // 2022.8.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/76.%20Minimum%20Window%20Substring
    // OJ: https://leetcode.com/problems/minimum-window-substring/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(C) where C is the range of characters
    // Ref: https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems
    // Solution 2. Shrinkable Slinding Window
    string minWindow(string s, string t) {
        int cnt[128] = {};
        for (char c : t) cnt[c]++;
        int N = s.size(), i = 0, j = 0, start = -1, minLen = INT_MAX, matched = 0;
        while (j < N) {
            matched += --cnt[s[j++]] >= 0;
            while (matched == t.size()) {
                if (j - i < minLen) minLen = j - i, start = i;
                matched -= ++cnt[s[i++]] > 0;
            }
        }
        return start == -1 ? "" : s.substr(start, minLen);
    }
};


class Solution93 {
public:
    // 2022.8.27, from https://walkccc.me/LeetCode/problems/0076/
    // Time: O(∣s∣+∣t∣)
    // Space: O(128)=O(1)
    string minWindow(string s, string t) {
        vector<int> count(128);
        int required = t.length();
        int bestLeft = -1;
        int minLength = s.length() + 1;

        for (const char c : t)
        ++count[c];

        for (int l = 0, r = 0; r < s.length(); ++r) {
            if (--count[s[r]] >= 0)
                --required;
            while (required == 0) {
                if (r - l + 1 < minLength) {
                    bestLeft = l;
                    minLength = r - l + 1;
                }
                if (++count[s[l++]] > 0)
                    ++required;
            }
        }

        return bestLeft == -1 ? "" : s.substr(bestLeft, minLength);
    }
};


class Solution92 {
public:
    // 2022.8.27, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/076.Minimum-Window-Substring/076.Minimum-Window-Substring.cpp
    /*
        76. Minimum-Window-Substring
        典型的双指针题型。

        对于每个新加入的元素s[j]，首先更新该字符出现次数的Map[s[i]]++。如果更新后，Map[s[i]]等于需要出现的次数
        Table[s[i]]，则计数器count++，说明有一个字符满足了出现次数的要求．

        当count等于t中的字符类型数COUNT时，说明任务已经实现。此时，让左指针不断右移，相应的Map[s[i]]就要自减，
        一旦Map[s[i] < Table[s[i]]，则count需要自减1从而不再满足COUNT，说明需要继续加入新元素才能满足任务. 
        从而j才可以右移继续遍历。

        在这个过程中如果满足条件count==COUNT，都需要不断更新和记录结果。
    */
    string minWindow(string s, string t) 
    {
        unordered_map<char,int>Table;
        for (int i=0; i<t.size(); i++)
            Table[t[i]]++;
        int M = Table.size();
        
        unordered_map<char,int>Map;
        int i=0;
        int Len = INT_MAX;
        string result;
        int count = 0;
        for (int j=0; j<s.size(); j++)
        {
            Map[s[j]]++;
            if (Map[s[j]]==Table[s[j]])
                count++;
            while (count==M)
            {
                if (Len>j-i+1)
                {
                    Len = j-i+1;
                    result = s.substr(i,Len);
                }
                Map[s[i]]--;
                if (Map[s[i]]==Table[s[i]]-1)
                    count--;
                i++;
            }
        }
        return result;
    }
};


class Solution91 {
public:
    // 2022.8.27, from https://www.guozet.me/leetcode/Leetcode-76-Minimum-Window-Substring

    string minWindow(string s, string t) {
        vector<int> r(128, 0);
        string ans;
        for (char& c : t) ++r[c];
        int left = 0, cnt = 0, n = t.length(), diff = INT_MAX;
        for (int right = 0; right < s.size(); ++right) {
        if (--r[s[right]] >= 0) cnt++;
        while (cnt == n) {
            if (diff > right - left + 1) {
            diff = right - left + 1;
            ans = s.substr(left, diff);
            }
            if (++r[s[left]] > 0) --cnt;
            ++left;
        }
        }
        return ans;
    }
};


class Solution90 {
public:
    // 2022.8.27, from https://ke.algomooc.com/detail/v_62bd711ee4b0a51feef9895d/3?from=p_6243bcc1e4b04e8d90291891&type=8&parent_pro_id=p_62b96d90e4b00a4f371ee3ad
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 最小覆盖子串（LeetCode 76）：https://leetcode.cn/problems/minimum-window-substring/
    string minWindow(string s, string t) {
        // 使用整型数组来表示每个字符在 t 中的数量，初始化都为 0，利用 ASCII 码的方式把字符存储到整型数组中
        // 数组的长度设置为 128
        // 其中 65 ～ 90 号为 26 个大写英文字母，97 ～ 122 号为 26 个小写英文字母，其余为一些标点符号、运算符号等
        // 由于 t 是由英文字母组成，所以数组中有些位置的值始终不会被操作，造成了空间的浪费，比如 map[20]map[30]
        // 但这样做方便理解，比如看到 map[98] = 5 ，能知道 b 出现的频次是 5 次
        vector<int> map(128, 0);

        // 开始统计 t 中每个字符出现的频次
        for (auto& c : t){
            // 对于数组类型，其下标为 int 类型
            // 可以直接使用 char 类型变量，默认强制转换，存储的就是字母对应的 ASCII 码
            // 比如 t.[i) = 'a'，存储的就是 map[97]
            map[c]++;
        }

        // 记录滑动窗口的长度，并且不断更新获取最小的那个
        int windowLength = s.length() + 1;

        // 滑动窗口的左端
        int left = 0;

        // 滑动窗口的右端
        int right = 0;

        // t 中字符的总个数
        int count = t.length();

        // 滑动窗口左端新的位置
        int start = 0;

        // 滑动窗口的右端开始移动
        while (right < s.length()) {

            // 获取此时将要加入到滑动窗口的元素
            auto c = s[right];

            // 如果说 map 数组中 c 出现的频次大于了 0，说明此时字符 c 加入到滑动窗口距离找到这样一个子串更近了一步
            // 那么滑动窗口需要搜罗的特定元素个数变少了
            if (map[c] > 0) {
                // 需要搜罗的和 t 中字符一样的元素个数变少了
                count--;
            }

            // 既然滑动窗口中新增了一个字符 c，那么 map 数组中对应的频次就需要减 1
            map[c]--;

            // System.out.println( c + " : " + map[c]);


            // 如果此时 count == 0 ，表明滑动窗口中包含了 t 中全部的字符
            // 此时，找到了一个符合条件的子串
            // 但想尝试一下，能否满足条件的情况下子串更短一些
            // 于是，去尝试把滑动窗口的左端向右移动一下
            // 可以移动的前提是，滑动窗口的左端元素抛弃后剩下的元素依旧满足条件
            // 意思就是实际上左端元素是多余的
            // 而如果这个元素对应的值在 map[] 数组中小于 0，说明它是一个多余元素
            // 反复的删除这些多余的元素
            while(count == 0){

                // 如果当前的这个窗口值比之前维护的窗口值更小，需要进行更新
                if (right - left + 1 < windowLength) {

                    // 更新滑动窗口的长度
                    windowLength = right - left + 1;

                    // 更新滑动窗口起始位置，来到了 left 这个位置
                    start = left;
                }

                // 接下来左端位置开始向右移动，也就是一个删除操作
                // 删除操作需要执行以下三个步骤
                // 如果这个元素不是多余的元素，比如滑动窗口为 ADBC，t 为 ABC
                // 移除了 A，那么滑动窗口又需要去新增其它的元素了
                // 所以通过 map[s.[left)] == 0 来判断它是否是多余的元素
                if( map[s[left]] == 0){
                    // 需要搜罗的和 t 中字符一样的元素个数要增加一个了，因为删除了关键元素
                    count++;
                }
                
                // 2、这个元素离开了滑动窗口，那么在 map 中这个的值就需要加 1
                // 对应着上面新增一个元素到滑动窗口，map[c]--
                map[s[left]]++;

                // 3、left 向右移动，那么这个元素就离开了
                left++;

            }

            // 可以开始查看新的元素了
            right++;

        }

        // 根据 s 中是否涵盖了 t 所有字符的子串来获取结果
        return windowLength == s.length() + 1 ? "" : s.substr(start, windowLength);

    }
};


class Solution89 {
public:
    // 2022.8.27, from https://medium.com/leetcode-patterns/leetcode-pattern-2-sliding-windows-for-strings-e19af105316b
    /*
        note : this first problem has been brutally analyzed as this is a tricky concept and forms the basis to 
        solve the next 5. Master this one and try the rest on your own, that would be the best way to learn.

        In the previous example the window was of a fixed size, but here we use a window of variable size determined 
        by begin and end markers. A brute force approach would be to iterate through all possible substrings and 
        determine the minimum window which contains all characters of T. How do you see if a substring has all 
        characters of T ? You could use the frequency table of T which stores character to number of occurrences as 
        follows :

        # initialize frequency table
        for char c in T do 
            table[c]++;
        end
        counter = table.size()                 # unique chars in T
        for char c in string B do
            if(char c in table){ 
                table[c]--;                    # decrement count for c
                if(table[c] == 0) counter--;
            }
        end
        if(counter == 0){ # B has every character in T }

        So we are basically assuring that every unique character in T exists in B as many times as it exists in T 
        by maintaining a counter. It is fine if there are 4 ‘K’s in T and B has 7 ‘K’s , the table count for ‘K’ would 
        simply go negative, but it goes to 0 at some point before that, proving string B has at least 4 'K’s in it, 
        satisfying the need with respect to “K”, extending the logic to other chars in T if counter = 0, B has all 
        chars in T.

        Okay so coming to the sliding window part here, we keep sliding end to the right examining each new character 
        and updating the count in table. As soon as we hit counter = 0, it means we have a valid answer so we try to 
        trim it down removing the unessential characters from the start by sliding begin right. We constantly keep 
        trying to validate / invalidate the string by manipulating counter and table counts.

        Take a moment, understand this code. Walk through it on paper for this example : [ S : ADOBECODEBANC | T :"ABC" ] . 
        Do not worry, the code is just heavily annotated, it is actually very concise.

        Intuition : the best substring for the answer would simply be a permutation of T if such a substring exists 
        in S, but otherwise we could have wasteful characters sitting in between the essential characters that make 
        the substring valid as an answer. Our attempt here is to remove such chars without losing the necessary ones. 
        After trimming down as much as possible we resume with sliding end right and repeating the whole process.

        Whenever counter = 0 we have a valid candidate for our ans, but we update ans only if it is shorter than previously 
        recorded minimum length ans.
    */ 
    string minWindow(string s, string t) {
        unordered_map<char, int> table;
        
        // initialize frequency table for t
        for(char c : t){
            table[c]++;
        }
        
        // initialize sliding window
        int begin = 0, end = 0;
        int counter = table.size();
        int len = INT_MAX;
        
        string ans = "";
        
        // start sliding window
        while(end < s.length()){
            char endchar = s[end];
            
            // if current char found in table, decrement count
            if(table.find(endchar) != table.end()){
                table[endchar]--;
                if(table[endchar] == 0) counter--;
            }
            
            end++;
            
            // if counter == 0, means we found an answer, now try to trim that window by sliding begin to right.
            while(counter == 0){
                // store new answer if smaller than previously best
                if(end-begin < len){
                    len = end - begin;
                    ans = s.substr(begin, end - begin); 
                }
                
                // begin char could be in table or not, 
                // if not then good for us, it was a wasteful char and we shortened the previously found substring.
                
                // if found in table increment count in table, as we are leaving it out of window and moving ahead, 
                // so it would no longer be a part of the substring marked by begin-end window
                // table only has count of chars required to make the present substring a valid candidate
                // if the count goes above zero means that the current window is missing one char to be an answer candidate
                int startchar = s[begin];
                
                if(table.count(startchar) == 1){
                   table[startchar]++;
                   if(table[startchar] > 0) counter++; 
                }
                
                begin++;
            }
        }
        
        return ans;
    }
};


class Solution88 {
public:
    // 2022.8.28, from https://leetcode-solution.cn/book
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0 || t.size() > s.size())
            return "";

        vector<int> remaining(128, 0);
        int required = t.size();

        for (int i = 0; i < required; i++)
            remaining[t[i]]++;

        int min = INT_MAX, start = 0, left = 0, i = 0;
        while (i <= s.size() && start < s.size()) {
            if (required) {
                if (i == s.size())
                    break;
                remaining[s[i]]--;
                if (remaining[s[i]] >= 0)
                    required--;
                i++;
            } else {
                if (i - start < min) {
                    min = i - start;
                    left = start;
                }
                remaining[s[start]]++;
                if (remaining[s[start]] > 0)
                    required++;
                start++;
            }
        }
        return min == INT_MAX ? "" : s.substr(left, min);
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


class Solution87 {
public:
    // 2022.9.3, from https://labuladong.github.io/algo/1/12/
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;
        // 记录最小覆盖子串的起始索引及长度
        int start = 0, len = INT_MAX;
        while (right < s.size()) {
            // c 是将移入窗口的字符
            char c = s[right];
            // 扩大窗口
            right++;
            // 进行窗口内数据的一系列更新
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }

            // 判断左侧窗口是否要收缩
            while (valid == need.size()) {
                // 在这里更新最小覆盖子串
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                // d 是将移出窗口的字符
                char d = s[left];
                // 缩小窗口
                left++;
                // 进行窗口内数据的一系列更新
                if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                }                    
            }
        }
        // 返回最小覆盖子串
        return len == INT_MAX ?
            "" : s.substr(start, len);
    }
};


class Solution {
public:
    // 2022.9.3, from https://www.educative.io/courses/grokking-the-coding-interview/xoyL4q6ApNE
    string minWindow(string &str, string &pattern) {
        int windowStart = 0, matched = 0, minLength = str.length() + 1, subStrStart = 0;
        unordered_map<char, int> charFrequencyMap;

        // build up hash table for pattern first
        for (auto chr : pattern) {
            charFrequencyMap[chr]++;
        }

        // try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            char rightChar = str[windowEnd];

            // if given character existed in pattern hash table
            if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) {
                charFrequencyMap[rightChar]--;
                if (charFrequencyMap[rightChar] >= 0) {  // count every matching of a character
                    matched++;
                }
            }

            // shrink the window if we can, finish as soon as we remove a matched character
            while (matched == pattern.length()) {
                if (minLength > windowEnd - windowStart + 1) {
                    minLength = windowEnd - windowStart + 1;
                    subStrStart = windowStart;
                }

                char leftChar = str[windowStart++];
                if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) {
                    // note that we could have redundant matching characters, therefore we'll decrement the
                    // matched count only when a useful occurrence of a matched character is going out of the
                    // window
                    if (charFrequencyMap[leftChar] == 0) {
                        matched--;
                    }
                    charFrequencyMap[leftChar]++;
                }
            }
        }

        return minLength > str.length() ? "" : str.substr(subStrStart, minLength);
    }
};


// @lc code=end

