### 解题思路
一般来说，处理两个字符串的动态规划问题，都是按本文的思路处理，建立 DP table。为什么呢，因为易于找出状态转移的关系，比如编辑距离的 DP table：
----labuladong
### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        #参考学习:https://github.com/labuladong/fucking-algorithm/blob/master/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E7%B3%BB%E5%88%97/%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.md
        #操作4种: 插入,删除,替换,Skip.
        #base case: s变成t:
        #   pointer_s先到头:把pointer_t及剩下的insert;
        #   pointer_t先到头: 把pointer_s及剩下的del.
        # if s1[i] == s2[j]:
        #     啥都别做（skip）
        #     i, j 同时向前移动
        # else:
        #     三选一：
        #         插入（insert）
        #         删除（delete）
        #         替换（replace） 
        if not word1: return len(word2)#一路插入
        if not word2: return len(word1)#一路删除

        dp = [[0]*(len(word2)+1) for _ in range(len(word1)+1)]
        #print(dp)
        #base case:
        for i in range(len(dp)):
            dp[i][0] = i #从目标到空字符,一路删除
        for j in range(len(dp[0])):
            dp[0][j] = j #从空字符到目标,一路增加
        for i in range(1,len(dp)):
            for j in range(1,len(dp[0])):
                if word1[i-1] == word2[j-1]:# Skip跳过
                    dp[i][j] = dp[i-1][j-1]
                    #print("%s==>%s"%(word1[i-1],word2[j-1]),"Skip")
                else:
                    deletes = dp[i-1][j]
                    inserts = dp[i][j-1]
                    replaces = dp[i-1][j-1]
                    dp[i][j] = min(deletes,inserts,replaces)+1
                    # if dp[i][j] == deletes:
                    #     print("%s==>%s"%(word1[i-1],word2[j-1]),"deletes")
                    # if dp[i][j] == inserts:
                    #     print("%s==>%s"%(word1[i-1],word2[j-1]),"inserts")
                    # if dp[i][j] == replaces:
                    #     print("%s==>%s"%(word1[i-1],word2[j-1]),"replaces")
                    #未完成:将变量名转化为同名字符串
                    # for choice in [deletes, inserts, replaces]:
                    #     if dp[i][j] == choice:
                    #         print("%s==>%s"%(word1[i-1],word2[j-1]),????)

        #for d in dp:
        #    print(d)
        #打印步骤:(从最后一步开始:)
        i = len(dp)-1
        j = len(dp[0])-1
        while i >0 and j >0:
            skip = dp[i-1][j-1]
            deletes = dp[i-1][j]+1
            inserts = dp[i][j-1]+1
            replaces = dp[i-1][j-1]+1
            print("第%d步:"%dp[i][j])
            if dp[i][j] == deletes:
                print("%s==>%s"%(word1[i-1],word2[j-1]),"deletes",word1[i-1])
                i = i -1
                j = j

            if dp[i][j] == inserts:
                print("%s==>%s"%(word1[i-1],word2[j-1]),"inserts",word2[j-1])
                i = i
                j = j - 1

            if dp[i][j] == replaces:
                print("%s==>%s"%(word1[i-1],word2[j-1]),"replaces")
                i = i -1
                j = j -1

            if dp[i][j] == skip:
                print("%s==>%s"%(word1[i-1],word2[j-1]),"skips")
                i = i -1
                j = j -1
            #未完成:将变量名转化为同名字符串
            # for choice in [deletes, inserts, replaces]:
            #     if dp[i][j] == choice:
            #         print("%s==>%s"%(word1[i-1],word2[j-1]),????)

        return dp[-1][-1]
        
```