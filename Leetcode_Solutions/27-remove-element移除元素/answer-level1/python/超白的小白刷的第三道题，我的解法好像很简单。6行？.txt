本二大三学生，学习一般，对编程感兴趣，因为想去大厂，无意之间知道了力扣，这是我刷的第三道题，因为全是自学的编程，很多地方考虑不周，请大神多多担待，多多指教。
我的代码耗时20ms，消耗内存11.8m,我也不知道是啥水平，真超级雪白的小白。
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        p=0
        while(p<len(nums)):
            if nums[p]！=val:
                p+=1
            else:
                nums.pop(p)
用一个while循环然后用一个指针？我也不知道，暂且就叫他一个指针吧，不，单指针！
从0开始，遍历数组。
如果指针p的值不等于val，那么p后移一位，如果等于val，就pop删了他，这时候p指针还是0(因为没有赋值，while循环还满足，哈哈)，数组整体迁移了一位？接着判断嘛！等于就删，不等于就往后走嘛，挺简单的哈。
各位大佬轻喷！