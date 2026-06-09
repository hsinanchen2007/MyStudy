动态规划 + 哈希
这道题不少人一开始想到的是：求回文嘛，双指针一首一尾判断是否相等然后不断往中间移动
但是，第一个坑出现了——"hunu" [0,3,1]，“为什么hunu只变一个字符就能成回文？不应该啊！”，
先看清题目：子串是允许重新排列顺序的。。。
好既然如此，那自然想到的是：那我就求待求子串各个字符出现的次数，如果是双数，恭喜，自然成对，
如果是单数呢？那就要找另一个一样落单的字符，然后把其中一半变成另一半的样子，如果找不到另一个呢？
那说明该字符站在C位，无需配对了，思路很清晰，每个待求子串各字符的数量用哈希表吧，运行几个用例完美！
提交，超时！一看第29个用例，一个奇长无比的字串，一组深不见底的待求子串。。。
为什么会超时呢？因为每次都去临时待求子串每个字符的出现次数（哈希表保存），其实这里面有大量的重复运算，
所以要先预处理，可以把字串到某个字符为止所出现的字符计数先保存下来，这样的好处是后面要求某个子串的字符分布情况时
只要把结束行减去起始行就好了，不用每次再临时遍历建哈希表，大大加快了速度*

```
举个例子就好理解了, abcda这个字串：
   a b c d
空 0 0 0 0 
a  1 0 0 0
b  1 1 0 0
c  1 1 1 0
d  1 1 1 1
a  2 1 1 1
第0行，前0个(空串)自然每个字符都只出现0次
第1行，前1个(也就是a)，a出现1次，其他字符出现0次
第5行，前5个(abcda)，a出现了2次，bcd字符各出现1次
下面假如要求子串bcd，那就用d那行减去a那行(刨去a保留b)
*/
class Solution {
public:
    inline bool IsPailWord(vector<vector<int>>& dp, int l, int r, int k)
    {
        int n = r - l + 1;
        int oddCnt = 0;
        for (int i = 0; i < 26; ++i) {
            /*dp第0行是预留给空字串情况的，所以s字串的第r个字符在dp里是第r + 1行*/
            if ((dp[r + 1][i] - dp[l][i]) % 2 != 0) {
                oddCnt++;
                if (oddCnt == 2) {
                    --k;/*每2个落单的字符消耗1次变化机会(改变其中1个字符即可)*/
                    oddCnt = 0;
                }
            }

            if (k < 0)//变化次数已超过给的机会会，已无法形成回文
                return false;
        }

        return true;
    }

    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries)
    {
        int n = s.size();
        int m = queries.size();
        vector<bool> ans;
        /*第0行是预留给空字串的情况，所以要多加1行*/
        vector<vector<int>> dp(n + 1, vector(26, 0));
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i];
            dp[i + 1][s[i] - 'a']++;
        }

        for (int i = 0; i < m; ++i) {
            bool subAns = false;
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            subAns = IsPailWord(dp, l, r, k);
            ans.push_back(subAns);
        }

        return ans;
    }
};
```
