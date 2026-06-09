
![image.png](https://pic.leetcode-cn.com/b200b975702bbc1719d1e5555dae9ba20a666425624a03e4963f66114d21f2b7-image.png)

### 解题思路
本题解致力于通过一个实际例子来说明动态规划算法和暴力算法的区别，受众人群为大概了解暴力算法和动态规划算法的思路，但没有完全想明白的同学。主要参考: [参考题解](https://leetcode-cn.com/problems/word-break/solution/dong-tai-gui-hua-cban-ben-by-hu-lu-wa-wa-2/)，例子为自己所想。

先上代码：（和参考题解的一样）
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty()) 
            return false;        
        
        int size = s.size();
        int dp[size + 1];
        fill_n(dp, size + 1, 0);

        dp[0] = 1;
        for (int i = 0; i <= size; ++i) {
            for(const auto &word: wordDict) {
                int ws = word.size();
                if (i - ws >= 0) {  // 单词长度不超过开头
                    int mat = s.compare(i - ws, ws, word); 
                    if (mat == 0 && dp[i - ws] == 1)  // s[i - ws] ~ s[i-1]匹配成功，且s[i-ws]之前也匹配成功
                        dp[i] = 1;
                }
            }
        }
        return dp[size];
    }
};
```


**状态数组的意义：**

dp[i]：表示位置i之前的字符串是否可以进行单词拆分（1可以，0不行）。

举例：
- s = catsand 
- wordDict = ["cat", "cats", "and"] 

| c | a | t | s | a | n | d | |
|--|--|--|--|--|--|--|--|
|1| 0 | 0 | 1 | 1 | 0 | 0 | 1 |

- c前面是空字符，故可以成功拆分，为1
- s前面为cat，在wordDict中，故可以成功拆分，为1
- a前面为cats，在wordDict中，故可以成功拆分，为1
- 最后一个位置前面的字符串可以拆分为cats和and，为1

**算法的过程：**（对应代码）
1. 创建一个s.size()+1的数组用于保存状态，由于位置0前面是空字符，故dp[0] = 1
2. 遍历每一个字符s[i]，如果以s[i-1]为结尾的字符串在末尾成功匹配了一个单词w（该单词的长度为ws），且dp[i-ws]==1（字符s[i-ws]前的字符串可以成功进行单词划分），则dp[i]=1（即当前字符串可以成功进行单词划分）。（注意，只有在i-某个单词长度>=0时才进行单词匹配）
    - a和t对应下标为1，2，而最短单词长度为3，均不能进行单词匹配
    - s和a前分别匹配了cat和cats
    - n和d处，没有以a和n结尾的单词，匹配失败
    - 最后一个位置，成功匹配and，且dp[i-3]==1，即a前面字符串成功匹配，故dp[最后一个位置]=1，即整个字符串可以成功匹配

---

**动态规划相比暴力算法的优化在哪里？**

答：**动态规划算法，每个位置成功匹配之后，不会再次匹配。**

比如上面的例子，若使用暴力算法：

- catsand成功匹配cat之后，继续对剩余的字符串sand进行处理，发现sand无法继续匹配，于是又回到第一个位置，匹配单词cats，于是，第一个位置进行了两次匹配。

若使用动态规划算法：

- 会分别在s和a处匹配cat和cats，均只会匹配一次