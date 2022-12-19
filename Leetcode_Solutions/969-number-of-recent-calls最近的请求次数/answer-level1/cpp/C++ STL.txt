```c++
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        s.insert(t);
        return distance(s.lower_bound(t - 3000), s.end());
    }

private:
    set<int> s;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
```