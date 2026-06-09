### 解题思路
此处撰写解题思路

### 代码
1.将连个字符串相同位置值作为哈希表的key_string，value_string存储；
2.若出现相同的key，但是value与前一个不同就会将前一个覆盖，导致重新组成的字符串与待测的value_string不同；
3.为避免出现key_string=‘ab’，value_string=‘aa’类型的key不重复，value重复的问题，通过计算两个串的不重复子串长度（即set串长度）解决。
```python3
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        hashmap={}
        t_string=''
        if len(set(s))!=len(set(t)):
            return False
        for index,c in enumerate(s):
            hashmap[c]=t[index]
        for c in s:
            t_string+=hashmap[c]
        return True if t_string==t else False
```