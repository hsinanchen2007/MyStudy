逻辑是这样的

如果在list中出现00这个组合，后一个0必然为单比特字（前一个0可以是单比特字或双比特字）。

如果出现01这个组合，则此处0与1必然不属于同一个字。


检查最后一位，如果是1，直接return False。

检查最后一位，如果是0，检查倒数第二位，

倒数第二位是0 return True。

倒数第二位不是0，检查0前有几个连续1，奇数个：False, 偶数个：True。

```
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        if bits[-1] == 0:
            try:
                if bits [-2] == 0:
                    return True
                else:
                    sum1 = 0
                    for k in range(-2, -len(bits)-1, -1):
                        if bits[k] == 1:
                            sum1 += 1
                        else:
                            break
                    if sum1 % 2 == 0:
                        return True
                    else:
                        return False
            except IndexError:
                return True
        else:
            return False

```
执行用时 : 48 ms , 在所有Python3提交中击败了96.32%的用户

内存消耗 : 13 MB, 在所有Python3提交中击败了96.88%的用户