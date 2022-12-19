### 解题思路
我这么垃圾的代码居然能双超100%？不敢相信

### 代码

```python3
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        list_ = str.split()
        if len(list_) != len(pattern):
            return False
        ret1, ret2 = {}, {}
        for i in range(len(pattern)):
            if pattern[i] not in ret1 and list_[i] not in ret2:
                ret1[pattern[i]] = list_[i]
                ret2[list_[i]] = pattern[i]
            elif pattern[i] in ret1 and ret1[pattern[i]] == list_[i] and list_[i] in ret2 and ret2[list_[i]] == pattern[i]:
                pass
            else:
                return False
        return True
```

![capture_20191212093634295.bmp](https://pic.leetcode-cn.com/17086a204cdc45d2feeb4d5f32f74f7db6629e95bd1ba59c3337fe186c23d7d9-capture_20191212093634295.bmp)
