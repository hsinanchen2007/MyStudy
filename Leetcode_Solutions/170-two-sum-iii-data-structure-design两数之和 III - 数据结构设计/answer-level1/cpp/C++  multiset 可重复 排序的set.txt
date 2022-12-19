### 代码

```cpp
class TwoSum {
private:
    multiset<int> data;

public:
    TwoSum() {}

    void add(int number) {
        data.insert(number);
    }

    bool find(int value) {
        if (data.empty()) return false;

        auto p = data.begin(), q = --data.end();
        while (p != q) {
            int sum = *p + *q;
            if (sum < value) ++p;
            else if (sum > value) --q;
            else return true;
        }
        return false;
    }
};
```