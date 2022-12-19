```
def isAnagram(self, s: str, t: str) -> bool:
    # 定义默认布尔值参与后续运算
    result = True
    # 利用 Python 数据结构 set 去重去序
    set_tmp = set(s)
    # 先判断组成字符串的各个字符元素是否一致
    if set_tmp == set(t):
        for i in set_tmp:
            # 利用逻辑运算符判断各个字符元素的数量一致，均为 True 才输出 True
            result = result and (s.count(i) == t.count(i))
    else:
        result = False
    return (result)
```

主要利用了 set 的内置优化和特性减少运算，以及使用布尔运算提高效率。

执行用时 : 48 ms, 在所有 Python3 提交中击败了 98.93% 的用户
内存消耗 : 14 MB, 在所有 Python3 提交中击败了 29.70% 的用户

各位觉得还不错的点点赞吧，万一本文科生转行码农呢哈哈，感谢！