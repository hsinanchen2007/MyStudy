### 解题思路
思路不是特别好
一、现将数字转化成字符串
二、准备一个额外数组用于顺序存放字符串
三、每次都遍历这个额外数组中都字符串，取出字符串中都每个字符，依次做判断
四、因为字符串都不是等长的，所以加了一些代码用于特殊情况的判断

### 代码

```python
class Solution(object):
    def minNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        result_list = []

        for num in nums:
            is_find = False

            num_str = str(num)

            index = 0
            for result in result_list:
                current_index = 0
                num_length = len(num_str)
                result_length = len(result)

                while current_index < num_length or current_index < result_length:

                    current_num_char = num_str[num_length - 1]
                    current_result_char = result[result_length - 1]

                    if current_index < num_length:
                        current_num_char = num_str[current_index]

                    if current_index < result_length:
                        current_result_char = result[current_index]

                    if current_num_char < current_result_char:

                        if current_index >= num_length and current_result_char < result[0]:
                            break

                        result_list.insert(index, num_str)
                        is_find = True
                        break
                    elif current_num_char > current_result_char:

                        if current_index >= result_length and current_num_char < num_str[0]:
                            result_list.insert(index, num_str)
                            is_find = True

                        break

                    current_index += 1

                if is_find:
                    break

                index += 1

            if not is_find:
                result_list.append(num_str)

        return ''.join(result_list)
```