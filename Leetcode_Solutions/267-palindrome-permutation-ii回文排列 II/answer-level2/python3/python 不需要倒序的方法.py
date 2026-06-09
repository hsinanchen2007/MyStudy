从中间向两边添加字符，则省去倒序一步
```
class Solution:
    def generatePalindromes(self, s: str) -> List[str]:
        def helper(my_dict, pre):
            if len(pre) == count1 + len(mid_str):
                ret_list.append(pre)
            for s in my_dict:
                my_dict[s] -= 1
                if my_dict[s] >= 0:
                    helper(my_dict, s + pre + s)
                my_dict[s] += 1
        ret_list = []
        my_dict = {}
        for i in range(len(s)):
            my_dict[s[i]] = my_dict.get(s[i], 0) + 1
    
        count = 0
        count1 = 0
        mid_str = ''
        for item in my_dict:
            if my_dict[item] % 2 == 1:
                mid_str = item
                count1 += (my_dict[item] - 1)
                my_dict[item] = (my_dict[item] - 1) // 2
                count += 1
            else:
                count1 += my_dict[item]
                my_dict[item] //= 2
            if count > 1:
                return []        
        helper(my_dict, mid_str)
        return ret_list

        

        

```
