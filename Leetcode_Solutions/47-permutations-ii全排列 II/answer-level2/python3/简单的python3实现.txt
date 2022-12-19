
原数组中重复的元素会使全排序的结果产生重复项。

因此先对原数组进行排序（为了方便剪枝）

对数组中每一个数进行遍历，当满足条件 i>0 and nums[i] == nums[i-1] 时，就可直接continue。

本方法是将数组中被选中的元素pop()出去，所以数组一直都是处于排序的状态.


    class Solution:
        def permuteUnique(self, nums: List[int]) -> List[List[int]]:
            out = []
            temp = []
        
            def back(ns, ini):
                # 当只剩下一个元素时，直接添加
                if len(ns) == 1:
                    r = ini.copy()
                    r.append(ns[0])
                    out.append(r)
                    return

                for i in range(len(ns)):
                    if i > 0 and ns[i] == ns[i-1]:
                        continue
                    # 用于存储添加的元素的数组
                    now = ini.copy()
                    # 当前的数组
                    temp = ns.copy()
                    # 从当前数组temp中去除一个元素，并添加到now中
                    now.append(temp.pop(i))

                    back(temp, now)
        
            back(sorted(nums), temp)
        
            return out