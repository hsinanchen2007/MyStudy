### 解题思路
- 通过判断n的奇偶性来添加数字
- 如果n是偶数，那么在添加数字的时候，可以直接加入互为相反数的值
- 如果n是奇数，那么可以提前加入一个值0，然后再加入互为相反数的值
- 声明一个变量index用来控制添加不同的数（例如1, -1, 2, -2, 3, -3...）

### 代码

```python3
class Solution:
    def sumZero(self, n: int) -> List[int]:
        # 通过判断n是奇数还是偶数来添加数字
        # 如果n是偶数，那么在添加数字的时候，可以加入互为相反数的值
        # 如果n是奇数，那么可以提前加入一个值0， 然后再加入互为相反数的值
        # 声明一个变量index用来控制添加不同的数（例如1，-1， 2， -2， 3， -3...）
        result = []
        index = 1
        if n ==1:
            result.append(0)
            return result
        if n % 2 == 0:
            for i in range(1, n+1):
                result.append((-1)**i*index)
                if i % 2 ==0:
                    index +=1
            return result
        else:
            result.append(0)
            for i in range(1, n):
                result.append((-1)**i*index)
                if i % 2 ==0:
                    index +=1
            return result

```