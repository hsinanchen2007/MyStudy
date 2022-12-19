### 解题思路
使用collections中的有序字典OrderedDict,直接返回第一个value==1的字符所在的索引就行了。
![image.png](https://pic.leetcode-cn.com/806711d5bdc5f72586b9cdeb90c7d383654fa2f0053cf24ce13b9479b7853b7f-image.png)

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        from _collections import OrderedDict
        order_dict = OrderedDict()
        for char in s:
            if char not in order_dict:
                order_dict[char] = 1
            else:
                order_dict[char] += 1
        for key,val in order_dict.items():
            if val == 1:
                return s.index(key)
        return -1
```
欢迎关注的我的[github](https://github.com/tcandzq)，查看更多精彩题解