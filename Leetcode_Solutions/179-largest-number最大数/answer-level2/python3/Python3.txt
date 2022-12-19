### 解题思路
此处撰写解题思路
用了一个奇怪的方法。。。。
### 代码

```python3
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums=sorted(nums)
        j=0
        ans=''
        dic=defaultdict(list)
        for num in nums:
            dic[len(str(num))].append(num)      
        for i in dic.keys():
            dic[i]=sorted(dic[i])
        while j<len(nums):
            kexuan=[dic[i][-1] for i in dic.keys() if dic[i]]
            kexuan=sorted(kexuan,key=lambda x:x/int(len(str(x))*'1'),reverse=True)
            a=kexuan[0]
            ans=ans+str(a)
            dic[len(str(a))].pop()
            j=j+1
        return ans if ans !=len(ans)*'0' else '0'       
        
        

```