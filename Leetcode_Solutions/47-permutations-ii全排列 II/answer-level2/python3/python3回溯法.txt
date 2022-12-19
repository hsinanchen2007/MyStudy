### 解题思路
python3回溯法

### 代码

```python3
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        len_nums = len(nums)
        if len_nums < 2:
            return [nums]
        self.ret_list = []
        total_dict = {}

        for item in nums:
            if item in total_dict:
                total_dict[item] += 1
            else:
                total_dict[item] = 1

        def my_traverse(existed_list, pending_dict):
            for cur_key in pending_dict.keys():
                tmp_dict = pending_dict.copy()
                tmp_dict[cur_key] -= 1
                if tmp_dict[cur_key] == 0:
                    tmp_dict.pop(cur_key)
                if not tmp_dict:
                    self.ret_list.append(existed_list+[cur_key])
                else:
                    my_traverse(existed_list+[cur_key], tmp_dict)

        my_traverse([], total_dict)
        return self.ret_list


```