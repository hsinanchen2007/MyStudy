### 解题思路
此处撰写解题思路

### 代码

```python3

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        """

        :param s:
        :return:
        """
        if not s:
            return 0
        len1 = len(s)
        s_index = 0
        left_num = right_num = 0
        result_left = 0
        while s_index < len1:
            if s[s_index] == "(":
                left_num += 1
            else:
                right_num += 1
            s_index += 1
            if right_num == left_num:
                result_left = max(result_left, 2 * left_num)
            if right_num > left_num:
                left_num = right_num = 0
                if len1 - s_index < result_left:
                    break
                continue
        s_index = 0
        left_num = right_num = 0
        result_right = 0
        s = s[::-1]
        s = s.replace('(', 'a').replace(')', '(').replace('a', ')')
        while s_index < len1:
            if s[s_index] == "(":
                left_num += 1
            else:
                right_num += 1
            s_index += 1
            if right_num == left_num:
                result_right = max(result_right, 2 * left_num)
            if right_num > left_num:
                left_num = right_num = 0
                if len1 - s_index < result_right:
                    break
                continue

        return max(result_left, result_right)

```