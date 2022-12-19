![859.jpg](https://pic.leetcode-cn.com/e86f85062e441e6b3f091185b63e595b2d27262ca59367e61ce0b53a5d04eff9-859.jpg)

```
class Solution:
    def buddyStrings(self, a: str, b: str) -> bool:
        count=0
        temp=False

        if len(a)!=len(b):
            return False    #字符串长度不等返回False
        
        elif a==b:
            return len(set(a))!=len(a)  #如果字符串相等则判断字符串中有无相同元素

        for a,b in zip(a,b):
            if a!=b:
                if temp:
                    return False    #temp为True说明已经有两组不相同元素了，有三组就要返回False

                elif count:
                    if a==charA and b==charB:
                        temp=True   #当count为1的时候说明已经有一组不相同元素了

                    else:
                        return False #说明无法通过互换得到，返回False

                else:
                    count=1
                    charA=b
                    charB=a
                    #把这组不同元素记下来

        return temp #temp为True说明正好2组不同元素，为False说明只有1组.
```