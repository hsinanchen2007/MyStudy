先贴代码
```
class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        res = []
        for i in queries:
            k = 0
            flag = True
            for j in i:
                if k == len(pattern):
                    if j.islower():
                        continue
                    else:
                        flag = False
                        break
                if j == pattern[k]:
                    k += 1
                    continue
                else:
                    if j.islower():
                        continue
                    else:
                        flag=False
                        break
            if k < len(pattern):
                flag = False
            res.append(flag)
        return res
```

字符串匹配问题本质上都可以看成是一种状态机问题，而状态的数目通常根据模式串来定，每个模式串的一个字符作为一个状态，当匹配到该字符的时候进入下一个状态，以FoBaT为例具体如图所示（画的比较丑，见谅）：
![1580740709(1).jpg](https://pic.leetcode-cn.com/fab43a3bd118728ed02697bfb7de0e2fb09a0e50dae39fbac1204296e58d4546-1580740709\(1\).jpg)

按理说一般有一个开始状态，这里可以有也可以不需要，直接把第一个字母的状态作为开始状态即可，结束状态有两种，成功和失败，向下一种状态前进肯定是遇到了当前字母，而因为相邻字母之间只能填小写字母，因此指向自己状态都是来小写字母，而来非当前字母的大写字母因为加不进去，直接失败


**但是，还有一种情况可能失败**，那就是在结束时没有处于成功状态也算失败，因此按这个思路就可以写出上面的状态机代码，k代表当前处于第几个状态，也即第k-1个字符
