这题的题目描述有点坑啊。。。题目的示例的输出其实是False，不要被误导了。。。
本题为简单题，所以不需要想的太复杂。

**思路**：
- 用一个哈希表记录每个字符出现的个数
- 然后判断每个key出现的个数，看看是否能构成回文串（最多允许一个key的数量是奇数，此时该key放在回文串中心位置，所以若出现两个奇数的，则不能构成回文串）

**吐槽**：
看那个示例我还以为需要考虑什么空格问题、字符大小写问题等等。。结果一运行发现示例的输入是False。。无语。。

```
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        d = {}
        for i in s:
            if i not in d.keys():
                d[i] = 1
            else:
                d[i] += 1
        
        center = False
        for key in d.keys():
            if d[key] % 2 == 1:
                if center:
                    return False
                else:
                    center = True
        
        return True
```
