### 解题思路

我的思路：
emmmm就是遍历匹配,满足条件的加入到结果中.
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(1)


### 代码

```python3
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        result = []
        text = text.split(' ')
        # 边界
        text.append('#')
        text.append('#')
        for i in range(len(text)-2):
            if text[i] == first and text[i+1] == second and text[i+2] != '#':
                result.append(text[i+2])
        return result

```