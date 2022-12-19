一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 关注交流。

### 解题思路
反向遍历，哈希表存储字母数量，最后一个数量为1的字母为最终的输出。


### 代码

```python
class Solution(object):
    def firstUniqChar(self, s):
        map = {}
        for i in range(len(s)):
            map[s[i]] = map.get(s[i], 0) + 1
        for i in range(len(s)):
            if map[s[i]] == 1:
                return s[i]
        return " "
```