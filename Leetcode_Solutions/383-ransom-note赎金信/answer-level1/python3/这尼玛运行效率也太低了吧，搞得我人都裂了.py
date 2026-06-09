### 解题思路
![QQ截图20200116161857.png](https://pic.leetcode-cn.com/4cceca9520b33a84a884513baa0647bf8fda30b411fa7ea5775fda964a344dc1-QQ%E6%88%AA%E5%9B%BE20200116161857.png)

灵活运用Python3字符串和列表API

### 代码

```python3
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for r in ransomNote:
            if magazine.find(r)!=-1:
                list_mang = list(magazine)
                list_mang.remove(r)
                magazine=''.join(list_mang)
            else:
                return False
        return True




```