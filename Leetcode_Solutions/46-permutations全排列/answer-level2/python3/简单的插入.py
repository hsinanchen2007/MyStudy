就是一个简单的插入操作即可。
举个例子：nums=[1,2,3], res = []
1: res = [[1]]
2: 在[1]的左右两个各插入一个数字：  res = [[2,1], [1,2]]
3: 插入左后一个数字，在res的元素中执行同样的操作： 对于res[0]在索引0之前，0和1之间和1之后插入最后一个数字-> [3,2,1,],[2,3,1],[2,1,3]。对res[1]执行同样的操作->[3,1,2],[1,3,2], [1,2,3] 得到结果。
说明：
    这个题目最大的问题是要保证不重复和不遗漏。
    1. 不重复
        因为1,2这两个数字的顺序不同，因此由[1,2]和[2,1]两个数组衍生出来的数组必定是不同的
    2. 不遗漏
        [1,2] 共有三个位置可以插入数字，各插入一次必然不会遗漏
```
    def permute(self, nums: List[int]) -> List[List[int]]:
        _len = len(nums)
        if _len <= 1: return [nums]
        res = [[nums[0]]]
        while _len > 1:
            t, a = [], nums.pop()
            for key, value in enumerate(res):
                for k, v in enumerate(value):
                    t.append(value[:k]+[a]+value[k:])
                t.append(value+[a])
            res, _len = t, _len-1
        return res
```