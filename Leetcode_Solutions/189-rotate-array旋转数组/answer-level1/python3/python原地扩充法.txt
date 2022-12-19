#### 思路
把原本在前面，旋转后在后面的几个元素增加在数组最后
然后原本剩下的部分加上新增的一起向前移动到顶
最后删除最后面多余的元素
#### 代码
```
class Solution(object):
    def rotate(self, nums, k):
        lens = len(nums)
        k = k % lens
        for i in range(lens-k):  #添加项到数组尾部
            nums.append(nums[i])
        for i in range(lens):    #向前移
            nums[i] = nums[i+(lens-k)]
        lenss = len(nums)        #删掉多余的项
        for i in range(lens,lenss):
            nums.pop(lens)
```

