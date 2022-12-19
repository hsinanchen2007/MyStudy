# 解法一：
**二分搜索**
```
class Solution {
public:
    vector<int> s;
    int lo;
    int hi;
    Solution(vector<int>& w) {
        s = w;
        for (int i = 1; i < s.size(); ++i) {
            s[i] += s[i - 1];
        }
        lo = 0;
        hi = s.back();
    }
    
    int pickIndex() {
        int r = rand() % (hi - lo) + 1;
        return lower_bound(s.begin(), s.end(), r) - s.begin();
    }
};
```

![image.png](https://pic.leetcode-cn.com/69ab3b50e7ebff552227f74ee0d3c3a5b5eed032dfb9a1e54a7ea5b6939055f6-image.png)


# 解法二：
**Alias method**
该方法在`O(nlog(n))`时间复杂度内对概率进行预处理，然后就可以实现`O(1)`的时间复杂度进行抽样
在固定样本后，需要大量采样的场景下能大大提高计算效率
但对于采样数小于样本数的情况下，则优化效果收效不大
```
class Solution {
public:
    struct Sample {
        int ind1;
        int ind2;
        double prob;
        Sample() : ind1(-1), ind2(-1), prob(0.0) {};
        Sample(int i, double p) : ind1(i), ind2(-1), prob(p) {};
        bool operator < (const Sample& other) const {
            if (prob == other.prob)
                return ind1 < other.ind1;
            return prob < other.prob;
        }
    };
    int N;
    vector<Sample> samples;
    Solution(vector<int>& w) {
        N = w.size();
        double sum = accumulate(w.begin(), w.end(), 0.0);
        set<Sample> s;
        for (int i = 0; i < w.size(); ++i) {
            auto sample = Sample(i, (double) w[i] * N / sum);
            s.insert(sample);
        }
        while (!s.empty()) {
            if (s.size() == 1) {
                auto sample = *s.begin();
                sample.ind2 = sample.ind1;
                samples.push_back(sample);
                break;
            }
            auto small = *s.begin();
            auto large = *s.rbegin();
            s.erase(small);
            s.erase(large);
            small.ind2 = large.ind1;
            large.prob -= 1 - small.prob;
            samples.push_back(small);
            s.insert(large);
        }
    }
    
    int pickIndex() {
        int i = rand() % N;
        double p = rand() * 1.0 / RAND_MAX;
        if (p <= samples[i].prob) {
            return samples[i].ind1;
        }
        return samples[i].ind2;
    }
};

```

![image.png](https://pic.leetcode-cn.com/5b98e9e9c2c932c780fc4a10032b595e52734cfd7656bbb5e84b3146d1c3f21c-image.png)
