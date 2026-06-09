### 解题思路
1. 先判断首字母是否相同
2. 若相同，则判断余下来的字符是否全部相同
3. 若不同，则 j += 1


我的实现还是太慢了， 这里 如果 needle 数组较长，needle[1:m] == haystack[j+1:m+j] 太过于耗费时间了。
可能是直接判断到某一个不同时，直接终止。没必要全部都比一遍。

参考官方题解： 有空学 KMP 算法， Hash 表

官方题解 2 看上去用了回溯，实际上并不是技巧，仍然相当于把 haystack 的指针往后移动一位，然后从头开始匹配。

官方题解 3 Rabin Karp - 常数复杂度 没太看懂。

把代码1 中的连续判断自己来写，发现了一堆 bug. 

+ 1. 首先 python 的 for 循环变量永远不会超出
+ 2. 需要剪枝，当 haystack 剩下的子串长度不够时，不用进行判断，直接退出。若无此，可能超时。
+ 3. 若无上面剪枝，在判断 needle[i] = haystack[i+j] 时，可能 i+j 下标会溢出。 


### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        m, n = len(needle), len(haystack)
        if m == 0:
            return 0
        
        j = 0
        while j<n:
            if needle[0] == haystack[j]:
                # if needle[1:m-1] == haystack[j+1:m-j-1]: 
                # bug 在这里，'hello','ll' j=2, n[1:1] = None == h[3:-1]= 'l'不成立，
                # 所以 j += 1, 两个都是 None, 返回 3
                if needle[1:m] == haystack[j+1:m+j]: #如果C++ 未实现此，这里可以抽象成一个子函数
                    return j
                else: 
                    j += 1
            else:
                j += 1
        return -1
         
```

### 代码2
``` python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        m, n = len(needle), len(haystack)
        if m == 0:
            return 0
        
        j = 0
        
        while j+m-1<n:   #bug 不加此可能特殊样例会过不去
            if needle[0] == haystack[j]:
                # 匹配接下来的 need[1:]
                le = 1
                for i in range(1, m):
                    if (j+i) <n and needle[i] == haystack[j+i]:  # bug j+i 溢出了
                        le += 1
                    else:
                        break
                # if i == m:   # for 是不可以这么用，不管是否在最后一个 break, i 恒为 m-1
                if le == m:
                    return j
                else:
                    j += 1
            else:
                j += 1
        return -1
```         