周赛中我使用的是这个最直观的方法，不一定是最优的。

关键思路是：我们要寻找的是 $n, n+1, \dots, n+k-1$ 这样的 $k$ 个连续数字（我叫做数字序列）。那么从所有的数字中找到最小的一个，它一定是某个数字序列的首个数字，这样我们就可以确定一个数字序列。然后在剩下的数字中，继续找最小的一个。不断重复就可以确定全部的数字序列。

使用 map 统计所有数字的出现次数，然后不断往下减。

数组排序是为了每次能找到最小的数字，这一步是必需的。

参考代码：

```C++
bool isPossibleDivide(vector<int>& nums, int k) {
    int N = nums.size();
    if (N % k != 0) {
        return false;
    }

    sort(nums.begin(), nums.end());

    unordered_map<int, int> counter;
    for (int n : nums) {
        counter[n]++;
    }

    for (int n : nums) {
        if (counter[n] <= 0) {
            continue;
        }
        for (int i = 0; i < k; i++) {
            if (counter[n+i] <= 0) {
                return false;
            }
            counter[n+i]--;
        }
    }
    return true;
}
```

复杂度分析：

+ 时间复杂度：$O(n \log n + kn)$，$n$ 是数组的长度。
+ 空间复杂度：$O(n)$。