### 解题思路
因为要考虑后续挑战，怎么去优化后续去判断大量输入，第一个想到的是把长字符串存储为字典，字典的键为26个小写字母，值为这个字母在长字符串中的位置的列表。第一次判断的时间复杂度应为2n，第一次n建立字典，第二次n遍历位置数组，第二次的时间开销最差的情况应该是长数组的长度。比如长数组长度为10万，短数组长度为10，需要遍历10万次。代码写的比较难看，而且没有优化。

后来看到某位同学用的矩阵，第二次遍历时间复杂度貌似可以大大降低。同样长数组假定为10万，短数组假定为10，只需要遍历26*10=260次，时间大大缩短，空间复杂度为26倍，不知道我理解的对不对。

请各位大神指点。

![1.png](https://pic.leetcode-cn.com/0166b372f4c3a41a17cfd6f749e4bdcf8cd3414adabcd4bb52c311b4f431b525-1.png)


### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s)==0:
            return True

        d = dict()
        for i in range(len(t)):
            if t[i] in d:
                d[t[i]].append(i)
            else:
                d[t[i]] = [i]

        if s[0] in d:
            v = d[s[0]][0]
            c = 1
        else:
            return False

        for j in range(1, len(s)):
                if s[j] not in d:
                    return False
                else:
                    l = d[s[j]]
                    for k in range(len(l)):
                        if l[k]>v:
                            v = l[k]
                            c = j
                            break
            
        if c == len(s)-1:
            return True
        else:
            return False
```