这个要用ide慢慢断点调试，或者画图琢磨。
```cpp []
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        move(A, B, C);
    }
    void move(vector<int>& x, vector<int>& y, vector<int>& z) {
        if (x.size() <= 1) {
            z.push_back(x.back());
            x.pop_back();
        } else {
            y.push_back(x.back());
            x.pop_back();
            move(x, y, z);
            z.push_back(y.back());
            y.pop_back();
        }
    }
};
```
```python3 []
class Solution:
    def hanota(self, A: List[int], B: List[int], C: List[int]) -> None:
        def move(x, y, z):
            if len(x) <= 1:
                z.append(x.pop())
            else:
                y.append(x.pop())
                move(x, y, z)
                z.append(y.pop())
        move(A, B, C)
```

