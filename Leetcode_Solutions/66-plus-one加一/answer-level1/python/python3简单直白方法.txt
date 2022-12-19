### 解题思路
此处撰写解题思路
首先将列表导入到字符串中，将字符串变整形，做加一处理再变回字符串。
遍历新字符串，随后导入一个新列表中即可（导入过程中别忘了再变成整形哦）
### 代码

```python3
class Solution:
    def plusOne(self, digits):
        str1 = ""
        ans = []
        for i in range(len(digits)):
            str1 += str(digits[i])

        str1 = str(int(str1) + 1)
        for j in range(len(str1)):
            ans.append(int(str1[j]))

        return ans
```