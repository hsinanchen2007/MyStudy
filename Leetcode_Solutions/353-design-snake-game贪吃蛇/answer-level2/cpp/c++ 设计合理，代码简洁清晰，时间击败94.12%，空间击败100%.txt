```
class SnakeGame {
public:
    struct Point{
        int x;
        int y;
        bool operator == (const Point& p){
            return x == p.x && y == p.y;
        }
    };
    int w, h;
    int score;
    queue<vector<int>> foods;
    queue<Point>       body_pos;
    unordered_set<int> body_set;
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        for(int i = 0; i < food.size(); ++i){
            foods.push(food[i]);
        }
        w = width;
        h = height;
        score   = 0;
        Point p = {0, 0};
        push_head(p);
    }
    
    int hash(Point& p){
        return p.x*w + p.y;
    }
    
    void push_head(Point& p){
        body_pos.push(p);
        body_set.insert(hash(p));
    }
    
    void pop_tail(){
        body_set.erase(hash(body_pos.front()));
        body_pos.pop();
    }
    
    bool is_crossing(Point& p){
        return (p.x >= h || p.x < 0 || p.y >= w || p.y < 0);
    }
    
    bool is_collision(Point& p){
        return body_set.count(hash(p));
    }
    
    bool is_food(Point& p){
        return (!foods.empty() && p.x == foods.front()[0] && p.y == foods.front()[1]);
    }
    
    void add_score(Point& p){
        foods.pop();
        push_head(p);
        score++;
    }
    
    Point head_pos(string& direction){
        Point p = body_pos.back();
        if(direction == "R")
            p.y += 1;
        if(direction == "L")
            p.y -= 1;
        if(direction == "D")
            p.x += 1;
        if(direction == "U")
            p.x -= 1;
        return p;
    }
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        Point p = head_pos(direction);
                
        if(is_crossing(p)) return -1;
        if(is_food(p)){
            add_score(p);
            return score;
        }
        pop_tail();
        if(is_collision(p))
            return -1;
        push_head(p);
        return score;
    }
};
```
