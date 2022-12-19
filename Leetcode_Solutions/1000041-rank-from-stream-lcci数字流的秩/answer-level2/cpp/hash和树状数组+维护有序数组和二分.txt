### 解题思路
两种思路：
1. 维护有序数组+二分
2. 维护hash，然后求和；暴力没写，这里写了树状数组优化版

### 代码
#### 有序数组+二分
```cpp
class StreamRank {
public:
    vector<int> nums;
    StreamRank() {

    }
    
    void track(int x) {
        stack<int> tmp;
        while (nums.size() && nums.back() > x) tmp.push(nums.back()), nums.pop_back();
        nums.push_back(x);
        while (tmp.size()) nums.push_back(tmp.top()), tmp.pop(); 
    }
    
    int getRankOfNumber(int x) {
        if (nums.empty() || nums[0] > x) return 0;
        if (nums.back() <= x) return nums.size();
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= x) l = mid;
            else r = mid - 1;
        }
        return r + 1;
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */
```
#### 树状数组+hash
题目没说最小值，当成非负数做的
```cpp
const int N = 5e4 + 10;
class StreamRank {
public:
    int tr[N], idx;
    StreamRank() {
        memset(tr, 0, sizeof tr);
        idx = 0;
    }
    
    int lowbit(int x) {
        return x & -x;
    }
    
    void track(int x) {
        for (int i = x + 1; i <= N; i += lowbit(i)) tr[i] += 1;
    }
    
    int getRankOfNumber(int x) {
        int ans = 0;
        for (int i = x + 1; i; i -= lowbit(i)) ans += tr[i];
        return ans;
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */
```