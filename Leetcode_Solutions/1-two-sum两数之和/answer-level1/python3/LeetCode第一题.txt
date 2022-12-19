### 解题思路

这是在LeetCode做的第一题，分享下我的解题历程。

- 1. 尝试暴力解决，结果：超出时间限制。

- 2. 先把数组按{数值: 索引}初始化字典，然后用try语句强行搜索。结果：32ms，15.2MB。
虽然用时较短，战胜了98.51%的提交结果，但用try不知道会不会出现我不知道的bug。

- 3. 用if代替try，结果：40ms，15.5MB。和2大同小异。

- 4. 使用list.index，很慢，结果：1248ms，14.1MB。

- 5. 使用numpy的矩阵运算，结果：超出内存限制。

- 6. 使用numpy的向量运算，结果：100ms，31.7MB。

- 7. 还是2的思路，不过字典初始化为空，在遍历nums的时候再一个个往字典里加，结果：48ms，14.8MB。
相比2，因为开始字典内容少，所以搜索字典的速度快了，但是多了一步添加的操作，最后结果与2差不多。

注意：
测试用例：nums = [2, 3, 3, 7]，target = 6
使用2初始化字典时，后面的3会把前面的3的索引覆盖，
初始化后的字典为：{2: 0, 3: 2, 7: 3}，
但输出结果正确。（这算特性还是bug？哈哈。）

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # dict 
        # ----------------------------------------------
        num_dict = dict(zip(nums, range(len(nums))))
        # num_dict = {}
        for i, num in enumerate(nums):
            
            # 1
            # ----------------------------
            # d = target - num
            # if d in num_dict:
            #     j = num_dict[d]
            #     if i != j:
            #         return [j, i]
            # else:
            #     num_dict[num] = i
            # ----------------------------

            # 2
            # ----------------------------
            try:
                j = num_dict[target - num]
                if i != j:
                    return [i, j]
            except KeyError:
                pass
            # ----------------------------

        # ----------------------------------------------

```