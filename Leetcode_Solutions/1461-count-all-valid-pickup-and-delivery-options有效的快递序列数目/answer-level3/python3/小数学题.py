### 解题思路
此处撰写解题思路
就是简单的排列组合，这个没啥说的了，怎么会放在hard里面呢
### 代码

```python3
class Solution:
    def countOrders(self, n: int) -> int:
        if n == 1:
            return 1
        num_list = [1]
        for i in range(1, n):
            # print(i)
            tmp = int(num_list[i-1]*(2*i + 2)*(2*i+1)/2)
            tmp = tmp%int(pow(10, 9) + 7)
            num_list.append(tmp)
            # print(num_list)
        return num_list[-1]
```