根据multiset的大小奇偶性以及插入数据与中位数指针的大小来进行指针的前后滑动调整
```
class Solution {
public:
    multiset<int> ms;
    multiset<int>::iterator mid;
    void add(int x) {
        ms.insert(x);
        if (ms.size() == 1) {
            mid = ms.begin();
        } else if ((ms.size() & 1) == 1 && *mid <= x) {
            ++mid;
        } else if ((ms.size() & 1) == 0 && *mid > x) {
            --mid;
        }
    }
    void del(int x) {
        auto it = ms.find(x);
        if (it == ms.end()) return;
        if ((ms.size() & 1) == 1) {
            if (it == mid || x > *mid) {
                --mid;
            }
        } else {
            if (x <= *mid) {
                ++mid;
            }
        }
        ms.erase(it);
    }
    double get() {
        if (ms.size() & 1) {
            return *mid;
        }
        return 0.5 * ((double)*mid + (double)*(next(mid)));
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k || k < 1) return {};
        for (int i = 0; i < k; ++i) {
            add(nums[i]);
        }
        vector<double> res;
        res.push_back(get());
        for (int i = k; i < nums.size(); ++i) {
            add(nums[i]);
            del(nums[i - k]);
            res.push_back(get());
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/6a504e8d8a1a557b4d6868ca51a4703f3b4273927de54f8224cd1f8708b83283-image.png)

