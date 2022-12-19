```
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        for i in range(1, len(num) // 3 + 1):
            for j in range(i + 1, (len(num) // 3) * 2 + 1):
                for k in range(j + 1, len(num) + 1):
                    if self.str_add(num[:i], num[i: j], num[j:k]):
                        if k == len(num):
                            return True
                        if self.str_func(j-i, k-i, num[i:]):
                            return True
                    if num[j] == '0':break
                if num[i] == '0':break
            if num[0] == '0':break
        return False
    
    def str_func(self, j, k, str_sub):
        if k == len(str_sub):
            return True
        for i in range(k + 1, len(str_sub) + 1):
            if self.str_add(str_sub[:j], str_sub[j:k], str_sub[k:i]):
                if self.str_func(k-j, i-j, str_sub[j: ]):
                    return True
            if str_sub[k] == '0':break
        return False
        
    def str_add (self, str1, str2, str_sum): #字符串相加判断
            tmp = 0
            str1 = str1[::-1]
            str2 = str2[::-1]
            str_sum = str_sum[::-1]
            len1 = len(str1)
            len2 = len(str2)
            if len(str_sum) < max(len1, len2):
                return False
            for i in range(max(len1, len2)):
                a = int(str1[i]) if i < len1 else 0
                b = int(str2[i]) if i < len2 else 0
                tmp += a + b
                if (tmp % 10) != int(str_sum[i]):
                    return False
                tmp //= 10
            if tmp > 0:
                return tmp == int(str_sum[-1])
            return True
```
