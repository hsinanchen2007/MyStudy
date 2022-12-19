思路：建立一个数组，维护着可以使用的区间范围。这种区间也是start可用，end不能用的。每当插入一个日程，就将可用区间进行割裂。割裂的时候注意新加入区间保持有序。这样查找可用区间的时候可以使用二分法。

```
class MyCalendar {
    typedef pair<int, int> Item;
public:
    vector<Item> vec = vector<Item>();
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (vec.empty()) {
            if (start > 0) {
                vec.emplace_back(Item(0, start));
            } 
            vec.emplace_back(Item(end, 1000000001));
            return true;
        }
        long r = vec.size();
        long l = 0;
        while (l < r) {
            long mid = (r + l)/2;
            auto &item = vec[mid];
            if (start >= item.first) {
                if (end <= item.second) {
                    int v = item.second;
                    item.second = start;//需要先修改，再插入新的。否则修改不生效
                    vec.insert(vec.begin() +mid+1, Item(end, v));
                    return true;
                } else {
                    l = mid + 1;
                    continue;
                }
            } else if (start < item.first) {
                r = mid;
            }
            
        }
        
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
```