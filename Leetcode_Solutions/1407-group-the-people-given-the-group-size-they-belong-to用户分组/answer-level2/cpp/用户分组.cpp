**方法一：哈希映射**

对于两个用户 `x` 和 `y`，如果 `groupSize[x] != groupSize[y]`，它们用户组的大小不同，那么它们一定不在同一个用户组中。因此我们可以首先对所有的用户进行一次【粗分组】，用一个哈希映射（HashMap）来存储所有的用户。哈希映射中键值对为 `(gsize, users)`，其中 `gsize` 表示用户组的大小，`users` 表示满足用户组大小为 `gsize`，即 `groupSize[x] == gsize` 的所有用户。这样以来，我们就把所有用户组大小相同的用户都暂时放在了同一个组中。

在进行了【粗分组】后，我们可以将每个键值对 `(gsize, users)` 中的 `users` 进行【细分组】。由于题目保证了给出的数据至少存在一种方案，因此我们的【细分组】可以变得很简单：只要每次从 `users` 中取出 `gsize` 个用户，把它们放在一个组中就可以了。在进行完所有的【细分组】后，我们就得到了一种满足条件的分组方案。

```C++ [sol1]
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < groupSizes.size(); ++i) {
            groups[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for (auto group = groups.begin(); group != groups.end(); ++group) {
            const int& gsize = group->first;
            vector<int>& users = group->second;
            for (auto iter = users.begin(); iter != users.end(); iter = next(iter, gsize)) {
                vector<int> dummy(iter, next(iter, gsize));
                ans.push_back(dummy);
            }
        }
        return ans;
    }
};
```

```C++ [sol1]
// C++17 Standard
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < groupSizes.size(); ++i) {
            groups[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for (auto& [gsize, users]: groups) {
            for (auto iter = users.begin(); iter != users.end(); iter = next(iter, gsize)) {
                ans.emplace_back(iter, next(iter, gsize));
            }
        }
        return ans;
    }
};
```

```Python [sol1]
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        groups = collections.defaultdict(list)
        for i, _id in enumerate(groupSizes):
            groups[_id].append(i)
        
        ans = list()
        for gsize, users in groups.items():
            for it in range(0, len(users), gsize):
                ans.append(users[it : it + gsize])
        return ans
```

**复杂度分析**

- 时间复杂度：$O(N)$。

- 空间复杂度：$O(N)$。