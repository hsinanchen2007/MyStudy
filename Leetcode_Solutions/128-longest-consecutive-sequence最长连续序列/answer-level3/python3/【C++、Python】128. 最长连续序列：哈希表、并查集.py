### 哈希表 ###
#### 代码 ####
```cpp []
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int &num : nums) {
            if (s.count(num - 1)) continue;
            int curLen = 1;
            while (s.count(num++ + 1)) ++curLen;
            res = max(res, curLen);
        }
        return res;
    }
};
```
```python3 []
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        res = 0
        for num in nums:
            if num - 1 in s:
                continue
            curLen = 1
            while num + 1 in s:
                curLen += 1
                num += 1
            res = max(res, curLen)
        return res
```


### 并查集 ###
#### 代码 ####
```cpp []
class Solution {
public:
    struct DSU {
        unordered_map<int, int> pre, rank, cnt;
        DSU(vector<int>& nums) {
            for (int &num : nums) {
                pre[num] = num;
                cnt[num] = 1;
            }
        }
        int find(int x) {
            while (x != pre[x]) x = pre[x];
            return x;
        }
        int merge(int& x, int&& y) {
            if (!pre.count(y)) return 1;
            int root1 = find(x), root2 = find(y);
            if (root1 == root2) return cnt[root1];
            pre[root1] = root2;
            cnt[root2] += cnt[root1];
            return cnt[root2];
            if (rank[root1] < rank[root2]) {
                pre[root1] = root2;
                cnt[root2] += cnt[root1];
                return cnt[root2];
            }
            else if (rank[root1] > rank[root2]) {
                pre[root2] = root1;
                cnt[root1] += cnt[root2];
                return cnt[root1];
            }
            else {
                pre[root1] = root2;
                cnt[root2] += cnt[root1];
                ++rank[root2];
                return cnt[root2];
            }
        }
    };
    int longestConsecutive(vector<int>& nums) {
        DSU dsu(nums);
        int res = 0;
        for (int &num : nums) res = max(res, dsu.merge(num, num + 1));
        return res;
    }
};
```
```python3 []
class DSU:
    def __init__(self, nums):
        self.pre = {num: num for num in nums}
        self.rank = collections.defaultdict(lambda: 1)
        self.cnt = collections.defaultdict(lambda: 1)
    def find(self, x):
        while x != self.pre[x]:
            x = self.pre[x]
        return x
    def merge(self, x, y):
        if y not in self.pre:
            return 1
        root1, root2 = self.find(x), self.find(y)
        if root1 == root2:
            return self.cnt[root1]
        if self.rank[root1] < self.rank[root2]:
            self.pre[root1] = root2
            self.cnt[root2] += self.cnt[root1]
            return self.cnt[root2]
        elif self.rank[root1] > self.rank[root2]:
            self.pre[root2] = root1
            self.cnt[root1] += self.cnt[root2]
            return self.cnt[root1]
        else:
            self.pre[root1] = root2
            self.cnt[root2] += self.cnt[root1]
            self.rank[root2] += 1
            return self.cnt[root2]
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        dsu = DSU(nums)
        res = 0
        for num in nums:
            res = max(res, dsu.merge(num, num + 1))
        return res
```