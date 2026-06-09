```
mx=t=sum(nums[0:k])
for i in range(k,len(nums)):
    t+=nums[i]-nums[i-k]
    mx=t if t>mx else mx
return mx/k
```
