### 解题思路
外层一次遍历，内层对外层每次遍历需要寻找的差进行二分查找。

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i,num in enumerate(numbers):
            t = target-num
            left=i+1
            right = len(numbers)-1
            while left<=right:
                mid=left+(right-left)//2
                if numbers[mid]>t:
                    right=mid-1
                elif numbers[mid]==t:
                    return [i+1,mid+1]
                else:
                    left = mid+1
```
![image.png](https://pic.leetcode-cn.com/f8d150524208271ffd5c2e957eef6e29c5397028abff09c67e496905f539a1dc-image.png)
