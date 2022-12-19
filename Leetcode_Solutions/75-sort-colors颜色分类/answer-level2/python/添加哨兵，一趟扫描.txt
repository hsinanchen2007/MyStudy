方法一：分别找出各种颜色数量，重新生成列表
```
def sortColors(self, nums):
    count0 = nums.count(0)
    count1 = nums.count(1)
    count2 = nums.count(2)
    # 注意nums[:]与nums的区别 
    nums[:] = [0]*count0 + [1]*count1 + [2]*count2
```
方法二：在原始列表最后添加“#”作为哨兵，从前向后扫描，遇0指针后移，遇到非0数字后移，1后移到哨兵后，2在末尾添加。
        指针移动到“#”完成扫描。
```
def sortColors(nums):
    nums.append("#")
    i = 0
    while nums[i] != '#':
        # 0时列表不变，向后查找其他颜色
        if nums[i] == 0:    
            i += 1
            continue
        # 非0弹出，根据颜色种类插入
        color = nums.pop(i)    
        if color == 2:
            nums.append(color)
        # 在“#”后插入，否则陷入死循环
        if color == 1:
            nums.insert(nums.index("#")+1, color)       
    nums.remove("#")
```
