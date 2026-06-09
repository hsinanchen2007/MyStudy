因为题目说了窗口是5分钟，所以按秒遍历可以接受。但是如果窗口变大，遍历效率就太低了。
因为时间戳是递增的，所以可以用map记录每个时间点之前的总次数，这样在查询时，就可以用前缀和的方式相减求出次数。
```c++
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (count.count(timestamp) > 0) count[timestamp]++;
        else {
            int sum = 0;
            if (count.size() > 0) sum = count.rbegin()->second;
            count[timestamp] = sum+1;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int start = timestamp - 300 + 1;
        auto si = count.lower_bound(start);
        auto ei = count.upper_bound(timestamp);
        if (si == count.end()) return 0;
        
        if (ei == count.begin()) return 0;
        ei--;
        if (si == count.begin()) {
            return ei->second;
        } else si--;
        return (ei->second - si->second);
    }
    map<int, int> count;
};
```