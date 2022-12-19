思路：设之前跳的步数为pre_step，则青蛙在当前石头上可以跳的步数最多三种：pre_step-1， pre_step， pre_step+1（暂不考虑有无石头）。每跳一次都是如此，画图就能得到一个三叉树：
![leetcode_qing_wa_tiao_he.png](https://pic.leetcode-cn.com/89f7d63431461e69762c62420449c0e37cab5a6a627ce0636f49614dae1bf99d-leetcode_qing_wa_tiao_he.png)
如此便可以像二叉树那样，使用DFS搜索。
**剪枝**：图中有些选择是一样的，比如 路径1：0-1-1-1 此时有一选择(3,2)，即在第3块石头，要跳2步。在路径2：0-1-2，这里也有一个选择(3,2)。如果前面路径1已经证明走不通了，路径2这里也不该再走。

```
class Solution:
    def canCross(self, stones):
        if stones[1] > 1:
            return False
        self.stones = stones

        #: `pos_dict`字典 {第i块石头所在的格子位置：i}
        self.pos_dict = { s[1]:s[0] for s in enumerate(stones)}

        #: 集合cut用于剪枝，集合元素为`tuple(当前石头i，要走的步数s)`。
        #: 如果在cut集合，说明在当前石头，走s步到最后是走不通的，应该放弃。
        self.cut = set()

        end = len(stones)-1
        #: 假设前一步走了0步，现在在第一块石头上。
        return self.traverse(0, 0, end) 

    def traverse(self, pre_step, current, end):
        """前一次走了`pre_step`步，当前在stones中第`current`块石头上，目标是到达第`end`块石头。"""
        if current == end:
            #: 到达end
            return True

        if current < end:
            #: 三叉搜索，pre_step-1,pre_step,pre_step+1
            for step in range(pre_step-1, pre_step+2):
                if step>0 and (current,step) not in self.cut:
                    #: `nexp_pos`表示如果从第`current`块石头起跳`step`步到达的格子位置。
                    next_pos = self.stones[current] + step
                    #: 如果该位置`next_pos`有石头，就跳上去，递归。
                    next_stone_index = self.pos_dict.get(next_pos)
                    if next_stone_index:
                        r = self.traverse(step, next_stone_index, end)
                        if r != -1:
                            return r
                        self.cut.add((current, step))  # 记录下来，此路不通。

        if current == 0 :
            # 当无法到达end时，最后会回到第一块石头（树的根）
            return False   
        else:
            # 无石头能跳，该路径走到头了
            return -1 
```

---
看了官方和其他解答，模仿一个动态规划记录一下：
```
class Solution:
    def canCross(self, stones):
        dp = dict()
        for s in stones:
            dp.setdefault(s, set())
        dp.get(0).add(0)
        for s in stones:
            for pre_step in dp.get(s):
                for step in [pre_step-1, pre_step, pre_step+1]:
                    if step>0 and (s+step) in dp:
                        dp.get(s+step).add(step)
        return len(dp.get(stones[-1])) > 0
```
dp字典：key是石头所在格子数，value是走到key时的步数集合。
遍历所有石头，对于每一个石头，从此石头对应集合拿出以前走到此石头用的步数来更新它能走到的下一石头的集合。
如果最后一个石头对应的集合空，也就是没能走到最后。dp真是简洁阿。