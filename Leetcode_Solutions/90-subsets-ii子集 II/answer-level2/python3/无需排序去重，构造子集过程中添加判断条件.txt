### 解题思路

如果无重复元素，遍历nums每个元素，每个元素分为两种情况（存在或不存在），子集共2^n个；
如果有重复元素，在遍历nums每个元素，判断当前子集是否已包含该元素：
若不包含则依旧分为两种情况，存在或者不存在；
若包含则只有存在这种情况。
举例如下图所示：

![微信图片.jpg](https://pic.leetcode-cn.com/0720bcc757e4aa8dad677219cbc90b8018680c81e32308671e277d28cd02a977-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87.jpg)


### 代码

```python3
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        sets=[]
        L=len(nums)
        def back(i,Ln):
            if i==L:
                sets.append(Ln)
                return 
            if nums[i] not in Ln:
                back(i+1,Ln+[nums[i]])
                back(i+1,Ln)
            else:
                back(i+1,Ln+[nums[i]])
        back(0,[])
        return sets
```