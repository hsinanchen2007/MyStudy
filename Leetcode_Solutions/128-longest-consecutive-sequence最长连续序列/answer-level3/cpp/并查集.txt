不看tag真不知道是并查集，使用了一个people数组来统计各个集合个数。
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> parent(n);
        vector<int> people(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            return x == parent[x] ? x : parent[x] = find(parent[x]);
        };
        function<void(int, int)> union_ = [&](int x, int y) {
            parent[find(x)] = find(y);
            people[find(x)] += people[find(y)];
        };
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i ++) {
            hash[nums[i]] = i;
            people[i] = 1;
            if (hash.count(nums[i] - 1)) 
                union_(i, hash[nums[i] - 1]);
            if (hash.count(nums[i] + 1))
                union_(i, hash[nums[i] + 1]);
        }
        int ans = 1;
        for (int i = 0; i < n; i ++)
            ans = max(ans, people[i]), cout << people[i] << " " << parent[i] << endl;
        return ans;
    }
};
```
