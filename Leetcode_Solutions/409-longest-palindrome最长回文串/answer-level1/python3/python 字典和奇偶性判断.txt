### 解题思路
思路官方题解已经说得很清楚了，优化了一下如何解决标记奇数出现的一次的方法
就是用时和内存消耗很大，不知道还有没有优化的办法


### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        dic = {}
        cnt = 0
        flag = False
        for i in s:
            dic[i] = dic.get(i,0)+1  
        for i in dic:
            cnt+= dic[i]//2*2
            if dic[i] % 2 != 0 :
                flag = True   //出现一次奇数flag即标记为True,用boolean判断解决了奇数出现一个的标记
        if flag:
            cnt +=1
        return cnt

```