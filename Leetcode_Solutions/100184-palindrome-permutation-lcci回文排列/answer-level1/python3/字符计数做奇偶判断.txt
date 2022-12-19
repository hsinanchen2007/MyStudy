### 解题思路
对字符计数，只能出现一个奇数次的字符，其余是偶数次或全部是偶数次，还有一个另外就是字符串都是同一个字母

### 代码

```python3
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        counter_dict = {}
        for i in s:
            if i in counter_dict:
                counter_dict[i] += 1
            if i not in counter_dict:
                counter_dict[i] = 1
            
        # print(counter_dict)
        if len(list(set(list(s)))) == 1:
            return True
        l = []
        for i in s:
            if counter_dict[i] % 2 != 0:
                l.append(i)
        # print(l)
        l = list(set(l))
        if len(l) > 1:
            return False
        if len(l) == 1:
            return True
        if len(l) == 0:
            return True

```