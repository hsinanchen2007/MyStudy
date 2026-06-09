### 解题思路
zip函数可将列表打包为元组，元祖的长度与最短的列表的长度一致。
然后使用set函数将列表中的元素去重，如果len（set（list））的长度为1，则说明这个列表的元素一样。
```
nums = ['flower','flow','flight']
for i in zip(*nums):
    print(i)
('f', 'f', 'f')
('l', 'l', 'l')
('o', 'o', 'i')
('w', 'w', 'g')
```
### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ''
        result=[]
        for temp in zip(*strs):
            if len(set(temp))==1:
                result+=temp[0]
            else:
                break
        return ''.join(result)
```