### 解题思路
So easy!但空间复杂度较高，胜在代码简洁。

### 代码

```cpp
class RecentCounter {
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        que.push(t);
        while(que.front() < t - 3000) que.pop();
        return que.size();
    }
private:
    queue<int> que;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
```