```python
def merge(nums):
    """
        1. 判断区间是否有交集的方法是: [a, b], [c, d], 只要a <= d and b >= c即可.
        2. 两次遍历数组, 将第i个元素和 i + 1 ~ N的元素进行合并, 然后继续执行i+1的遍历.
        3. 要将被合并的元素删除.
    """
    i, N = 0, len(nums)
    while i < N:
        del_indexs = []
        for j in range(i+1, len(nums)):
            # 找到合并的区间, 进行合并
            if nums[i][0] <= nums[j][1] and nums[i][1] >= nums[j][0]:
                nums[i] = [min(nums[i][0], nums[j][0]), max(nums[i][1], nums[j][1])]
                del_indexs.append(j)
        # 将被合并的区间删除
        if del_indexs:
            # 如果存在被合并的区间, 那么合并的元素要重新进行合并判断
            i -= 1
            nums = [n for i, n in enumerate(nums) if i not in del_indexs]
        i += 1
    
    return nums

print(merge([[1,3],[2,6],[8,10],[15,18]]))
print(merge([[2,3],[4,5],[6,7],[8,9],[1,10]]))
```