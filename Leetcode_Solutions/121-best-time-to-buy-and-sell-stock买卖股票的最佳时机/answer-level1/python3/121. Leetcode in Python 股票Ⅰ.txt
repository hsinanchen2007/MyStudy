1. 先更新最小值，也就是买入值
2. 再更新利润值，也就是current和买入值的差


```python []
minn = float('inf')
maxx = 0
for i in range(len(nums)):
    minn = min(nums[i], minn)
    maxx = max(maxx, nums[i]-minn)
return maxx
```


