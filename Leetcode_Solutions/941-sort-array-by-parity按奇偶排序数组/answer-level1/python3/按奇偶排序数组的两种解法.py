一、算法思想
1. 方法1
创建两个数组even，odd分别用于保存原数组中的偶数和奇数，然后遍历原数组，如果是偶数添加到even，反之添加到odd,然后返回由even和odd拼接的数组。
2. 原地解法
利用两个指针i,j分别从首尾遍历原数组，如果nums[i]为奇数，nums[j]为偶数，则交换值，反之分别自增i或者自减j，直至两指针相遇。
二、算法实现
```
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        # method1
        even = []
        odd = []
        for num in A:
            if num & 1 == 0:
                even.append(num)
            else:
                odd.append(num)
        return even + odd
        
        # # method2
        # i, j = 0, len(A) - 1
        # while i < j:
        #     while i < j and A[i] & 1 == 0:
        #         i += 1
        #     while i < j and A[j] & 1 == 1:
        #         j -= 1
        #     if i < j:
        #         A[i], A[j] = A[j], A[i]
        #         i += 1
        #         j -= 1
        # return A
```
三、复杂度分析
1.方法1
时间复杂度：O(N)，N为数组A的长度，下同。
空间复杂度：O(N)。
2.原地算法
时间复杂度：O(N)。虽然有两层循环，但指针i,j只朝一个方向移动，因此实际时间复杂度只有O(N)。
空间复杂度：O(1)。