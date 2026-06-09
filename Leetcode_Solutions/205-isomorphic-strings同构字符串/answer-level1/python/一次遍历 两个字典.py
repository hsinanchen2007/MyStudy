### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        preindexs=dict() #dict[char]=i: s中的char字符上一次出现的下表是i
        preindext=dict()
        for i in range(len(s)):
            sc=s[i]
            tc=t[i]
            #获取上此出现位置
            scindex=preindexs.get(sc,i)
            tcindex=preindext.get(tc,i)
            #如果上此出现位置不同 False
            if scindex!=tcindex:
                return False
            #更新字典
            preindexs[sc]=i
            preindext[tc]=i
        return True
```