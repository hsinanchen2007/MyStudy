### 解题思路
思路：用一个字典保存字符的映射关系，本题的关键是通过在遍历的过程中检查相同的字符是否有相同的映射关系，否则直接返回`False`；

注意：这里既要考虑字符串`s->t`的映射，也要考虑`t->s`的映射；

### 代码

```python3
class Solution:
    """
    构造一个映射字典map_dict: s[i]->t[i]；
    遍历字符串s，如果map_dict[s[i]]不存在，则令map_dict[s[i]]=t[i]；否则检查map_dict[s[i]]是否等于t[i]；
    不相等则返回False；相等比较下一个字符；

    注意，这里不仅要有s->t的映射，也要考虑t->s的映射；同样的方法；
    """
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        map_dict_s = dict()
        map_dict_t = dict()
        for i in range(len(s)):
            try:
                if t[i] != map_dict_s[s[i]]:
                    return False
            except:
                map_dict_s[s[i]] = t[i]
            try:
                if s[i] != map_dict_t[t[i]]:
                    return False
            except:
                map_dict_t[t[i]] = s[i]
        return True
```