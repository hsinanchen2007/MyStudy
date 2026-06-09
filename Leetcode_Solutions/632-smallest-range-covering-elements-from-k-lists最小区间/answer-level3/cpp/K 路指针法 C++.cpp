首先每一个数组都把头放到一个排序set里面，插入的时候要记录数组index。

找出最小和最大的差值去更新结果。

为了要缩小间距，我们必须每次把最小的元素移出来，并且更上对应数组的下一个元素。

当某次操作没有下一个元素时，循环停止。

k路指针用于记录每个数组遍历到的位置

这里我用的是set直接可以拿到最大和最小，也可以用两个优先队列，一个升序一个降序。

```cpp
class Solution {
public:
    struct CMP {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        };
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        if (nums.size() == 1)
            return { nums[0][0], nums[0][0] };
        vector<int> result{ -1000000,1000000 };
        vector<int> cur{ -1000000,1000000 };
        vector<int> ptrs(nums.size(), 0);
        set<pair<int, int>, CMP> data;
        for (int i = 0; i < nums.size(); ++i)
            data.insert({ nums[i][0],i });
        while (true) {
            auto e = data.end();
            cur = { data.begin()->first, (--e)->first };
            if (cur[1] - cur[0] < result[1] - result[0])
                result = cur;
            if (++ptrs[data.begin()->second] == nums[data.begin()->second].size())
                break;
            int toInsert = nums[data.begin()->second][ptrs[data.begin()->second]];
            int index = data.begin()->second;
            data.erase(data.begin());
            data.insert({ toInsert, index });
        }
        return result;
    }
};
```
