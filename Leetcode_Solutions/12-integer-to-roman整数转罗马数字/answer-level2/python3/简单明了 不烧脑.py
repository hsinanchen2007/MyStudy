这属于贪心算法嘛。我感觉是的。
```
class Solution:
    def intToRoman(self, num: int) -> str:
        k_v = {1000: 'M', 100: 'C', 10: 'X', 1: 'I'}
        k_v_5 = {500: 'D', 50: 'L', 5: 'V'}
        divisor = list(k_v.items())
        divisor.sort(reverse=True)
        result = ''
        for k,v in divisor:
            if 4>num//k>=0:
                result+=v*(num//k) 
            elif num//k==4 or num//k==5:
                result += v*(5-num//k)+k_v_5[k*5]
            elif num//k==9:
                result+=v+k_v[k*10]
            else:
                result+=k_v_5[k*5]+v*((num//k)-5)
            num-=(num//k)*k
        return result
```
