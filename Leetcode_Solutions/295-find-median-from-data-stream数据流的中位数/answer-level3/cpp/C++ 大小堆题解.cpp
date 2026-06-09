```

class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int> > large;
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        // 判断归属
        if (large.empty() || num > large.top()) {
            large.push(num);
            // 平衡大小
            if (large.size() > small.size() + 1) {
                small.push(large.top());
                large.pop();
            }
        } else {
            small.push(num);
            // 平衡大小
            if (small.size() > large.size()) {
                large.push(small.top());
                small.pop();
            }
        }
    }
    
    double findMedian() {
        if (small.size() + large.size() & 1) {
            return large.top();
        }
        return 0.5 * (small.top() + large.top());
    }
};
```

![image.png](https://pic.leetcode-cn.com/e74a757792bc2c2929c13b8f3440ae02d66fb96e01f3dede6f9028bdd50d0b26-image.png)
