### 解题思路
分离位权，进行四个条件判断，在字典查找对应值

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        dic = {1: 'I', 5: 'V', 10: 'X', 50: 'L', 100: 'C', 500: 'D',
            1000: 'M', 4: 'IV', 9: 'IX', 40: 'XL', 90: 'XC', 400: 'CD', 900: 'CM'}
        list_num = list(str(num))[::-1]
        #print(list_num)
        res = []
        base = 10  # 基数,十进制
        for quan, wei in enumerate(list_num):  # 分离位权
            weight = int(wei)
            #print(quan,weight)
            if weight >= 0 and weight < 4:
                res.append(dic[base ** quan] * weight)
            elif weight == 4:
                res.append( dic[weight * base ** quan])
            elif weight >= 5 and weight < 9:
                res.append(dic[5 * base ** quan] + dic[base ** quan]*(weight-5))
            elif weight == 9:
                res.append(dic[weight * base ** quan])
            # print(res)
        res_str = "".join(res[::-1])
        #print(res_str)
        return res_str
```