# ### 解题思路
# 个人愚钝，没有捋清思路，在此复述，仅做个人学习理解，有错误的地方还请指正，谢谢。

# - 首先需要确定的是，两个水壶不可能同时处于未满状态；
# - 在题目要求条件下，可以执行的操作有：
#   - 装满X或者Y水壶；
#   - 清空X或者Y水壶；
#   - 将X水壶中的水倒入Y水壶，倒入的水量，取决于Y水壶的剩余容量以及X水壶的现有水量；
#   - 同理，将Y水壶中的水倒入X水壶，倒入的水量，则取决于X水壶的剩余容量以及Y水壶的现有水量；
# - 每一轮我们都有上述可执行的操作可供选择，所以我们遍历这所有的操作，并将操作纳入访问记录表(避免重复)，这样依次尝试，即可得到想要的结果


# 感谢[官方题解](https://leetcode-cn.com/problems/water-and-jug-problem/solution/shui-hu-wen-ti-by-leetcode-solution/)及[力友“Sweetiee 🍬”](https://leetcode-cn.com/problems/water-and-jug-problem/solution/javade-bfsxie-fa-by-sweetiee/)的代码参考

# ### 代码

# ```python3
class Solution:

    def check(self, x, y):
        if (x, y) not in self.visited:
            self.queue.append((x, y))
            self.visited.add((x, y))
        pass

    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z == 0 or x+y==z:
            return True

        remian_x, remian_y = 0, 0
        self.queue = [(remian_x, remian_y)]
        self.visited = set()
        self.visited.add((0, 0))
        while self.queue:
            cur_x, cur_y = self.queue.pop(0)
            if cur_x+cur_y == z:
                return True
            # fill x
            self.check(x, cur_y)
            # fill y
            self.check(cur_x, y)

            # clear x
            self.check(0, cur_y)
            # clear y
            self.check(cur_x, 0)

            # fill y from x
            cnt = min(cur_x, y-cur_y)
            self.check(cur_x-cnt, cur_y+cnt)
            # fill x from y
            cnt = min(x-cur_x, cur_y)
            self.check(cur_x+cnt, cur_y-cnt)
        
        return False
# ```