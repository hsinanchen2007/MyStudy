```
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        if (cache.size() == size) {
            sum-=cache.front();
            cache.pop_front();
        }
        cache.emplace_back(val);
        sum+=val;
        return sum/static_cast<double>(cache.size());
    }

private:
    int size = 0;
    int sum = 0;
    list<int> cache;
};
```
