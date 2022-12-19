


```python []

def rotate(nums,k):
    ne_nums=[0]*len(nums)
    for i in range(len(nums)):
        ne_i=i+k-len(nums)
        ne_nums[ne_i]=nums[i]
    return ne_nums
print(rotate([1,2,3,4,5,6,7],3))
```
```ruby []
puts 'Hello world!'
```

简单易懂，不需托马斯全旋翻转~
但是我也会去了解一下的！@