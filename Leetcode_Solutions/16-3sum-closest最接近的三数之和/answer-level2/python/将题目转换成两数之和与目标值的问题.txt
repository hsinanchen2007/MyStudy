需要用到的变量，及其初始化值：
- `target_0`：将原始目标值另赋值给一个变量`target_0`；
- `dist`：代表和值与目标值的距离，初始化为正无穷；
- `flag`：标识位，代表和值与目标值的大小关系，若和值大于目标，则`flag = True`，小于目标则`flag = False`。
具体思路见注释：
```
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums=sorted(nums)
        target_0 = target
        # 初始化最小差值为正无穷
        dist = float('inf')
        # 标记位：表示和值比target大/小（True/False）
        flag = True
        
        for i in range(len(nums)):
            # 从第1个数开始，依次取出，更新target为target-num_1，变换题目为两数之和
            num_1 = nums[i]
            j = i + 1
            k = len(nums) - 1         
            target = target_0 - num_1

            while j < k:
                num_2 = nums[j]
                num_3 = nums[k]

                # 如果两数之和与新target相同，则与原target最接近的三个数的和即为target_0，返回target_0即可
                if num_2 + num_3 == target:
                    return target_0
                # 如果两数之和小于target，则为了使和与target接近，将j+1
                elif num_2 + num_3 < target:
                    j += 1
                    # 如果当前dist大于target - (num_2 + num_3)，更新dist
                    if dist > target - (num_2 + num_3):
                        dist = target - (num_2 + num_3) 
                        flag = False
                else:
                    k -= 1
                    if dist > (num_2 + num_3) - target:
                        dist = (num_2 + num_3) - target
                        flag = True   
       # 最后判断标识位，决定target_0与dist的加减操作
        if flag:
            return target_0 + dist
        else:
            return target_0 - dist
            
```