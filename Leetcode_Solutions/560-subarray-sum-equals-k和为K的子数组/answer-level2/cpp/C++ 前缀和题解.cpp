解法一：
```
class Solution {
public:
    int bisearch(vector<int>& nums, int t) {
        if (nums.back() < t) return nums.size();
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= t) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> sums(N + 1);
        for (int i = 0; i < N; ++i) {
            sums[i + 1] += sums[i] + nums[i];
        }
        map<int, vector<int> > m;
        for (int i = 0; i < sums.size(); ++i) {
            m[sums[i]].push_back(i);
        }
        int res = 0;
        for (auto& p : m) {
            if (m.count(k + p.first) == 0) continue;
            if (k == 0) {
                res += p.second.size() * (p.second.size() - 1) / 2;
            } else {
                auto q = m[k + p.first];
                for (auto x : p.second) {
                    res += q.size() - bisearch(q, x);
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/ff087d625b462c75aa8235bfb2886fbf79a91d7ee4cc8f9999f1844d94c235c6-image.png)


解法二：
参考官方题解：
```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m{{0, 1}};
        int res = 0;
        int sum = 0;
        for (auto x : nums) {
            sum += x;
            if (m.count(sum - k)) {
                res += m[sum - k];
            }
            ++m[sum];
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/efa23279e3bc79f3e323cf040d9aa8aa447161c5d991624295d4de3efc4e58e9-image.png)
