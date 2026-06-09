## 编辑距离
> 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
> 你可以对一个单词进行如下三种操作：
> 插入一个字符
> 删除一个字符
> 替换一个字符

```
输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
```


思路借鉴了一位评论区的大佬，这里直接引用，对于过程，进行了逐步推导
看到这道题，我们很自然知道有3个选择，可以替换、删除或者增加字符。但是怎么利用呢？
我们可以把大问题拆分为小问题，即**面对word1的前i个要变为word2的前j个字符时**，我们需要消耗多少步呢？
1. **替换的情况**：当word1中的前i-1个就可以变换为word2中的前j-1个，那么我们只要根据word1中的第i个是否等于word2中的第j个字符进行判断，如果相等，那么`cost[i][j]=cost[i-1][j-1];`否则，`cost[i][j]=cost[i-1][j-1]+1`,加的1就是我们将word1中第i个字符替换为word2中第j个的消耗。
2. **删除的情况**：当word1中的前i-1个就可以变换为word2中的前j个时，我们需要将word1中的第i个字符删除，`cost[i][j]=cost[i-1][j]+1`
3. **增加的情况**：当word1中的前i个可以变换为word2中的前j-1个时，我们需要将word1中的第i个字符后面增加一个，`cost[i][j]=cost[i][j-1]+1` 
4. 所以，我们的cost[i][j]取上列的**最小值**即可。

ps:注意，我们的cost数组索引均是从1开始，而word中索引是0开始的，所以`word1[i-1] == word2[j-1]`，就是在判断我们word1中的第i个字符是否等于word2中第j个字符。

为了直观的让大家感受一下，我对于题目中word1：horse，word2：ros的案例，进行了展示：

![1.png](https://pic.leetcode-cn.com/5f5a0cb2854f8f47158052587a79486fc00df2da7540a48360425c9598be9d3f-1.png)

所以，我们上代码：

```
class Solution {
public:
    int minDistance(string word1, string word2) {
        // 对于每个状态下，都有三种选择，替换、删除、插入

        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> cost(m+1, vector<int>(n+1,0));

        // 必须具有0->0 ，消耗为0，这里索引是从1开始的。
        // word1:1..m  ; word2:1..n
        for(int i=0;i<=m;i++){
            cost[i][0] = i;// word2是0，那么word1中的i个要全部删除
        }
        for(int j=0;j<=n;j++){
            cost[0][j] = j;// word1是0，那么word1增加每一个word2的字符个数j
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int min_ = 1999;
                if(word1[i-1] == word2[j-1]){
                    // 因为i和j是从1开始计数，对于word索引要-1
                    min_ = cost[i-1][j-1];
                }
                min_ = min(min_, cost[i-1][j-1]+1);// i替换j
                min_ = min(min_, cost[i-1][j]+1);// 删除i
                cost[i][j] = min(min_, cost[i][j-1]+1);// 增加
            }
        }
        return cost[m][n];
    }
};
```
