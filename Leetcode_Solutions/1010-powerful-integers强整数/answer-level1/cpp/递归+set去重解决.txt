比迭代写起来方便一些吧
```
class Solution {
private:
    set<int> res;
public:
    void modify(int x, int y, int a, int b, int bound) {
        int r = pow(x, a) + pow(y, b);
        if (r <= bound) res.insert(r);
        else return;
        if (x != 1) modify(x, y, a + 1, b, bound);
        if (y != 1) modify(x, y, a, b + 1, bound);
    }
    vector<int> powerfulIntegers(int x, int y, int bound) {
        modify(x, y, 0, 0, bound);
        return vector<int>(res.begin(), res.end());
    }
};
```
