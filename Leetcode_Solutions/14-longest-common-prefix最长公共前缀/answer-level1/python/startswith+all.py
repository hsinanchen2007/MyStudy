### 解题思路
1. 非空列表处理
2. 取最短列表元素长度为前缀，并逐次减小
3. 判断全部列表元素是否有该前缀
4. 有则返回，否则为空

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs:
            for i in range(min(map(len,strs)),0,-1):
                prefix=strs[0][:i]
                result_list=all(map(lambda v:v.startswith(prefix),strs))
                if result_list:
                    return prefix
        return ''
```