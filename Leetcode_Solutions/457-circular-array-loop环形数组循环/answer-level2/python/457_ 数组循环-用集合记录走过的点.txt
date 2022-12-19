
实现思路：
循环1：以数组的每个点为起点，开始循环。
循环2：将路径点加入到set中，并更新新的位置
判断set中的路径是否有效：
    (1)出现反向时，路径无效
    (2)循环长度为1时，路径无效
    (2)循环长度>1, 且出现环, 路径有效

```
class Solution(object):
    def circularArrayLoop(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        n = len(nums)
        for start in range(n):  # 从每个点开始
            s = set()  # 集合记录走过的点
            pos = start  # 当前位置
            posLast = pos  # 上次的位置
            flag = 0  # 标志位
            while pos not in s:  # 未出现环，便继续循环
                flag = 1
                s.add(pos)
                posLast = pos
                pos = (pos + nums[pos] + n) % n  # 新的位置
                if nums[pos] * nums[start] < 0:  # 出现反向，则无效
                    flag = 2
                    break
            if pos == posLast:  # 循环长度为1时，路径无效
                continue
            if len(s) > 1 and flag == 1:  # 循环长度>1, 且出现环
                return True

        return False
```
