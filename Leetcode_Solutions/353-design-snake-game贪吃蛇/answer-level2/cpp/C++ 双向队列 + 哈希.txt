```C++ []
class SnakeGame {
public:
    int W;
    int H;
    int N;
    int i;
    int score;
    int status;
    vector<vector<int> > foods;
    unordered_set<int> bodies;
    deque<pair<int, int> > snake;
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        W = width;
        H = height;
        N = food.size();
        i = 0;
        score = 0;
        status = 1;
        foods = food;
        snake.push_back({0, 0});
        bodies.insert(0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    bool valid(int w, int h) {
        if (w < 0 || w >= W || h < 0 || h >= H) return false;
        int t = w * H + h;
        if (bodies.count(t)) return false;
        return true;
    }

    void oneStep(char d) {
        auto tail = snake.front();
        auto head = snake.back();
        snake.pop_front();
        bodies.erase(tail.first * H + tail.second);
        int w = head.first;
        int h = head.second;
        if (d == 'U') {
            --h;
        } else if (d == 'L') {
            --w;
        } else if (d == 'R') {
            ++w;
        } else {
            ++h;
        }
        if (!valid(w, h)) {
            status = -1;
            return;
        }
        if (i < foods.size() && h == foods[i][0] && w == foods[i][1]) {
            ++score;
            ++i;
            snake.push_front(tail);
            bodies.insert(tail.first * H + tail.second);
        }
        snake.push_back({w, h});
        bodies.insert(w * H + h);
    }
    int move(string direction) {
        for (auto c : direction) {
            oneStep(c);
            if (status == -1) {
                return -1;
            }
        }
        return score;
    }
};
```

![image.png](https://pic.leetcode-cn.com/a33d4246c8d025a314bed49066b0215c26448bf0e86b31764c1aaf34d8f5b05a-image.png)
