```python
class RangeNode:

    def __init__(self, i=None, j=None):
        self.begin = i
        self.end = j
        self.next = None

    def __add__(self, other):
        if self.begin is None:
            return other

        node = self
        while node.next:
            node = node.next

        if node.end == other.begin:
            node.end = other.end
        # 若相交则raise该异常，或者返回个特殊值，我懒得写if了= =
        elif node.end > other.begin:
            raise ValueError('intersected')
        else:
            node.next = other
        return self

    def __eq__(self, other):
        while self and other:
            if (self.begin, self.end) != (other.begin, other.end):
                return False
            self, other = self.next, other.next
        return not self and not other


class Solution:
    def isRectangleCover(self, rectangles) -> bool:
        # 每个矩形的起始点和终止及其高度，终止点的高度为负数
        points = ([(x1, y1, y2-y1) for x1, y1, _, y2 in rectangles]
                  + [(x2, y2, y1-y2) for _, y1, x2, y2 in rectangles])
        points.sort(reverse=True)
        first_time = True

        try:
            while points:
                cur = points[-1][0]
                to_add, to_sub = RangeNode(), RangeNode()

                while points and points[-1][0] == cur:
                    x, y, h = points.pop()

                    if h > 0:
                        to_add = to_add + RangeNode(y, y+h)
                    else:
                        to_sub = to_sub + RangeNode(y+h, y)

                # 只用在第一次扫描之后判断每次扫描增加的区间和减少的区间是否相同
                if first_time:
                    first_time = False
                    if to_add.next:
                        return False
                elif to_add != to_sub and points:
                    return False

        except ValueError:
            return False

        return True
```