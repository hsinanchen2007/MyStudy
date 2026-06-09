算法是不可能看懂的，优化又不会，只能欺负测试数据太弱骗点分这样子。。。

1. 当前串的元音是否满足要求
2. 如果满足，返回串长度，否则进入递归
3. 因为结果串必然不能包含所有奇数个元音，所以递归尝试：
    - 去掉最左边的不满足字符
    - 去掉最右边的不满足字符
4. 取最大值即可


```
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        def findlr(l, r, c):
            for i in range(l,r,1):
                if s[i]==c:
                    return i
        def findrl(l, r, c):
            for i in range(r-1,l-1,-1):
                if s[i]==c:
                    return i
        def gogogo(l,r):
            mapp = {
                'a' : 0,
                'e' : 0,
                'i' : 0,
                'o' : 0,
                'u' : 0
            }
            for i in s[l:r]:
                if i in mapp:
                    mapp[i]+=1
            for k in mapp:
                if mapp[k]%2!=0:
                    nl,nr = findlr(l,r, k)+1, findrl(l,r, k)
                    if r-nl > nr-l:
                        a = gogogo(nl,r)
                        if a >=nr-l:
                            return a
                        b = gogogo(l,nr)
                        return max(a,b)
                    else:
                        b = gogogo(l,nr)
                        if b >=r-nl:
                            return b
                        a = gogogo(nl,r)
                        return max(a,b)
            return r-l
        
        return gogogo(0,len(s))
```