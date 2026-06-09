### 解题思路
执行用时 :
44 ms
, 在所有 python3 提交中击败了
31.95%
的用户
内存消耗 :
12.7 MB
, 在所有 python3 提交中击败了
100.00%
的用户
### 代码

```python3
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        str_list=str.split(" ")
        dict={}
        if len(pattern)!=len(str_list):
            return False
        for each_letter,each_str in zip(pattern,str_list):
            if dict.get(each_letter)==None:
                dict[each_letter]=each_str
            else:
                if dict[each_letter]!=each_str:
                    return False
            kry_temp=each_letter
            value_temp=dict[each_letter]
            for key,value in dict.items():
                if key!=kry_temp and value==value_temp:
                    return False       
        return True


```