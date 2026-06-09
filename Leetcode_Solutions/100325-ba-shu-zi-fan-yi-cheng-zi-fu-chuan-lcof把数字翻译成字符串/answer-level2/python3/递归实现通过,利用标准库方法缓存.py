```python3
from functools import lru_cache


class Solution:
    def can_translate_num(self, num_str: str, first_index: int, second_index: int) -> int:
        """
        判断一个两位数字是否可以转换成一个字母
        :return: 如果可以转换返回 1，否则 0
        """
        sub_str = num_str[first_index: second_index + 1]
        first_str = num_str[first_index]
        if int(sub_str) < 26 and int(first_str) != 0:
            return 1
        else:
            return 0

    @lru_cache()
    def translate_num_core(self, num_str: str, index: int) -> int:
        # 只剩一个字母
        if index == len(num_str) - 1:
            return 1
        # 剩下两个
        elif index == len(num_str) - 2:
            return 1 + self.can_translate_num(num_str, len(num_str) - 2, len(num_str) - 1)
        # 当前能够翻译的数量 = 减去第一个数字后能够翻译的数量 + 减去两个数字后能够翻译的数量 * 是否能够用前两个数字翻译
        else:
            return self.translate_num_core(num_str, index + 1) + \
                   self.translate_num_core(num_str, index + 2) * self.can_translate_num(num_str, index, index + 1)

    def translateNum(self, num: int) -> int:
        return self.translate_num_core(str(num), 0)
```