![image.png](https://pic.leetcode-cn.com/2d58ebe78bc286dd6f996459c2f835b7888370b7f6be43e4a52ac700936ccbe8-image.png)
一次过，开心。

```
class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        #写一个字典
        dic={}
        #计数到字典里去
        for i in arr:
            if i in dic:
                dic[i]=dic[i]+1
            else:
                dic[i]=1
        #转换成set，看key的长度和value的长度是否一样
        return len(set(dic))==len(set(dic.values()))
```
