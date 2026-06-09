
```
class MyCalendarThree {
public:
    MyCalendarThree() {
        m.clear();
    }
    
    int book(int start, int end) {
        // map保证节点有序，当某个点为0时删掉
        if(++m[start]==0) m.erase(start);
        if(--m[end]==0) m.erase(end);
        int res = 0, ans = 0;
        for(auto it: m) {
            ans += it.second;
            res = max(res, ans);
        }
        return res;
    }
private:
    map<int, int> m;
};
```
