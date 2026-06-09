 **思路：**
    从后向前遍历，定位后大前小位置i，i-1为需要替换位置，以该位置为分界点，i-1之前位置为高位保持不动；
    i-1位：使用后半段中大于该位数值的最小值替换，后半段数值集合添加替换下来的i-1位数值，并remove little_max
    i以后：排序生成最小数值，更新原数组后半段
**实例**
![微信图片_20191106174441.jpg](https://pic.leetcode-cn.com/2923fcc5a0ffde4bde3c5efcb69b498d0df33e7f10af91eda995e7b54bd37cd2-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191106174441.jpg)
**代码**
```
def nextPermutation(nums):
    """
    :type nums: List[int]
    :rtype: None Do not return anything, modify nums in-place instead.
    """
    if not nums:
        return
    i = len(nums)-1
    while i > 0:
        # print(i)
        if nums[i] > nums[i-1]:
            temp = nums[i:]

            little_max = min([num for num in temp if num > nums[i-1]])      # 比高位大的最小值
            # 替换
            temp.append(nums[i-1])
            nums[i-1] = little_max
            temp.remove(little_max)
            # 划分数组，后半段排序
            temp.sort()
            for j in range(i, len(nums)):
                nums[j] = temp[0]
                temp.remove(temp[0])
            break
        else:
            i -= 1
    if i == 0:
        nums.reverse()
```
