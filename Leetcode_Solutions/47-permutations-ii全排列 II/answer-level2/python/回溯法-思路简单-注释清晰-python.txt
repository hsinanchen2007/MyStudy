思路：
    1. 首先画出题目的树状结构图，可以发现，回溯过程中重复的部分都是每一层中相同元素以及以其为节点的子树
    2. 树状图请参照官方给定的题解中的图片
    3. 所以很容易的想到，每层遍历的时候维护一个字典，该字典用于检校元素重复与否

代码如下：
```
import copy
def calculate(tmp_dict, result, tmp, nums):
    length = len(nums) # 
    if length == 1: # 边界条件，当到达叶子节点的时候
        tmp.append(nums[0]) # 保存经过该节点的痕迹
        result.append(copy.deepcopy(tmp)) # 用深拷贝，因为tmp是列表，使用的是引用传递
        tmp.pop() # 消除经过该节点的痕迹
        return 
    elif length > 1:
        for i in range(length): #　依次经过给定的数据域
            save = nums[i]
            if tmp_dict.get(save) is None:　＃ 字典中没有该元素说明该元素未重复
                tmp.append(save) # 保存痕迹
                del nums[i] # 使得元素不能重复选
                calculate({}, result, tmp, nums) 
                nums.insert(i, save) # 恢复数据域
                tmp.pop() # 消除痕迹
                tmp_dict[nums[i]] = True # 说明该元素使用过了

class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]

        """
        tmp_dict = {}
        result = []
        tmp = []
        calculate(tmp_dict, result, tmp, nums) # tmp_dict维护的字典，result保存最后结果，tmp保存每次到叶子节点构成的路径
        return result
```
