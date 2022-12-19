第 152 次周赛第四题，比赛时没做出来，看了一下第一名大佬的代码，%%%，同时分享下思路。

首先看这道题，最普通的思路是对每个 `puzzle`，都对 `words` 遍历一遍，方法很直观，但一定超时。`words.length * puzzles.length` 会达到 $10^9$。

---

那么问题主要是，用怎么样的一种方法可以大大缩短时间？

其实我们可以发现一些规律和 **题目给我们的暗示**：
1. 对于 word，其实每个 word 代表了一种模式，abc 和 aaaaabbbccc 是等价的。 我们需要提取出这种模式(位运算)
2. 对于一个 puzzle，有两种遍历谜底的思路。 一是遍历 words，另一种是遍历自己的模式子集。题目给我们的暗示是 `puzzles[i].length == 7`。这就意味着一个 puzzle 的模式，子集不会超过 $2^7$，$2^7=128$，因此我们遍历 puzzle 模式的子集，采用 map 映射的方式统计谜底个数。


**那么，如何将一个字符串转化为他所对应的模式?** 这就可以巧妙地用到位运算，字母只有26个，因此可以很轻松的将每个字符串转化为一个 int 型数据。同样，每个 puzzle 字符串也可以转化为这样的模式。

**接下来的问题是，如何遍历 puzzle 模式的子集?**
大佬用了一种极其巧妙的方式。 (其中k为一个 puzzle 的模式数)
`for (int j = k; j; j = (j - 1)&k) {}`

这样遍历的数值就是，比如 $k = 0101$，也就是 $5$，那么遍历的数据会是 $0101$，$0100$，$0001$，遍历出了它的子集，然后判断这些子集是否字谜条件，如果满足，就做和。 

当然，这道题的这个思路也可以不用位运算来实现，但位运算使得算法(或者说代码)优美了很多。

分析时间复杂度，我们知道 puzzle 的子集个数不到 $128$ 个，因此把他作为常数的话，此算法的 **时间复杂度为 $O(n\ log\ n)$**。$n$ 为 `max(words.length, puzzles.length)`


```cpp [-C++]
class Solution {
public:
    vector<int> ans;  // 存储答案
    map<int, int> bit2cnt;  // "字符串word转化为一个数(位运算): 该模式出现的次数"  的映射
        
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        // 统计每个word模式的数量, map形式保存, 位运算进行操作
        for (int i = 0; i < words.size(); ++i) {
            int k = 0;
            for (int j = 0; j < words[i].size(); ++j) {
                k |= (1 << (words[i][j] - 'a'));
            }
            bit2cnt[k] += 1;
        }
        
        for (int i = 0; i < puzzles.size(); ++i) {
            ans.push_back(0);
            int k = 0;
            for (int j = 0; j < puzzles[i].size(); ++j) {  // 将puzzles的字符串转化为一个 数字
                k |= (1 << (puzzles[i][j] - 'a'));
            }
            for (int j = k; j; j = (j - 1)&k) {  // 遍历 该数字 出现1 的子集, 比如0101 遍历到 0101, 0100, 0001. 再判断首字母.
                if ((1 << (puzzles[i][0] - 'a')) & j) ans[i] += bit2cnt[j];
            }
        }
        return ans;
    }
};
```
