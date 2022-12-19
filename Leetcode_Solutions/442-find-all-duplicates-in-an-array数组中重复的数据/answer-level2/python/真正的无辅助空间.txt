更多题解关注我的博客
http://sbaban.com/leetcode-list.html


最初想法：

根据下标，将对应位置的元素重置为负值，为正的就是出现偶数次的。

但如何解决出现0次的元素，其位置加不了负号还是正值？

考虑+n，偶数次就是加2n，最后找出>2n的元素就可以。

```python
def findDisappearedNumbers( nums):
    # n=len(nums)
    for i in range(len (nums)):
        # nums[abs(nums[i])-1] = - nums[abs(nums[i])-1]
        #nums[nums[i]%n-1] = nums[nums[i]%n-1]+n#当n与当前元素相等时，取余会变成0
        nums[(nums[i]-1)%len (nums)] += len (nums) #注意，先减1再取下标。

    # print(nums)
    #返回大于2n的元素
    return [index+1 for index,elem in enumerate(nums) if elem>2*len (nums)]

```

