
1.首先，这是（1）一个数组（2）排序了的数组（3）有重复项
2，甭管他是正序还是逆序，删除重复项
3.删除数组的方式有三种，可以自行选择：（1）del根据下标删除（2）pop删除最后一个元素（3）remove根据元素值删除（很显然这不合适）  < -- 所以只能选第一二种
4.最后返回处理后的数组长度



![](https://pic.leetcode-cn.com/22f2ee8da5da9e8a741d5dcc3eccdeb65f7de93494565f7954b8b52b15888cf7-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200408092256.png)

```
    def removeDuplicates(self, nums: List[int]) -> int:
        #因为是排序数组，所以是正序或逆序
        for i in range(len(nums)-1,0,-1):
            if i>0 and nums[i-1] == nums[i]:
                nums.pop(i)
        return len(nums)
```
        