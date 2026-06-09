### 解题思路
移除高位逆序的数字，最后的结果自然是最小的。例如12321，尽可能保持高位小，那么321的3作为逆序的区间，把3移除了留下21一定是最小的。按照这个思路借助一个栈就可以搞定了。
如果按照k来遍历，则每次都需要从头再来一次，复杂度是O(N2)，反向借助遍历num，则可以降低复杂度。
![image.png](https://pic.leetcode-cn.com/72e63ad3ab9d425f5ec5b10e6fb5ceaa5e789545df027681af26970d92a3f148-image.png)

### 代码

```python3
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        len_num = len(num)
        if k == len_num:
            return '0'

        new_num = []
        for n in num:
            while new_num and k > 0 and n < new_num[-1]:
                new_num.pop(-1)
                k -= 1
            
            new_num.append(n)

        if k > 0:
            new_num = new_num[:-k]
            
        no_zero_num = self._erase_zero_in_left(new_num)
        return ''.join(no_zero_num)

    @staticmethod
    def _erase_zero_in_left(new_str_list):
        while len(new_str_list) > 1:
            if new_str_list[0] == '0':
                new_str_list.pop(0)
                continue

            break

        return new_str_list
        
```