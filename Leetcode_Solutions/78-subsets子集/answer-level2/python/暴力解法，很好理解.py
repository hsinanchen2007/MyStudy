### 解题思路
暴力算法，遍历数组一个一个和表里的数组链接并对比是否在表里
不存在就放进表里和答案里
![image.png](https://pic.leetcode-cn.com/d9f82aa7ff7409956f763426ebdc119f2970f7bcc446f9b157b3ebc6d098388f-image.png)

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        count,res={},[]
        count[0]=[]
        res.append(count[0])
        if not nums: return res
        length=len(nums)
        index=1
        for i in range(length):
            for j in range(index):
                sub=count[j]+[nums[i]]
                if not sub in count.values():
                    count[index]=sub
                    res.append(sub)
                    index+=1
        return res
```