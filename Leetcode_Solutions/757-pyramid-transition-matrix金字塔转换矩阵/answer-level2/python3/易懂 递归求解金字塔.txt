### 解题思路
递归求解问题首先要明确3大方向：
1）递归的求解模式的轮廓是什么样子？
2）整个递归过程的终点在哪里？
3）什么条件会触发一次递归？
（1）找到当前bottom层的上一层解，如果解均存在，则继续将bottom的上一层解作为当前bottom进行再一次的求解，否则退回到前一次递归直至上一层解均存在；退回到前一次递归并不是直接结束，而是存在着对当前位置的可能元素集合的遍历，例如，一个位置可能有3个不同元素存在的可能，则在此位置最多会触发3次遍历。
（2）根据递归的大致轮廓，可知递归完全结束的终点在于，如果金字塔存在，那么递归一定能遍历到塔尖然后返回True；否则，递归会一直进行，直到当前bottom的所有位置上的所有元素的可能全部遍历完成，最终得出金字塔不存在的解。
（3）此求解方法中，递归包含在遍历中，每次遍历都触发一次递归，从这个角度来看，符合深度优先的思想。
### 代码实现思路
代码实现和解题思路有时会产生微妙的差距感，需要灵活应对。
在每次得到上一层解的过程，是一个可能集合的构造过程，其中存在着当前层构造结束时的处理方法和技巧
### 代码

```python3
from collections import defaultdict
from typing import List


class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        # 将allowed集合转换为字典便于索引与操作
        allow = defaultdict(list)
        for item in allowed:
            allow[item[:2]].append(item[2])
        # 从bottom的第一个元素开始深度遍历
        return self.deepFirstSearch(bottom, allow, 0)

    def deepFirstSearch(self, bottom: str, allow: defaultdict, index: int) -> bool:
        if index == len(bottom) - 1:
            # print('索引到达边界，在此层基础上进行循环')
            index = 0
            bottom = bottom[: -1]
        # bottom只剩下一个元素，则深度搜索结束，求解成功
        if len(bottom) <= 1:
            return True
        # bottom某相邻两元素不满足allow的条件，求解失败
        if bottom[index: index+2] not in allow.keys():
            # print(bottom[index: index+2] + '两元素不满足条件')
            return False
        for item in allow[bottom[index: index+2]]:
            # print('开始进行循环,bottom为{0},item为{1}'.format(bottom, item))
            _bottom = bottom[: index] + item + bottom[index+1:]
            # print('改造后，bottom为{0}，继续放入循环'.format(_bottom))
            if self.deepFirstSearch(_bottom, allow, index+1):
                # print('此次总循环结束，满足条件, bottom为', _bottom)
                return True
            # print('不满足条件,一次循环结束,_bottom为{0},item为{1}'.format(_bottom, item))
        # print('此次总循环结束，bottom中存在不满足条件, bottom为', bottom)
        return False
```