### 解题思路
荷兰国旗包含三种颜色：红、白、蓝。

有三种颜色的球，算法的目标是将这三种球按颜色顺序正确地排列。它其实是三向切分快速排序的一种变种，在三向切分快速排序中，每次切分都将数组分成三个区间：小于切分元素、等于切分元素、大于切分元素，而该算法是将数组分成三个区间：等于红色、等于白色、等于蓝色。

三个指针p0,curr,p2
p0在头，p2在尾，cur指针移动用来找0&2
1.找到0，跟po的数交换，cur,p0往右移一位
2.找到2，根p2的数交换，curr不动，p2往左移一位
（从p2交换过来的数curr还未扫描，所以curr不++）

![391d94d828bb6336c9a3fb2d59ae0c34791902a85577810480433b873869b5ea_荷兰国旗_动态图.gif](https://pic.leetcode-cn.com/e113b11711b39820415bbcb6ec3658c457d9d326b06882ac722bd348b3440349-391d94d828bb6336c9a3fb2d59ae0c34791902a85577810480433b873869b5ea_%E8%8D%B7%E5%85%B0%E5%9B%BD%E6%97%97_%E5%8A%A8%E6%80%81%E5%9B%BE.gif)


### 代码

```python
class Solution(object):
    def sortColors(self, nums):
        p0,curr,p2=0,0,len(nums)-1
        while curr<=p2:
            if nums[curr] == 0:
                nums[curr],nums[p0] = nums[p0],nums[curr]
                p0 += 1
                curr += 1
            elif nums[curr] == 2:
                nums[curr],nums[p2] = nums[p2],nums[curr]
                p2 -= 1
            else:
                curr += 1
```