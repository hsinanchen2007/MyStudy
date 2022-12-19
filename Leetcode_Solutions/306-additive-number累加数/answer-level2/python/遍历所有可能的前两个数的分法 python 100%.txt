√ 在长度范围内随机两个数(过滤掉不满足条件的)作为前两个数的末尾，如i,j表示nums[:i+1],nums[i+1:j]

```
class Solution:
    def isAdditiveNumber(self, nums: str) -> bool:
        def str2int(s):  
            if len(s)>=2 and s.startswith('0'):  # 如果不合法返回-1
                return -1
            ret, w = 0, 0
            for i in s[::-1]:
                ret += int(i)*10**w
                w += 1
            return ret
        leng = len(nums)
        pos = []
        for i in range(leng):  # 查找可能的前两个字母的切分
            for j in range(i+1, leng):
                if leng-j>=max(j-i,i):
                    pos.append([i,j])
        for i,j in pos:
            n1, n2 = str2int(nums[:i+1]), str2int(nums[i+1:j+1])
            if n1>=0 and n2>=0:
                p = j
                while p<leng:
                    tmp = n1+n2
                    if nums[p+1:].startswith(str(tmp)):
                        n1 = n2
                        n2 = tmp
                        p += len(str(tmp))
                        if p==leng-1:  # 刚好用完所有的数
                            return True
                    else:
                        break
        return False
```
                    
                        
                
        
        
        
        
        
        
        
        
        
        
        
        
        
        
         
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
         
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
         
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
         
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        