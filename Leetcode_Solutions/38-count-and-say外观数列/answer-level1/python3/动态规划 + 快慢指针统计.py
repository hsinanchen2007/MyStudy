```
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1: return '1'
        temp_str = '1'
        for _ in range(n-1):
            temp_str = self.count_num(temp_str)
        return temp_str

    def count_num(self, num_str:str)->str:
        slow, fast, result_str = 0, 0 , ''
        while fast < len(num_str):
            if num_str[fast] != num_str[slow]:
                result_str += f"{fast - slow}{num_str[slow]}"
                slow = fast
            else:
                fast += 1
        return result_str + f"{fast - slow}{num_str[slow]}"

```
