### 解题思路
思路:
1.创建两个列表,L记录生成的子串,L_len记录子串的长度.
2.遍历S,如果不在L列表中,就添加进去.如果在列表中,就删除该值(含)之前的所有数,然后把这个新数添加到尾部,每一次判断之后都向L_len列表中添加L的长度(极大优化空间,困了).
3.用max函数获得L_len列表中的最大值.

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s):
        if len(s) == 0:
            return 0
        elif len(s) == 1:
            return 1
        else:
            L = []
            L_len = []
            a = len(s)
            for x in range(0,a):
                if s[x] not in L:
                    L.append(s[x])
                else:
                    for i in range(0,L.index(s[x])+1):
                        L.remove(L[0])
                    L.append(s[x])
                L_len.append(len(L))
            return max(L_len)


                
```