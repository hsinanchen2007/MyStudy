### 解题思路
主要是想办法将整数转换成可以迭代的数据格式

### 代码

```python3
class Solution:
    def reverse(self, a: int) -> int:
        sum = 0
        if a >= 0:
            x = [int(i) for i in str(a)]
            int_list = [x[i] for i in range(len(x) - 1, -1, -1)]
            new_list_index = [x for x in range(len(int_list) - 1, -1, -1)]
            new = list(zip(int_list, new_list_index))
            for i in new:
                sum += i[0] * pow(10, i[-1])
        else:
            b = abs(a)
            x = [int(i) for i in str(b)]
            int_list = [x[i] for i in range(len(x) - 1, -1, -1)]
            new_list_index = [x for x in range(len(int_list) - 1, -1, -1)]
            new = list(zip(int_list, new_list_index))
            for i in new:
                sum += i[0] * pow(10, i[-1]) * -1
        if sum not in range(-1*pow(2,31),pow(2,31)-1):
            return 0
        else:
            return sum

```