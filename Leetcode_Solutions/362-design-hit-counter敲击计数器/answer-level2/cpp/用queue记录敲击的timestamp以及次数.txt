### 解题思路
用queue记录敲击的timestamp以及次数（应对每秒次数很多的情况）

### 代码

```cpp
class HitCounter {
private:
    deque<pair<int, int>> q;
    int cnt;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        cnt = 0;
    }
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (!q.empty() && q.back().first == timestamp) q.back().second++;
        else q.push_back({timestamp, 1});
        cnt ++;
    }
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front().first + 1 > 300) {
            cnt -= q.front().second;
            q.pop_front();
        }
        return cnt;
    }
};
```
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :9 MB, 在所有 cpp 提交中击败了100.00%的用户