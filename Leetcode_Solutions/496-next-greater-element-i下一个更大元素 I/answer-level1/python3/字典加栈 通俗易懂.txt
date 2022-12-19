![image.png](https://pic.leetcode-cn.com/e20d3e853a316b84f811aafa4b76b9e20c7616b45bcbcdd56d5859431ca10526-image.png)
思路：
dic key为nums2的元素 vlaue为元素对应索引
遍历nums1
对nums1中的每个元素，首先根据字典找到其在nums2中的位置
然后遍历nums2中该元素后面的元素，有比它大的就返回，没有就返回-1
```
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dic = {}
        result = []
        stack = []
        for i in range(len(nums2)):
            dic[nums2[i]] = i
        for i in nums1:
            stack.append(i)
            for j in nums2[dic[i]:]:
                if j > i:
                    result.append(j)
                    stack.pop
                    break
                elif j == nums2[-1]:
                    result.append(-1)
        return result
```
