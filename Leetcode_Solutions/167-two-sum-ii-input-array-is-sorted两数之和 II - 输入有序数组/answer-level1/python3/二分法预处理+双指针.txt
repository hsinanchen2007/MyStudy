### 解题思路
1. **二分法预处理步骤**
在进行正常的双指针操作之前，可以对numbers进行一次压缩处理，目的是将过大的尾部去除。
比如[1,2,3,5,6,7,8],4
显然这个数组只有[1,2,3]可能出现解答，因此使用二分法将满足numbers[0]+numbers[i]>target的第i位以后的数据剔除数组，再对新的数组使用双指针法求解。
因为数组只是升序排列而不限制是非负，所以不能找满足numbers[i]>target的i，而要找numbers[0]+numbers[i]>target。
采用二分法预处理之后，使用python3的解答时间约降低6-8ms
2. **双指针法**
设置一个左指针left指向数组左边，右指针right指向数组右边。
若numbers[left]+numbers[right]>target，则说明两数之和太大，将右指针向左移一位，减小两数之和；
若numbers[left]+numbers[right]<target，则说明两数之和太小，将左指针向右移一位，增加两数之和，

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        mid = right
        while left < right:
            mid = right + left >> 1
            if target > numbers[mid] + numbers[0]:
                left = mid + 1
            elif target < numbers[mid] + numbers[0]:
                right = mid - 1
            else:
                right = mid
                break;
        numbers = numbers[0:right + 1]
      
        left=0
        right=len(numbers)-1
        while left<right:
            if numbers[left]+numbers[right]==target:
                return [left+1,right+1]
            elif numbers[left]+numbers[right]<target:
                left+=1
            else:
                right-=1
        return []


```