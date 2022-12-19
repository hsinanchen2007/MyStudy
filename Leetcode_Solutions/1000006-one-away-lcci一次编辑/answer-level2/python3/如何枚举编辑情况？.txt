### 解法一：计算编辑距离
本题可以直接计算两个字符串的编辑距离，如果编辑距离为0或1则返回True。编辑距离的计算可参见[Leetcode-编辑距离](https://leetcode-cn.com/problems/edit-distance)

### 解法二：情况枚举
本题由于只需要考虑是否能进行一次编辑，因此情况会比计算整个字符串之间的编辑距离要简单很多，那么如何考虑这些情况呢？

首先区分0次编辑与1次编辑，随后对应于1次编辑的情况，分别判断删除、插入、替换对应的特征，总结如下：

0次编辑 -> 字符串相等
1次编辑 ->
    删除 -> len(sec) = len(first) + 1, 比较过程可跳过一个字母
    插入 -> len(sec) = len(first) - 1, 比较过程可跳过一个字母
    替换 -> len(sec) = len(first)，比较过程可跳过一个字母

对应字符串的比较会使用双指针算法，那么由于删除、插入、替换在比较过程汇总均可以跳过一个字母，只需要**在比较不相等时根据字符串长度来判断应执行哪个操作即可**。

```
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        if abs(len(first) - len(second)) > 1:
            return False

        i, j = 0, 0
        chance = True
        while i < len(first) and j < len(second):
            if first[i] == second[j]:
                i += 1
                j += 1
            else:
                if chance:
                    # 删除
                    if len(second) == len(first) + 1:
                        j += 1
                    # 替换
                    elif len(second) == len(first):
                        i += 1
                        j += 1
                    # 插入
                    else:
                        i += 1
                    chance = False
                else:
                    return False
        return True
```

