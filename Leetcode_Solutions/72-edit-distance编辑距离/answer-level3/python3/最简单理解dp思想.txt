```
'''
LeetCode 72 编辑距离
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

题目大意：
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
示例 1:
输入: word1 = "horse", word2 = "ros"
输出: 3
解释:
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2:
输入: word1 = "intention", word2 = "execution"
输出: 5
解释:
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')

解题思路：
哈哈，我的老本行算法题目，这道题是少有的可以用在实际的算法，用于OCR基于词典进行识别，也即是从库中找编辑距离最近的word
编辑距离也可以一种我最少修改几次可以和给定word一样，相当于一种相似度度量
你直接按照我的方法理解，超级easy，直接上代码
1，状态定义dp[i][j]表示word1的前i个单词，转化至word2的前j个单词，需要的编辑次数
2，边界看代码里注释
3，状态转移看注释
'''
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1=len(word1)
        n2=len(word2)
        dp=[[0]*(n2+1) for _ in range(n1+1)] #
        for i in range(n2+1): # 边界，word1前0个单词转化至word2的前i个单词，其实就是添加i个呀
            dp[0][i]=i
        for i in range(n1+1): # 同上
            dp[i][0]=i
        for i in range(1,n1+1):
            for j in range(1,n2+1):
                if(word1[i-1]==word2[j-1]): # 如果word前面一个字母一样，就是全部一样喽，所以直接等于上一个状态
                    dp[i][j]=dp[i-1][j-1] # 你是不是想问为什么前一个字母相同了怎么就都一样，因为状态转移只考虑上一状态，dp核心哦
                else:
                    dp[i][j]=min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1 # 不一样，就从前面状态最小的选一个+1次
        return dp[-1][-1]

if __name__ == '__main__':
    # begin
    s = Solution()
    # word1 = "horse"
    # word2 = "ros"
    word1 = "intention"
    word2 = "intention"
    print (s.minDistance(word1, word2))
```
