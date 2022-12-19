### 解题思路
根据题意：假设结果有元素A，A在列表1中出现3次，在列表2中出现2次，则A在结果中只能出现2次

用哈希表，也就是字典，记录列表1中所有元素出现的次数
遍历列表，如果2中元素也出现，检查它出现的次数，每次检查就给字典对应元素-1
如果键-值已经到0，则再出现的元素也不能被记入答案（参考 “根据题意”）
代码如下：
### 代码

```python3
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        Hashmap={}
        res=[]
        for i in nums1:
            if i not in Hashmap:
                Hashmap[i]=1
            elif i in Hashmap:
                Hashmap[i]+=1
        for i in nums2:
            if i in Hashmap and Hashmap[i]!=0:
                res.append(i)
                Hashmap[i]-=1
            elif i in Hashmap and Hashmap[i]==0:
                continue
            elif i not in Hashmap:
                continue
        return res
```