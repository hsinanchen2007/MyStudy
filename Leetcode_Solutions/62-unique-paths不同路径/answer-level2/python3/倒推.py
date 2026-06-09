### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        """
        倒着推导
        :param m:
        :param n:
        :return:
        """
        nums = [i for i in range(m * n)]
        # print(nums)
        # 备忘录来记录数据
        memo_dict = {0: 1}
        # 初始化  第一行与第一列的值都是1
        for i in range(1, n):
            memo_dict[i] = 1
        for i in range(1, m):
            memo_dict[i * n] = 1

        # 从nums[-1] 到nums[0]
        # 向上-m 或向左-1
        def getPointRoadNums(key):
            """
            得到某个点到0点的路径条数
            :param key:
            :return:
            """
            if memo_dict.get(key):  # 0的时候如果是0就是False了，所以初始化的时候把0的值为不是0的数
                return memo_dict.get(key)
            return getPointRoadNums(key - 1) + getPointRoadNums(key - n)

        # 初始化memo_dict
        for i in range(m * n):
            memo_dict[i] = getPointRoadNums(i)

        return memo_dict.get(m * n - 1)


```