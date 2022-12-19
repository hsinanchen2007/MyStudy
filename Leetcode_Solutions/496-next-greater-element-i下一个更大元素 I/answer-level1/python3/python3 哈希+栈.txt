哈希表`d`用来记录nums2中每个元素的下个更大的元素，栈`stack`从栈顶向下逆序排序

1. 将nums2[-1]压入栈，并且d[nums2[-1]] = -1, 因为该元素已经是最后一个元素了，不存在下个元素比他大
2. 从nums2倒数第二个元素开始逆序遍历，依次比较该元素和栈顶元素之间的大小，
    1. 如果栈不为空，比较栈顶元素和该元素的大小，如果栈顶元素比较小，退栈，直至退到栈顶元素大于该元素或者栈空为止；
    2. 更新哈希表，如果栈不空则当前元素的更大元素是栈顶元素，否则就是-1
    3. 当前元素入栈

```py3
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if not nums2:
            return []
        d  = {}
        d[nums2[-1]] = -1
        ans = []
        stack = [nums2[-1]]
        for i in range(len(nums2) - 2, -1, -1):
            while stack and stack[-1] <= nums2[i]:
                stack.pop()
            if not stack:
                d[nums2[i]] = -1
            else:
                d[nums2[i]] = stack[-1]
            stack.append(nums2[i])
        for num in nums1:
            ans.append(d[num])
        return ans

```