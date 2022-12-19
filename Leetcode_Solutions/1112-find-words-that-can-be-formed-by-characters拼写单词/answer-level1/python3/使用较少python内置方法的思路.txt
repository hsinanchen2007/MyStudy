### 解题思路
使用较少的内置方法，体现思考过程而非pythonic

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        letter_dict_origin={}
        sum=0
        for c in chars:
            if c in letter_dict_origin:
                letter_dict_origin[c]+=1
            else:
                letter_dict_origin[c]=1
        for w in words:
            letter_dict={}
            check=1
            for l in w:
                if l in letter_dict:
                    letter_dict[l]+=1
                else:
                    letter_dict[l]=1
            for k in letter_dict.keys():
                if k in letter_dict_origin.keys():
                    if letter_dict[k]>letter_dict_origin[k]:
                        check=0
                else:
                    check=0
            if check:
                sum+=len(w)
        return sum

```