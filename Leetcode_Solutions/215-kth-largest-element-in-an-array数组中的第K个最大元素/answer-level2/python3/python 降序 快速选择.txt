```
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        '''
        题意；在nums找出第k大的数字
        思路：
        1.直接sort降序，返回nums[k-1]；sort升序，返回nums[-k]--O(NlogN)
        2.使用堆--O(NlogK)
        3.快速选择，随机选择一个index作为中枢，将小于它的都移到其前面，然后得到
          该数字是第几大数字，小于k则在其右边继续该操作，大于则在其右边继续该操作，
          直到找到第k大数字--平均O(N)，最坏O(N^2)
        
        反思与改进：
        1.之前只知道使用sort，还要了解快速选择和堆
        '''
        # 用于迭代
        def quickSelection(left, right, k):
            key_index = random.randint(left, right)
            # 先将key放到最右边
            key_num = nums[key_index]
            nums[key_index], nums[right] = nums[right], nums[key_index]
            j = left
            for i in range(left, right):
                # 如果该数大于中枢数字，放到左边；注意因为是第几大，故不要将等于也放到左边
                if nums[i]>key_num:
                    # 移动
                    nums[i], nums[j] = nums[j], nums[i]
                    j += 1
            # 将中枢数字放到j处，此时他就是第j+1大数字
            nums[j], nums[right] = nums[right], nums[j]
            if j+1 == k:
                return nums[j]
            elif j+1 > k:
                return quickSelection(left, j-1, k)
            else:
                return quickSelection(j+1, right, k)

        # 本次尝试降序快速选择
        len_n = len(nums)
        if len_n==1:
            return nums[0]
        return quickSelection(0, len_n-1, k)
        

```
