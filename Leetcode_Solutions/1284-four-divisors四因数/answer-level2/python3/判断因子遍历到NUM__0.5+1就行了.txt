### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        res=0
        for num in nums:
            count=2
            tmp=1+num
            for i in range(2,int(num**0.5)+1):
                if num%i==0 :
                    if num//i==i:
                        count+=1
                        tmp+=i
                    else:
                        count+=2
                        tmp+=i
                        tmp+=num//i
                if count>4:
                    break
            if count==4:
                res+=tmp
        return res



```