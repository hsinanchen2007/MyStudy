构造数字-权重字典，先按照key进行排序（方便权重一样的后续排序），再按照value进行排序
```
class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        num_w = {}
        for num in range(lo,hi+1):
            w = self.getW(num)
            num_w[num] = num_w.get(num,0) + w
        sort_key = sorted(num_w.items(),key = lambda x:x[0],reverse = False)
        sort_value = sorted(sort_key,key = lambda x:x[1],reverse = False)
        return sort_value[k-1][0]
            
    def getW(self,num):
        w = 0
        while num != 1:
            if num%2==0:
                num = num/2
            else:
                num = 3*num + 1
            w += 1
        return w
```
