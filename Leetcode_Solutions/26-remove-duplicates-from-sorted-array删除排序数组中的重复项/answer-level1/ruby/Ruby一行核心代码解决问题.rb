
```
def remove_duplicates(nums)
    return nums.length if nums.length < 2
    (nums.length-1).downto(0) do |index|
        # 从后往前遍历数据，如果当前index的值与nums.index(num)(此num值在数组中第一次出现的index)不等，则删除此index的值
        nums.delete_at(index) if nums.index(nums[index]) != index
    end
    nums.length
end
```
