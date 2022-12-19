
```
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        # 72 ms
        # 12.7 MB
        base_num = [1000, 500, 100, 50, 10, 5, 1]
        base_num_map = {1000: "M", 500: "D", 100: "C",
                        50: "L", 10: "X", 5: "V", 1: "I"}
        base_num_add_map = {1000: 100, 500: 100, 100: 10,
                            50: 10, 10: 1, 5: 1, 1: 0}
        ans = ""
        for i in range(0, len(base_num)):
            xx = num // base_num[i]
            num = num % base_num[i]
            if xx >= 1:
                value = base_num_map[base_num[i]]
                for j in range(0, xx):
                    ans += value
            if (num + base_num_add_map[base_num[i]]) // base_num[i] == 1:
                ans += base_num_map[base_num_add_map[base_num[i]]] + base_num_map[base_num[i]]
                num -= base_num[i] - base_num_add_map[base_num[i]]

        return ans
```
