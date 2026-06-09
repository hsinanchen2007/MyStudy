

```
from queue import PriorityQueue
class Solution:

    m = [
        (0, 0),
        (0, 1),
        (0, 2),
        (0, 3),
        (0, 4),
        (0, 5),

        (1, 0),
        (1, 1),
        (1, 2),
        (1, 3),
        (1, 4),
        (1, 5),

        (2, 0),
        (2, 1),
        (2, 2),
        (2, 3),
        (2, 4),
        (2, 5),

        (3, 0),
        (3, 1),
        (3, 2),
        (3, 3),
        (3, 4),
        (3, 5),

        (4, 0),
        (4, 1),
    ]


    def getDis(self, start, end):
        if start == '@':
            return 0

        i1, j1 = self.m[ord(start)-ord('A')]
        i2, j2 = self.m[ord(end)-ord('A')]
        return abs(i1-i2) + abs(j1-j2)

    def minimumDistance(self, word: str) -> int:
        if word == '':
            return 0

        que = PriorityQueue()

        que.put((0, 0, word[0], '@')) # 状态定义：(当前总开销， 当前最后一个字符位置，左手在的字符，右手在的字符)， 字符是@表示还没有用过这只手
        best_state = {}

        while not que.empty():
            cost, last_pos, ch1, ch2 = que.get()

            if last_pos == len(word)-1:
                return cost

            next_char = word[last_pos + 1]

            # 移动左手
            dis = self.getDis(ch1, next_char)
            if (last_pos+1, next_char, ch2) not in best_state or cost + dis < best_state[(last_pos+1, next_char, ch2)]:
                best_state[(last_pos+1, next_char, ch2)] = cost + dis
                que.put((cost+ dis, last_pos+1, next_char, ch2))

            # 移动右手
            dis = self.getDis(ch2, next_char)
            if (last_pos + 1, ch1, next_char) not in best_state or cost + dis < best_state[(last_pos + 1, ch1, next_char)]:
                best_state[(last_pos + 1, ch1, next_char)] = cost + dis
                que.put((cost+dis, last_pos + 1, ch1, next_char))

        return -1
```
