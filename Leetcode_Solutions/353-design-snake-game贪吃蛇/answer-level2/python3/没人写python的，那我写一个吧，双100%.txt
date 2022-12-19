通过一个`list`来维护蛇的身体，如果没吃到豆子就加上头去掉尾巴，吃到了就不去掉尾巴。
注意有可能刚好撞到尾巴，要小心是否撞上身体的判定和维护蛇身的操作顺序。
也可以通过`queue.Queue`来维护蛇的身体，但是问题在于`Queue`不是`iterable`，因此不好判断`if self.head in self.snake`，还需要再维护一个同步的`set`，等于`Queue`没用。。。
代码如下：
```python []
class SnakeGame:

    def __init__(self, width: int, height: int, food):
        self.snake = list()
        self.snake.append([0, 0])
        self.head = [0, 0]
        self.foods = food
        self.width = width
        self.height = height
        self.score = 0

    def move(self, direction: str) -> int:
        x, y = self.head
        if direction == 'U':
            x -= 1
        elif direction == 'L':
            y -= 1
        elif direction == 'R':
            y += 1
        elif direction == 'D':
            x += 1
        if x < 0 or y < 0 or x > self.height-1 or y > self.width - 1:
            return -1
        
        self.head = [x, y]
        self.snake = [self.head] + self.snake
        if self.foods and self.head == self.foods[0]:
            self.score += 1
            self.foods = self.foods[1:]
        else:
            self.snake = self.snake[:-1]
        if self.head in self.snake[1:]:
            return -1
        return self.score

```