```
class Solution:
    def countAndSay(self, n: int) -> str:
        """思路：每一项的结果都是根据上一项的结果而来"""
        if n == 1:
            return "1"
        
        res = "1"
        for i in range(2, n+1):
            temp = ""
            
            j = 0
            res_l = len(res)

            while j < res_l:
                # 统计有多少个连续重复元素
                count = 1
                s = ""
                while j < res_l-1 and res[j] == res[j+1]:
                    count += 1
                    s = str(count) + str(res[j])
                    j += 1
                    
                if s:
                    temp += s
                else:
                    temp += str(count) + str(res[j])                   
                
                j += 1

            res = temp
        return res
```