执行用时 : 184 ms, 在所有 python 提交中击败了 99.29% 的用户
内存消耗 : 13.8 MB, 在所有 python 提交中击败了 19.80% 的用户
```
class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        l = []  # 栈， 栈中元素类型为列表，格式：【nums中的数，nums中的数的位置】
        xl = []  # 保存较大元素的数组
        # 顺序遍历数组，小数出栈，大数入栈
        for i, c in enumerate(nums):
            xl.append(-1)
            while l and l[-1][0] < c:
                xl[l.pop()[1]] = c
            l.append([c, i])
        # 栈内有元素，则从栈顶到栈底， 元素的大小必定依次增大
        if l:
            j = 0
            length = len(nums)
            li = l.__len__() - 1  # 栈中元素的位置
            # 逆序遍历栈内数据（即元素由小及大）
            while li > 0:
                c, i = l[li]
                # 关键步骤，顺序查找nums数组内较栈顶大的元素，
                # 有的话则替换li数组指定的位置，记录当前的位置，并退出遍历，
                # 没有查找nums数组内较栈顶大的元素，则当前位置+1，继续查找
                while j < length and j != i:
                    if c < nums[j]:
                        xl[i] = nums[j]
                        break
                    j += 1
                li -= 1
        return xl
```
