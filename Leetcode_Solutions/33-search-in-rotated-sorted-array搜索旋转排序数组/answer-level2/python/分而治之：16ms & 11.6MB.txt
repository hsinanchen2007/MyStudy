### 解题思路
要求复杂度是log n，所以必须分而治之
主要思路：
1. 考虑到由首末两个数可以判断该数组是否为严格升序，且对于n>3时，[left,mid]和[mid,right]中必有一个严格升序，另一个有逆序存在。
2. 若[left,mid]严格升序，则用二分法寻找target是否存在；若不存在，则left = mid，再次进入循环；反之亦然
3. 直观而言，每次循环，要么找到目标值，要么舍去一半的数组。
4. 故复杂度是 log n
注意事项：
1. 二分法注意 目标值比数组最小值还小，或者比最大值还大的情况
运行结果：
1. 16 ms, 在所有 Python 提交中击败了99.69%的用户
2. 11.6 MB, 在所有 Python 提交中击败了100.00%的用户

### 代码

```python
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        def search_erfen(nums,left,right,target):
            if(left > right):
                return -1
            elif(left == right):
                if(nums[left] == target):
                    return left
                else:
                    return -1
            elif(left < right):
                if (target < nums[left] or nums[right] < target):
                    return -1
                while(left < right):
                    mid = int((left + right)/2)
                    if(nums[mid] < target):
                        left = mid
                        if(right == left + 1):
                            if(nums[right] == target):
                                return right
                            else:
                                return -1
                    elif(nums[mid] > target):
                        right = mid
                    elif(nums[mid] == target):
                        return mid

        left = 0
        right = len(nums)-1
        if(left > right):
            return -1
        elif(left == right):
            if(nums[left] == target):
                return left
            else:
                return -1
        elif(left < right):
            while(left < right):
                if(right == left+1):
                    if(nums[left] == target):
                        return left
                    elif(nums[right] == target):
                        return right
                    else:
                        return -1

                mid = int((left + right)/2)
                if(nums[mid] < nums[right]):
                    ans = search_erfen(nums,mid,right,target)
                    if (ans != -1):
                        return ans
                    right = mid
                elif(nums[left] < nums[mid]):                   
                    ans = search_erfen(nums,left,mid,target)
                    if (ans != -1):
                        return ans
                    left = mid
            



```