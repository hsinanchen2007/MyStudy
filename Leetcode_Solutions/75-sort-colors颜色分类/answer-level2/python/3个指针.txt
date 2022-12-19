### 解题思路

- 3个指针，r,w,b初始化为0,0,n-1，分别指向red的右侧，white的右侧，blue的左侧
- 如果w当前指向red，则交换r和w的元素，然后二者都+=1
    - 因为r在w的左侧，所以交换时，只要r<w，则r指向的只可能是white，所以交换后r+=1
- 如果w当前指向white，则w+=1
- 如果w当前指向blue，则交换b和w的元素，然后b-=1
  - 因为b在w的右侧，所以交换后，w指向的仍然可能是3种可能，所有b-=1后，w先别动
- 循环直到w到了b的右边（while w <= b）

### 代码

```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        # - sanity check
        if not nums: 
            return nums

        # - 3 pointers
        # - r: right side of red
        # - w: right white of white
        # - b: left side of blue
        r,w,b = 0,0,len(nums)-1

        while w <= b:
            if nums[w] == 0:
                if w > r:
                    nums[r], nums[w] = nums[w], nums[r]
                w += 1
                r += 1
            elif nums[w] == 1:
                w += 1
            elif nums[w] == 2:
                if w < b:
                    nums[b], nums[w] = nums[w], nums[b]
                b -= 1
```