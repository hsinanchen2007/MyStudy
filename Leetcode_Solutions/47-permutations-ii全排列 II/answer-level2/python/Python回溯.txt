对于某一层，交换以前交换过的两个值得到的结果是重复的
因此对于某一层，保存交换过的值，如果没有交换过就执行交换操作，否则不执行
```
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        count = len(nums)
        def find(now_index):
            if now_index == count:
                result.append(nums+[])
            else:
                temp_set = set()  # 保存以前交换过的值
                for index in range(now_index, count):
                    if not (nums[now_index], nums[index]) in temp_set:  # 以前没有交换过
                        temp_set.add((nums[now_index], nums[index]))
                        nums[now_index], nums[index] = nums[index], nums[now_index]
                        find(now_index+1)
                        nums[now_index], nums[index] = nums[index], nums[now_index]
        find(0)
        return result
```
