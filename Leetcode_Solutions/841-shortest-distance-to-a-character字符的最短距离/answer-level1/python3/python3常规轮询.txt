### 解题思路
python3常规轮询

### 代码

```python3
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        if not S:
            return []
        len_s = len(S)
        ret_list = [-1]*len_s
        target_list = []

        for index in range(len_s):
            if S[index] == C:
                ret_list[index] = 0
                target_list.append(index)

        len_target_list = len(target_list)
        for index in range(0, len_target_list-1):
            left = target_list[index]+1
            right = target_list[index+1]-1
            cur_val = 1
            while left <= right:
                ret_list[left] = cur_val
                ret_list[right] = cur_val
                cur_val += 1
                left += 1
                right -= 1

        ret_list[:target_list[0]] = list(range(target_list[0], 0, -1))
        ret_list[target_list[-1]+1:] = list(range(1, len_s-target_list[-1]))

        return ret_list

```