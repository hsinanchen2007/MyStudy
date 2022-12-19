### 解题思路
![字母异位词分组.png](https://pic.leetcode-cn.com/1114d62dfb6683ebad4fbfcdce33394fe5efbfa10cf75847614ccc967729867c-%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D%E5%88%86%E7%BB%84.png)

遍历strs，现将当前字符串排序，然后把排序号的字符串作为键，原字符串作为值，添加到字典中
最后返回字典的所有值的list形式

### 代码

```python3
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}
        for i in strs:
            dic.setdefault(''.join(sorted(i)), []).append(i)
        return list(dic[i] for i in dic)
```