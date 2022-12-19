### 解题思路

![image.png](https://pic.leetcode-cn.com/a6d35efb7c629000bb9a9390a0b7a8f44e68bebe96bb8457411e005dba5f0cc0-image.png)

### 代码

```cpp
class RecentCounter {
public:
    RecentCounter() {
        
    }
    queue<int> p;
    int ping(int t) {
        p.push(t);
        while(p.front()<t-3000) p.pop();
        return p.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
```