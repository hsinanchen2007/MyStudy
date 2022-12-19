### 解题思路
原数组有n个元素，子集当中每个元素有出现和不出现两种选择，因此子集总共有2^n个，处理完原数组为空的边界条件之后首先把一个空集和只有第一个元素的子集放到sub里面，然后对于nums当中除去首元素的所有新元素进行遍历：在现有sub当中的每个子集的后面分别把新元素加上，使得子集长度倍增，得到最终结果。原数组非空情况下总共进行了n次倍增操作，最终结果的长度也是2^nヾ(✿ﾟ▽ﾟ)ノ

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if not nums: return [[]]
        sub = [[], [nums[0]]]
        for i in range(1, len(nums)):
            l = len(sub)
            for j in range(l):
                sub.append(sub[j]+[nums[i]])
        return sub
```