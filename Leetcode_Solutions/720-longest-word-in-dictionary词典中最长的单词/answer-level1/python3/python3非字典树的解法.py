### 解题思路
python3非字典树的解法，为提高效率，尽早跳出循环

### 代码

```python3
class Solution:
    def longestWord(self, words: List[str]) -> str:
        count_dict = {}
        for item in words:
            len_item = len(item)
            if len_item in count_dict:
                count_dict[len_item].append(item)
            else:
                count_dict[len_item] = [item]

        # import ipdb; ipdb.set_trace()
        max_count = 1
        while max_count:
            if max_count not in count_dict:
                break
            max_count += 1

        max_count -= 1

        for index in range(max_count, 0, -1):
            cur_list = count_dict[index]
            cur_list.sort()

            for item in cur_list:
                is_ok = True
                for cur_len in range(index-1, 0, -1):
                    if item[:cur_len] not in count_dict[cur_len]:
                        is_ok = False
                        break

                if is_ok:
                    return item

        return ''


```