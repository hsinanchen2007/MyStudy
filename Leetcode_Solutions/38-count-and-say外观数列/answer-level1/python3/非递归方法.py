### 解题思路
给出初始串推算结果串，不保留中间结果
给出当前串初始字符作为当前字符，比较后面字符是否与其相等：若相等则更新计数器，否则更新当前字符，并更新结果串及计数器。注意最后当当前字符为最后一个字符时（即最后一个字符单独出现一次），需在内循环结束后再次更新结果字符串。

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        pre_person = '1'
        for i in range(1, n):
            next_person, num, count = '', pre_person[0], 1
            for j in range(1, len(pre_person)):
                if num == pre_person[j]:
                    count += 1
                else:
                    next_person += str(count) + num
                    num = pre_person[j]
                    count = 1
            next_person += str(count) + num
            pre_person = next_person
        return pre_person
        

```