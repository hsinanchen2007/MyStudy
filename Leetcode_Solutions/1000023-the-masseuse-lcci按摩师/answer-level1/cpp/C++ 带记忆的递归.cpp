### 解题思路
我一开始也是想用动态规划，总也找不到递推式，思路自然点，从前往后递归一下。
traversalInternal 返回以start为起点的最大工作时长，那么massage就是每个点最大时长的最大值。在traversalInternal中，每个点为起点的最大工作时长，也就是其后相隔一个位置的点的最大工作时长的最大值，有点绕，看代码比较清楚。用一个map记录下已经计算过的点。即可避免重复计算。
执行用时 :4 ms, 在所有 C++ 提交中击败了63.53%的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
int traversalInternal(int start, vector<int>& nums, unordered_map<int, int>& cache) {
    auto it = cache.find(start);
    if (it != cache.end()) {
        return it->second;
    }
    int max = INT_MIN;
    int sum = nums[start];
    max = sum;
    for (int i = start + 2; i < nums.size(); i++) {
        auto r = traversalInternal(i, nums, cache);
        if (sum+r > max)
            max = sum + r;
    }
    cache.insert(make_pair(start, max));
    return max;
}

int massage(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int max = INT_MIN;
    unordered_map<int, int> cache;
    for (int i = 0; i < nums.size(); i++) {
        auto r = traversalInternal(i, nums, cache);
        if (r > max)
            max = r;
    }
    return max;
}
};
```