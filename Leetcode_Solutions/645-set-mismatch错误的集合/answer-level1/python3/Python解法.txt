#### 思路
1. 丢失的整数：原始集合为`{1,2,3，···,n}`，丢失以后的数组形成的集合为`{1,□,3，···,n}`，取交集即可；
2. 重复的整数：有且仅有一个元素重复了，也就是说**出现了两次的那个数**即为所求。
#### 代码
```python
def findErrorNums(nums):
    n=len(nums)
    los=set(nums)        
    ori=set(range(1,n+1))
    re=list(ori^los)
    dic=collections.Counter(nums)
    for k,v in dic.items():
        if v==2:
            re.insert(0,k)
    return re
```
#### 结果
![3.png](https://pic.leetcode-cn.com/ccc03d6a1baad52d66b01ff1f2b6d04c293c160892f7ba1bcc9c3af56cae2109-3.png)
