### 解题思路
此处撰写解题思路

### 代码

```cpp
class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        for (auto row : v) {
            for (auto n : row) {
                q.push(n);
            }
        }
    }
    
    int next() {
        int ret = q.front(); q.pop();
        return ret;
    }
    
    bool hasNext() {
        return !q.empty();
    }

private:
    queue<int> q;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```