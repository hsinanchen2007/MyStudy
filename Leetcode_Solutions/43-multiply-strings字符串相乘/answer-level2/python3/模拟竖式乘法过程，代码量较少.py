
class Solution:

    def str2int(self,s):
        return ord(s)-ord('0')

    def multiply(self, num1: str, num2: str) -> str:
        a = num1[::-1]
        b = num2[::-1]
        result = 0
        
        for i,x in enumerate(a):
            temp_result = 0
            for j,y in enumerate(b):
                temp_result += self.str2int(x) * self.str2int(y) * 10**j
            result += temp_result * 10**i
        return str(result)
  