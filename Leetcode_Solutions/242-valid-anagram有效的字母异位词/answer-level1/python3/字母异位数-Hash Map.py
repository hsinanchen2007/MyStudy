### 解题思路
`Map 计数  {letter:Count}
如：Map --》nagaram：{a:3,n:1,g:1,r:1,m:1}
            anagram：{a:3,n:1,g:1,r:1,m:1}
比较两个字典,如果相等，说明是字母异位数；否则不是`

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict1,dict2 ={},{}
        for item in s:
            dict1[item] = dict1.get(item,0)+1
        for item in t:
            dict2[item] = dict2.get(item,0)+1
        return dict1 == dict2
```