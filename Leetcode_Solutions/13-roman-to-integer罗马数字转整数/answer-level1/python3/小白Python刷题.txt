### 解题思路
1.将罗马数字和数字进行一一对应，用字典完成
2.生成空列表，将字典问题转化为列表
3.遍历列表，如果右边的小于左边则为负，否则为正数 累加
4.返回累加值，注意由于第三步少加了最后一个数，应加上



### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        d={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        arr=[]
        sum=0
        for i in s:
            arr.append(d[i])
        for i in range(len(arr)-1):
            if arr[i]<arr[i+1]:
                   sum-=arr[i]
            else:
                sum+=arr[i]
            
        return sum+arr[-1]
```