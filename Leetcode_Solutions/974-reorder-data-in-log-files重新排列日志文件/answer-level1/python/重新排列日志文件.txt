### 解题思路
学习了sorted多次排序。膜拜大佬。

### 代码

```python3
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digs, ltrs, iltrs = [], [], {}
        for log in logs:
            i = log.find(' ') + 1
            if log[i].isdigit():  # 判断是否字母/数字
                digs += [log]
            else:
                iltrs[log] = i   # 记录第一个空格出现的位置
                ltrs += [log]
        return sorted(ltrs, key = lambda log: [log[iltrs[log]: ], log[: iltrs[log]]]) + digs    
        # sorted(ltrs, key = lambda log: [log[iltrs[log]: ], log[: iltrs[log]]])   # 从第二个单词开始排序，再按标识符排序

        # # 作者：LeetCode-Solution
        # def f(log):
        #     id_, rest = log.split(" ", 1)
        #     return (0, rest, id_) if rest[0].isalpha() else (1,)
        # return sorted(logs, key = f)

        # 怎么处理字母串的排序呢？
        # aplha = []
        # num = []

        # for log in logs:
        #     words = log.split()
        #     if words[1].isalpha():
        #         aplha.append((words))
        #     else:
        #         num.append(log)
        
        # sortedAlpha = sorted(aplha, key=lambda s:s[1])
    
        # resAlpha = []
        # for item in sortedAlpha2:
        #     resAlpha.append(' '.join(item))
   
        # return resAlpha + num
```