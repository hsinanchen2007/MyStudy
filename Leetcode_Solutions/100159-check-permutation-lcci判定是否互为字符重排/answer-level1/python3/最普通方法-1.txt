### 解题思路
1 确定区间都是闭区间
2 去重
我这个是本方法，继续挖掘好的方法


### 代码

```python
class Solution(object):
    def CheckPermutation(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        info  =list(s1)
        print(len(info))
        if  0 <= len(s1) <=100:
            if  0 <= len(s2) <=100:
                for i in s2:
                    if i in info:
                        info.remove(i)
                        continue
                    else:
                        return False

                return True
            else:
                return False
        else:
            return False
```