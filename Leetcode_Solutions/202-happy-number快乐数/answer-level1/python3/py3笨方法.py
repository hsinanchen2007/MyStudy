### 解题思路
（执行用时 : 60 ms , 在所有 python3 提交中击败了 18.44% 的用户 内存消耗 : 12.7 MB , 在所有 python3 提交中击败了 99.43% 的用户）
思路：把结果放入list中，如果当前结果在list中说明出现了循环
### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        def tonewnum(num):
            a = [int(i) for i in list(str(num))]
            result = 0
            for i in a:
                result = result + pow(i,2)
            return result
        l = [n]
        while True:
            last = l[len(l) - 1]
            if tonewnum(last) not in l :
                l.append(tonewnum(last))
            elif tonewnum(last) == 1:  
                return True
            else:
                return False
        return True
```