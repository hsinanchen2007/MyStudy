### 解题思路
非递归用list记录中间结果避免重复计算

### 代码

```python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # special case
        if divisor == 1:
            return dividend
        if divisor == -1:
            if dividend == -2147483648:
                return 2147483647
            else:
                return -dividend
        # positive or not
        is_posive = True
        if dividend < 0:
            is_posive = not is_posive
            dividend = - dividend
        if divisor < 0:
            is_posive = not is_posive
            divisor = -divisor

        if dividend < divisor:
            return 0
        cur_divisor = divisor
        divisor_list = [divisor]
        result_list = [1]
        cur_base_count = 1
        while cur_divisor < dividend:
            cur_divisor += cur_divisor
            cur_base_count += cur_base_count
            divisor_list.append(cur_divisor)
            result_list.append(cur_base_count)

        if dividend == cur_divisor:
            ret_count = result_list[-1]
        else:
            ret_count = result_list[-2]
            diff = dividend - divisor_list[-2]

            for index in range(len(result_list)-3, -1, -1):
                if diff >= divisor_list[index]:
                    diff -= divisor_list[index]
                    ret_count += result_list[index]
                elif diff < divisor:
                    break

        return ret_count if is_posive else -ret_count
```