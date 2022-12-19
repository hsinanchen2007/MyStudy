### 解题思路
各位大佬，请指教，哈哈哈

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        # 计算每个字符的数量
        # 所有偶数数量+1
        count = {}
        for i in s:
            if i not in count:
                count[i] = 1
            else:
                count[i] += 1
        ou_list = []
        ji_list = []
        for value in count.values():
            if (value % 2) == 0:
                ou_list.append(value)
            else:
                if value>2:
                    ou_list.append(value-1)
                    ji_list.append(value)
                else:
                    ji_list.append(value)
        sum_all = 0
        for ou in ou_list:
            sum_all += ou
        if len(ji_list) > 0:
            sum_all = sum_all + 1
        
        return sum_all
```