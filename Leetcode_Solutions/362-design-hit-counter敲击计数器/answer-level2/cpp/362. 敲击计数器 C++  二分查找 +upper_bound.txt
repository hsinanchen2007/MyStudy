### 解题思路

![image.png](https://pic.leetcode-cn.com/256ef35b87675083b1dbeb3c7340016b7690e825490a7ddb57cc349e099d1c35-image.png)

难得双百，核心思路：
1）因为是时间戳，因此是递增序列，我们构造递减栈；
2）然后利用二分查找，找到小于300秒内时间窗的左边界 left = timestamp -300 +1;upper_bound +greater<int>() 是找到第一个小于left的索引
3）结果 = left - begin；


![image.png](https://pic.leetcode-cn.com/13a7972105398024420efb66f54a8010997b968f7e6a4c0e9043230faee22cc9-image.png)


### 代码

```cpp
class HitCounter {
public:
    /** Initialize your data structure here. */
    deque<int> buff;

    HitCounter() {
        buff.clear();
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        buff.push_front(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int left = buff.front() - 300 + 1;
        return upper_bound(buff.begin(), buff.end(), left, greater<int>()) - buff.begin() ;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
```