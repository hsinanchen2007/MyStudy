```
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        if k == 1:
            return(s)
        elif k > 1:
            num = 1
            str_long = len(s)
            new_str_long = 0
            new_str = ""
            while new_str_long + k <= str_long:
                if num % 2 == 1:
                    fan_str = s[new_str_long:k+new_str_long][::-1]
                    #new_str += fan_str
                else:
                    fan_str = s[new_str_long:k+new_str_long]
                new_str += fan_str
                num += 1
                new_str_long += k
            if len(new_str) == str_long:
                return(new_str)
            else:
                if num % 2 == 1:
                    fan_str = s[new_str_long:][::-1]
                else:
                    fan_str = s[new_str_long:]
                new_str += fan_str
                return(new_str)
```
