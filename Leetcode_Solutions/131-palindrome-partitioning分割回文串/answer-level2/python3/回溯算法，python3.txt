### 解题思路
![分割回文串.png](https://pic.leetcode-cn.com/b7ea7413d8be9e28f4c7f6dcec6696e9a6a12d69b6d68fd5a4a611b87785e4d7-%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2.png)

遍历字符串
如果遍历到第i位时，s的前i位是回文串，那么递归调用本函数
知道函数的输入为空时，一次回溯结束

### 代码

```python3
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def backtrack(s, path):
            if not s:
                res.append(path)
                return
            for i in range(len(s)):
                if s[:i+1] == s[i::-1]:
                    backtrack(s[i+1:], path+[s[:i+1]])    
        tmp,res = [],[]
        backtrack(s, tmp)
        return res

```