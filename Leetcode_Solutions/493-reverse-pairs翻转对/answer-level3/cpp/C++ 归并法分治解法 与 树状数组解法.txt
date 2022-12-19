# 解法一：
1，在归并排序的过程中计算出翻转对，可以认为翻转对是归并排序的副产物
2，也可以说是应用了归并排序的分治思想来求解本问题
```
class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& temp, int l, int r) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        // 先加上左右子数组的结果
        int res = mergeSort(nums, temp, l, m) + mergeSort(nums, temp, m + 1, r);
        // 然后记录左右子数组之间的结果
        int tl = l;
        int tr = m + 1;
        while (tl <= m && tr <= r) {
            // 转为long防止溢出
            if ((long)nums[tl] > 2 * (long)nums[tr]) {
                res += m - tl + 1;
                ++tr;
            } else {
                ++tl;
            }
        }
        // 进行归并
        int ind = 0;
        tl = l;
        tr = m + 1;
        while (tl <= m && tr <= r) {
            if (nums[tl] <= nums[tr]) {
                temp[ind++] = nums[tl++];
            } else {
                temp[ind++] = nums[tr++];
            }
        }
        while (tl <= m) temp[ind++] = nums[tl++];
        while (tr <= r) temp[ind++] = nums[tr++];
        // 从临时数组复制到排序数组
        for (int i = l; i <= r; ++i) {
            nums[i] = temp[i - l];
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        return mergeSort(nums, temp, 0, nums.size() - 1);
    }
};
```
![image.png](https://pic.leetcode-cn.com/4c5a3873d5abcb04c64fe88e371996d532a6bbc6e99190a6fa61afb9ed7a1733-image.png)

# 解法二：
树状数组题解
树状数组(Binary Indexed Tree (BIT))题解
1，数组离散化为其本身rank
2，然后从后向前遍历，并不断更新数组

```
class Solution {
public:
    vector<int> bits;
    int N;
    void add(int i, int x) {
        while (i <= N) {
            bits[i] += x;
            i += i & -i;
        }
    }
    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += bits[i];
            i -= i & -i;
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        // 离散化为排名
        set<int> s(nums.begin(), nums.end());
        map<int, int> m;
        for (auto x : s) {
            m[x] = m.size() + 1;
        }
        vector<int> ranks(nums.size(), 0);
        for (int i = 0; i < ranks.size(); ++i) {
            ranks[i] = m[nums[i]];
        }
        // 初始化树状数组
        N = ranks.size() + 1;
        bits = vector<int>(N + 1, 0);
        // 从后向前遍历查询更新，并获取结果
        int res = 0;
        for (int i = ranks.size() - 1; i >= 0; --i) {
            int t = (nums[i] > 0) ? ((nums[i] - 1) / 2) : (nums[i] / 2 - 1);
            auto it = m.lower_bound(t + 1);
            if (it != m.begin()) {
                res += query((--it)->second);
            }
            add(ranks[i], 1);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/39cc9fb94b4b9bbb9af029fb2a5f12d021229c24d6b837e2103aec32fdb54cb2-image.png)
