将非负元素n放置到索引n-1的位置。然后遍历找出索引i的位置值不是i+1的元素返回即可。

这里几个操作如下：
1. 第一次遍历，将负数和大于数组长度的值全都置为0；
2. 如果索引index上的值为index+1或者为0，则说明已经处理或者不需要调整了；
3. 将索引index上的值a放置到正确的位置上，也就是索引a-1的位置；这个时候需要注意的是，如果此时在索引a-1的位置值已经是a了，说明已经调整好了，这个时候就不需要再进行交换了。直接将索引为index处的值置为0；

经过上述的步骤，已经将元素i放置到了索引为i-1的位置；那么有两种情况：
- 如果数组里面有0， 说明数组里面没有该数字，这个时候只需要遍历一次，找出第一个索引为index的元素，返回index+1即可。
- 如果数组里面没有0，说明本身就是已经好的，比如[1,2,3,4,5],则只需要返回数组的长度n+1即可。

```
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        index = 0
        n = len(nums) # 数组长度
        while index < n:
            if nums[index] == index + 1 or nums[index] == 0: # 已经调整好了
                index += 1
                continue
            if nums[index] < 0 or nums[index] > n: # 将小于0和大于n的数全都改为0
                nums[index] = 0
                index += 1
                continue
            else:
                if nums[nums[index] - 1] == nums[index]:
                    nums[index] = 0
                else:
                    temp = nums[nums[index] - 1]
                    nums[nums[index] - 1] = nums[index]
                    nums[index] = temp
        index = 0
        while index < n:
            if nums[index] != index + 1: # 已经调整好了
                return index + 1
            index += 1
        return n + 1
```
