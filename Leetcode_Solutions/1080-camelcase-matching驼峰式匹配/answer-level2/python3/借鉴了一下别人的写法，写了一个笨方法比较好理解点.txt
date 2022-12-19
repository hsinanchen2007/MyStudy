
多看题目定义说明，例子有点误导，做两件事

# 保证原字符顺序不变：
    插入后新插入小写字符后形成的新字符字符顺序和原来一致，split,切分
    用pattern 所有字符依次去切分母串保留余下的部分，依次迭代，如果通过说明插入小写字符前的pattern 中的字符顺序

# 保证不插入新的单词
    大写字符的数目原来的一致 列表生成式来比对
# 优化：
    用re.find比 str.find快
    map 也会提升速度
```
class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        pattern_list = list(pattern)
        def check(strings):
            import re
            flag = True
            new_strings = strings
            print(strings, pattern_list)
            for pat in pattern_list:
                # 正则比字符串find 快
                # if new_strings.find(pat) == -1:
                if not re.findall(pat, new_strings):
                    flag = False
                    break
                new_strings = new_strings.split(pat, maxsplit=1)[-1]

            return flag and tuple(i for i in pattern if i.isupper())==tuple(i for i in strings if i.isupper())
        result = (list(map(check, queries)))
        return result
```
