### 解题思路
1. 新建一个数组
2. 找出奇数放在奇数索引
3. 找出偶数放在偶数索引

### 代码

```python3
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        new_list = [0]* len(A)
        odd_index = 0
        even_index = 1
        for i in A:
            if i % 2:
                new_list[even_index] = i
                even_index += 2
            else:
                new_list[odd_index] = i
                odd_index += 2
        return new_list
        # ia = [i for i in A if not(i % 2)]
        # ja = [i for i in A if i % 2]
        # return [i for n in zip(ia, ja) for i in n]
```