### 解题思路
最简单的思路就是把列表中的所有元素依次遍历，如果和目标值val相同就把它从列表中删除（一开始肯定想到的是for循环，但是for循环有个问题，就是列表中的元素被删除后下一个元素替代了原先被删除元素的位置，但是for循环会把判断变量加一，这样就会导致顶上来的元素在遍历中被跳过，而使用while循环则可以完美避免这点缺陷，因为while循环的判断变量是自己设置加1的）。因此只需要设置删除元素步骤使判断变量不变，而不删除的步骤使其加一从而正常继续向下遍历其他元素。

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        while i < len(nums):
            if nums[i] == val:
                nums.remove(nums[i])

            else:
                i += 1

        return len(nums)
```