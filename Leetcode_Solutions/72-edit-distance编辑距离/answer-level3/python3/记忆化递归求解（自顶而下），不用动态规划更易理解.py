从两个单词的最后一个字母开始比较，一样的话就比较前面的字母，不一样的话就采用总步数最少的操作
```
from functools import lru_cache
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        @lru_cache(None)
        def dp(i,j):
            if i<0:     #word1已经没有字母，删除word2多出的字母
                return j+1
            elif j<0:   #word2已经没有字母，删除word1多出的字母
                return i+1
            elif word1[i]==word2[j]:    #两个字母一样的话不用操作，比较之前的字母
                return dp(i-1,j-1)
            else:   #不一致的情况下采用总步数最少的操作
                return min(
                    dp(i,j-1)+1,    #插入
                    dp(i-1,j)+1,    #删除
                    dp(i-1,j-1)+1   #替换
                )
        i=len(word1)-1
        j=len(word2)-1
        return dp(i,j)
```
