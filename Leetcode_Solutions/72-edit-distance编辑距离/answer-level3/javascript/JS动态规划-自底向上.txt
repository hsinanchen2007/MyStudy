### 解题思路
1. 解题目的：将word1转化成word2的最小操作次数(最小编辑距离)。
2. dp，i，j的含义：
- i：表示word1的第i位
- j：表示word2的第j位
- dp[i][j]：表示截至到word1[i]和word2[j]两字符时，两串的最小编辑距离，依赖这个值，计算下一状态。
3. 动态规划的关键点：
    1.初始状态：要找准初始状态，初始状态相当于程序的出口。
    2.下一步的状态依赖于上一步的结果。
4. 状态公式：
    - 两串新增的字符相等，则dp[i+1][j+1] = dp[i][j]，即
        ```
        if(word1[i] === word2[j]) dp[i][j] = dp[i-1][j-1]
        ```
    - 将word1转化为word2与将word2转化为word1结果是一样的，`插入`/`删除`操作的值都是1，只是操作相反而已。固定一个字符串作为修改的主体即可，即：
    ```
        当word2更长时，从word1插入：dp[i][j] = dp[i][j-1] + 1
        当word1更长时，从word1删除：dp[i][j] = dp[i-1][j] + 1
    ```
    - 当两串长度相同，但新增字符不同时，替换即可 
    ``` dp[i][j] = dp[i-1][j-1] + 1```
    
### 代码

```javascript
/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    let n = word1.length;
    let m = word2.length;
    let dp = [];
    
    /*  如："horse" "ros"
        由于字符串与数组索引都是从0开始的，而字符串的直接量没有索引0，所以在二维数组的首位添0，相当于字符串首位为一个空字符""：
        好处1：更符合字符串的输入习惯,后续流程的索引不必再-1
        好处2：不必再单独考虑边界情况，如：输入"a","b"，或"","a"
    */
    //将初始化状态与状态转移两步骤合并
    for(let i = 0;i <= n;i++){//注意n与m不要写反了
        dp.push([])
        for(let j = 0;j <= m;j++){
            if(i*j){
                dp[i][j] = word1[i-1] == word2[j-1]? dp[i-1][j-1]: (Math.min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1);
            }else{
                dp[i][j] = i + j;
            }
        }
    }
    return dp[n][m];
    
};
```