```
#枚举法，计算1在数num上各个位置时，含有1的数字数目 11 11因为有两个1 不用考虑重复的情况
#想法是不断去掉最高位，直到数字为空。分两种情况：
#  最高位为1时：tem = int(s[1:])+1+ (m-1)*(10**(m-2))
#  最高位大于1时：tem = 10**(m-1)+(m-1)*int(s[0])*(10**(m-2)) #1在最高位 数字数目 + 1在其他位置 数字数目
class Solution:
    def countDigitOne(self, n: int) -> int:
        if n <= 9: return 1
        arr = []
        while n:
            arr = [n%10] + arr
            n = n//10
        self.res = 0
        def hp(arr):
            if len(arr)==0: return
            if len(arr)==1:
                if arr[0] >=1: 
                    self.res+=1
                return
            if arr[0]>1:
                m = len(arr)
                tem = 10**(m-1)+(m-1)*arr[0]*(10**(m-2))
                self.res+=tem
            elif arr[0]==1:
                m = len(arr)
                tem = (m-1)*(10**(m-2))
                base = 1
                for i in range(len(arr)-1,0,-1):
                    tem+=arr[i]*base
                    base*=10
                tem+= 1
                self.res+=tem
            
            hp(arr[1:])
        hp(arr)
        return self.res

    def count(self,n):
        #利用字符串
        if n==0: return 0
        self.res = 0
        s = str(n)
        def dfs(s):
            if len(s)==0:return
            if int(s[0])>1:
                m = len(s)
                tem = 10**(m-1)+(m-1)*int(s[0])*(10**(m-2))
                self.res+=tem
            elif int(s[0])==1:
                m = len(s)
                tem = int(s[1:])+1+ (m-1)*(10**(m-2))
                self.res+=tem
            dfs(s[1:])
        dfs(s)
        return self.res
print(Solution().count(412))
```
