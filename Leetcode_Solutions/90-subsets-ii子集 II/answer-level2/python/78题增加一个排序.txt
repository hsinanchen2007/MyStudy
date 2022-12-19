### 解题思路
子集在比较前排个序，就不存在[1,4,4]和[4,4,1]不同的问题了

### 代码

```python3
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        count,res={},[]
        count[0]=[]
        res.append(count[0])
        if not nums: return res
        length=len(nums)
        index=1
        for i in range(length):
            for j in range(index):
                sub=count[j]+[nums[i]]
                sub.sort()
                if not sub in count.values():
                    count[index]=sub
                    res.append(sub)
                    index+=1
        return res

```