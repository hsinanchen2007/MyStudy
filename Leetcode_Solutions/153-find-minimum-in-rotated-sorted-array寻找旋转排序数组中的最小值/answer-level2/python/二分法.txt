### 解题思路
用二分法查找,inflection point
且只能選取右邊nums[r]作爲基準..
這是由於二分法的性質決定的...
每次奇數個元素時切在中點,
偶數時候切在中點靠左位置..
且二分法最後的結果就是兩個點l和r重合

由於右邊不會越界,也不擔心無限循環,所以只能選擇nums[r]爲理想的基準點
而左邊書nusm[l]不能作爲基準點的原因是,
1.兩點的時候每次都會切到l
所以l必須動(不然就是無限循環) ,
2.l一旦開始動就會存在越界的情況,導致不能作爲基準

### 代码

```python3
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l,r = 0,len(nums)-1
        while l != r:
            m = (l+r)//2
            if nums[m] > nums[r]:#不能用nums[l]作爲基準,要麼越界要麼無線循環
                l = m+1
            else:
                r = m
        return nums[l]
```