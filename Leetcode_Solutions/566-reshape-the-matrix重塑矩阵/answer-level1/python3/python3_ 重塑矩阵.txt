```python
def matrixReshape(nums, r, c):
    if len(nums) * len(nums[0]) != r * c:
        return nums
    r, sub_r = [], []
    # 遍历二维数组
    for i in range(len(nums)):
        for j in range(len(nums[0])):
            sub_r.append(nums[i][j])
            if len(sub_r) == c:
                r.append(sub_r)
                sub_r = []
    return r

print(matrixReshape([[1,2],[3,4]], 1, 4))
```