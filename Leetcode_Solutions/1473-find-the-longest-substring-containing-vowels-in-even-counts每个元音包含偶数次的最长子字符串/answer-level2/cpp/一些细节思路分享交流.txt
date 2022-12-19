这道题当天晚上没写出来，思路是有，想到了是用状态压缩，但是想复杂了，代码也出现各种bug，不知道为啥越学越菜，嗨~。
这里跟各位大佬交流一下早上理清的一些思路：
- 首先看一下数据量`1 <= s.length <= 5 x 10^5`，只有小写字母而且只有元音字母才会影响答案的正确性，感觉数据量蛮大的，可以考虑离散化
- 利用一个`int`类型的后五位记录元音字母的奇偶状态：比如`leetcode`可以表示为`01010b`
- 昨天晚上只考虑了前一个状态加上当前的元音字母，没有考虑用前缀和相减的方法：我们从下标`0`开始记录元音字母的状态，则子字符串`(i, j)`的状态就可以由`(0, j) ^ (0, i)`获得（这里需要想想，只有奇数减奇数或者偶数减偶数才能得到偶数对吧，也就是需要两个状态位相同才为0，这与异或操作不谋而合）
- 我们需要找到与当前状态“相减”得到元音字母次数全为偶数的状态，也就是异或结果为0，然后只有自己与自己异或才为0，也就是我们需要找到之前出现过这种状态的位置
- 这道题还需要一些其他的细节，我在代码的注释中解释
```
class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<char, int> chPos = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        vector<int> pivotPos;
        // 记录离散化后的坐标
        pivotPos.push_back(-1);
        int n = s.size();
        int ans = 0, state = 0, prepos = -1;
        for (int pos = 0; pos < n; ++pos) {
            if (chPos.count(s[pos])) {
                pivotPos.push_back(pos);
                ans = max(ans, pos - prepos - 1);
                // 这里记录所有不含元音字母的子字符串的长度
                prepos = pos;
            }
        }
        ans = max(ans, n - prepos - 1);
        // 最后一段不含元音字母的子字符串
        pivotPos.push_back(n);
        int m = pivotPos.size();
        map<int, int> cache;
        cache[0] = 0;
        for (int pos = 1; pos < m - 1; ++pos) {
            state = state ^ (1 << chPos[s[pivotPos[pos]]]);
            // state记录[0, pos]的子字符串的状态
            if (cache.count(state)) {
                ans = max(ans, pivotPos[pos + 1] - pivotPos[cache[state]] - 1);
            }
            else
                cache[state] = pos;
        }
        return ans;
    }
};
```
对于`ans = max(ans, pivotPos[pos + 1] - pivotPos[cache[state]] - 1);`
我们除了考虑元音字母外，希望获得更多的辅音字母，即下图中我希望获得更多的空格，所以拿后面一个元音字母出现的位置来跟`cache[state]`相减。
![5337. 每个元音包含偶数次的最长子字符串.PNG](https://pic.leetcode-cn.com/8d5feb7b17e4bd7e50b65417a929cc36068326ed5be71bd655fbd7237240a105-5337.%20%E6%AF%8F%E4%B8%AA%E5%85%83%E9%9F%B3%E5%8C%85%E5%90%AB%E5%81%B6%E6%95%B0%E6%AC%A1%E7%9A%84%E6%9C%80%E9%95%BF%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.PNG)
同时，加入`-1, n`到坐标中也是出于这种考虑


