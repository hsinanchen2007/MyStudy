```class SnakeGame {
    Set<Integer> screen;
    Queue<Integer> body;

    int[][] foods;
    int foodIndex;
    int head;
    int width;
    int height;

    /**
     * Initialize your data structure here.
     *
     * @param width  - screen width
     * @param height - screen height
     * @param food   - A list of foods positions
     *               E.g foods = [[1,1], [1,0]] means the first foods is positioned at [1,1], the second is at [1,0].
     */
    public SnakeGame(int width, int height, int[][] food) {
        this.head = 0;
        screen=new HashSet<>();
        body = new LinkedList<>();
        screen.add(head);
        body.offer(head);

        this.foods = food;
        this.width = width;
        this.height = height;
        foodIndex = 0;
    }

    /**
     * Moves the snake.
     *
     * @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
     * @return The game's score after the move. Return -1 if game over.
     * Game over when snake crosses the screen boundary or bites its body.
     */
    public int move(String direction) {
        int newHead = head;
        switch (direction) {
            case "U":
                if (head< width) return -1;
                newHead -= width;
                break;
            case "D":
                if (head >= width * (height - 1)) return -1;
                newHead += width;
                break;
            case "L":
                if (head % width == 0) return -1;
                newHead--;
                break;
            case "R":
                if ((head + 1) % width == 0) return -1;
                newHead++;
                break;
        }


        if (foodIndex < foods.length && (foods[foodIndex][0] * width + foods[foodIndex][1]) ==newHead) {
            foodIndex++;
        } else {
            int tail = body.remove();
            screen.remove(tail);
        }

        if (screen.contains(newHead)) {
            return -1;
        }

        screen.add(newHead);
        body.offer(newHead);
        head = newHead;
        return body.size() - 1;
    }
}
```
