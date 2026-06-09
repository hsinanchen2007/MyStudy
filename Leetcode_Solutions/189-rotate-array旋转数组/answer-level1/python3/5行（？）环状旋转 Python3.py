## 思路
看了好多Python3的题解没有使用环状旋转的Python3解法，所以写了这么一个题解。

首先思路是先选数组第一项，找到它应该存放的位置。接着选中这个位置上的数，移动到它适合的位置。不难写出这样的代码：

## 初代码
```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        count,index,temp = 0,0,nums[0]
        while count < len(nums):
            count,target = count+1, (index + k) % len(nums)
            temp,nums[target] = nums[target],temp
            index = target
```
## 更多思考
仅有五行，非常简洁。然而，这样没有考虑到，下一个选择的可能是已经重复的。例如，对于[1,2,3,4]和2的参数而言，选中第一项，会移动到第三项，而选中第三项后，又要移到第一项，这样会没完没了。因此，需要作出改进，为了这一小点，代码量可能翻倍还多。实际上就是记录了已经处理过的序号，遇到死循环的，变为处理下一项。
## 完整代码
```py
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        count,index,temp = 0,0,nums[0]
        done_index = [0]
        while count < len(nums):
            count,target = count+1, (index + k) % len(nums)
            temp,nums[target] = nums[target],temp
            if target not in done_index:
                index = target
            elif target + 1 < len(nums):
                index,temp = target + 1,nums[target + 1]
            done_index.append(index)
```
## 附注
Python3 最简单的方法自然还是切片。一行搞定
```py
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        nums[:]=nums[len(nums)-k:]+nums[:len(nums)-k]
```