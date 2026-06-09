执行用时 :68 ms, 在所有 Python3 提交中击败了90.88%的用户
内存消耗 :13.1 MB, 在所有 Python3 提交中击败了91.67%的用户

```python [3]
class Solution:
    def compress(self, chars: List[str]) -> int:
        if len(chars) < 2:
            return len(chars)
        p_fast = 1
        p_slow = 0
        p_new_value = 0
        while p_fast < len(chars):
            if chars[p_slow] == chars[p_fast]:
                p_fast = p_fast+1
            else:
                temp_num = p_fast - p_slow
                chars[p_new_value]=chars[p_slow]
                if temp_num < 2:
                    p_new_value = p_new_value+1
                else:
                    p_new_value = p_new_value+1
                    temp_num = str(temp_num)
                    if len(temp_num) > 1:
                        for i in range(len(temp_num)):
                            chars[p_new_value] = temp_num[i]
                            p_new_value = p_new_value+1
                    else:
                        chars[p_new_value] = temp_num
                        p_new_value = p_new_value+1
                p_slow = p_fast
                p_fast = p_fast + 1
                
            if p_fast >= len(chars):
                temp_num = p_fast - p_slow
                chars[p_new_value]=chars[p_slow]
                if temp_num < 2:
                    p_new_value = p_new_value+1
                else:
                    p_new_value = p_new_value+1
                    temp_num = str(temp_num)
                    if len(temp_num) > 1:
                        for i in range(len(temp_num)):
                            chars[p_new_value] = temp_num[i]
                            p_new_value = p_new_value+1
                    else:
                        chars[p_new_value] = temp_num
                        p_new_value = p_new_value+1
        return p_new_value

```


