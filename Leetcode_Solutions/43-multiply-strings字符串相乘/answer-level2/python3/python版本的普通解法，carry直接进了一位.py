
```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return '0'

        len_num1 = len(num1)
        len_num2 = len(num2)
        # largest capcity
        ret_val_list = [0]*(len_num2 + len_num1)

        base_sequnce = len_num1 + len_num2 - 2
        for index1 in range(len_num1-1, -1, -1):
            for index2 in range(len_num2-1, -1, -1):
                cur_val = int(num2[index2]) * int(num1[index1])
                cur_sequence = base_sequnce - index1 - index2
                ret_val_list[cur_sequence] += cur_val % 10
                if ret_val_list[cur_sequence] > 9:
                    ret_val_list[cur_sequence] %= 10
                    ret_val_list[cur_sequence+1] += 1

                ret_val_list[cur_sequence+1] += cur_val // 10
                if ret_val_list[cur_sequence+1] > 9:
                    ret_val_list[cur_sequence+1] %= 10
                    ret_val_list[cur_sequence+2] += 1

        ret_str = ""
        start_index = len_num2 + len_num1 -1
        if ret_val_list[-1] == 0:
            start_index -= 1

        for index in range(start_index, -1, -1):
            ret_str += str(ret_val_list[index])
        return ret_str

```
