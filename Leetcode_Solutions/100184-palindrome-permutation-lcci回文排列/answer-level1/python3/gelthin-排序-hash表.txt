### 解题思路
#### 排序后处理

遍历相邻的两个元素，如果相同，则下标跳两个。如果不同，则下标往前跳一个。

代码没写好，一不小心又是一个 bug.
首先应该判断一下 s 的长度是奇数还是偶数，如果是偶数，则需要不同的个数是 0, 如果增长到 1，则返回 False.

如果是奇数，则需要不同的个数是1，当增长到 2 则返回 False.

"as" 统计不同的个数是 1, 我只判断是否增长到2， 导致错误。

##### 也可以用 hash 表计数
看落单的元素有多少个。


### 代码

```python3
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        # s_l = [x for x in s].sort BUG 返回 None
        s_l = list(s)
        s_l.sort()
        n = 0
        i = 0
        while i+1<len(s):
            if s_l[i] == s_l[i+1]:
                i += 2
            else:
                i += 1
                n += 1
                if (len(s)%2 ==0 and n ==1) or n == 2:   #否则 "as" 过不了
                    return False
        return True
            
```