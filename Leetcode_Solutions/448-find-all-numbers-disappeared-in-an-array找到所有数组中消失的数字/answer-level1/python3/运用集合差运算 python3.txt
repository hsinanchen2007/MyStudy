先把原矩阵转为Set类型去重，然后构造总集合all,all中包含了从1到n所有元素，在使用集合差运算即可：
```
def findDisappearedNumbers(nums):
    if(nums==[]):
        return [] 
    leng=len(nums)
    nums=set(nums)
    all=set(list(range(1,leng+1)))
    res=all-nums
    return res
```
