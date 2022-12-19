> 感觉官方题解不够巧妙，遂写下

## 思路
+ 建立一个空的哈希表和一个空的列表，列表存放答案
+ 哈希表的键存放nums1的数，值为出现次数（也可以自定义为别的数，只要不是None即可）
+ 遍历nums2，如果nums2的值出现在哈希表的键当中，那么把它放到答案的列表中，同时哈希表的值设为None
+ 返回列表
## 代码
```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hash_dict = {}
        ans = []
        for i in nums1:
            if hash_dict.get(i) is None:
                hash_dict[i] = 1
        for j in nums2:
            if hash_dict.get(j) is not None:
                ans.append(j)
                hash_dict[j] = None
        return ans
```