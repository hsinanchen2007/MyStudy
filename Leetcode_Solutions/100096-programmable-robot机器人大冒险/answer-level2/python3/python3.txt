根据[@yanghk](/u/yanghk/)的c++题解改编的python3题解
```
class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        xy_set = set()
        xy_set.add(0)
        xx, yy = 0, 0
        # 命令循环一次，向上和向右走的总距离
        for c in command:
            if c == 'U':
                yy += 1
            else:
                xx += 1
            xy_set.add((xx << 30) | yy)

        # 到达终点需要用到的总的循环次数
        circle = min(x // xx, y // yy)
        if (x - circle * xx) << 30 | (y - circle * yy) not in xy_set:
            return False
        for o in obstacles:
            if len(o) != 2:
                continue
            if o[0] > x or o[1] > y:
                continue
            circle = min(o[0] // xx, o[1] // yy)
            if (o[0] - circle * xx) << 30 | (o[1] - circle * yy) in xy_set:
                return False
        return True
```
