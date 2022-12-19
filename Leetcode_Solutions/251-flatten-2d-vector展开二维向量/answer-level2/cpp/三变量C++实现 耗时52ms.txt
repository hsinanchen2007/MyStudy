### 解题思路
首先我们需要保存这个二维向量，同时我们需要知道当前在访问哪一行哪一列，所以共有三个变量：

- `vec` 用于保存二维向量
- `r` 用于表示当前所在的行
- `c` 用于表示当前所在的列

二维向量中可能包含一些空行，我们使用`skipBlank()`这个函数跳过空行：

```cpp
void skipBlank() {
    while (r < vec.size() && vec[r].empty()) {
        r++;
        c = 0;
    }
}
```

`skipBlank()`需要在`next()`和`hasNext()`之前调用一次。在题目描述中我们被保证`next()`的调用总是有效的，每次访问完元素，我们增加`c`，
需要判断一下刚访问的元素是否这一行最后一个元素，如果是这样，我们移动到下一行的开头。

`hasNext()`的实现是不言自明的，我们在跳过空行后，判断`r`和`c`是否在有效的范围内即可。

### 代码

```cpp
class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) : r(0), c(0), vec(v) {
    }
    
    int next() {
        skipBlank();
        int val = vec[r][c];
        c++;
        if (c == vec[r].size()) { // we are accessing the last element at row r
            r++;
            c = 0;
        }
        return val;
    }
    
    void skipBlank() {
        while (r < vec.size() && vec[r].empty()) {
            r++;
            c = 0;
        }
    }
    
    bool hasNext() {
        skipBlank();
        return r < vec.size() && c < vec[r].size();
    }
private:
    int r;
    int c;
    vector<vector<int>> vec;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```