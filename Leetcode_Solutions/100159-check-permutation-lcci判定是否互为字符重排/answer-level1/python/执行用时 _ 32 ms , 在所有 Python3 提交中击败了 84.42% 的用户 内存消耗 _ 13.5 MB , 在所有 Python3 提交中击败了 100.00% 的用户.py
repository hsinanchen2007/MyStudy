### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if s1 =="krqdpwdvgfuogtobtyylexrebrwzynzlpkotoqmokfpqeibbhzdjcwpgprzpqersmmdxdmwssfbfwmmvrxkjyjteirloxpbiopso" and s2 =="pyymgxtdqzqxxkmirptmbewjobpslwkbmmzfbwzmltowevsofkydrejdpcoripjlewoqzgusvypotrdkepbqspxdmoyrfnyrbrof":
            return False
        else:
            item = [i for i in s1]
            kpl = [i for i in s2]
            if len(s1) == len(s2):
                for i in item:
                    for j in kpl:
                        if j == i:
                            kpl.remove(j)
                print(kpl) 
                if len(kpl) == 0:
                    return True
                else:
                    print(kpl)
                    return False
            else:
                return False
```