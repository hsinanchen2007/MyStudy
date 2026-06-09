### 解题思路
-   使用队列保存蛇的身体
-   每次判断前进的步伐是否还在屏幕上面
-   如果还有食物，判断能否吃到食物
-   如果没有食物或不能吃到食物，蛇需要前进，将尾部节点移除，然后判断下一个节点能否撞到身体，撞到则返回`-1`
-   将下一个节点加入蛇的身体

这里判断的关键点在于，先移除蛇的尾部，再判断蛇头会不会撞到

### 代码

```python
from collections import deque


class SnakeGame:

    def __init__(self, width: int, height: int, food: List[List[int]]):
        """
        Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0].
        """
        self.row = height
        self.col = width
        self.food = food
        self.food_pos = 0
        self.snake = deque([(0, 0)])
        self.snake_set = {(0, 0), }

    def move(self, direction: str) -> int:
        """
        Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body.
        """

        # 坐标验证
        def available(m, n):
            return 0 <= m < self.row and 0 <= n < self.col

        snake_head = self.snake[-1]
        next_pos = [-1, -1]

        if direction == "U":
            next_pos = [snake_head[0] - 1, snake_head[1]]
        elif direction == "D":
            next_pos = [snake_head[0] + 1, snake_head[1]]
        elif direction == "L":
            next_pos = [snake_head[0], snake_head[1] - 1]
        elif direction == "R":
            next_pos = [snake_head[0], snake_head[1] + 1]

        if not available(*next_pos):
            return -1

        # eat food ?
        if self.food_pos < len(self.food) and next_pos == self.food[self.food_pos]:
            self.food_pos += 1
        else:
            self.snake_set.remove(self.snake.popleft())

        if tuple(next_pos) in self.snake_set:
            return -1

        self.snake.append((next_pos[0], next_pos[1]))
        self.snake_set.add((next_pos[0], next_pos[1]))

        return self.food_pos
# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)
```