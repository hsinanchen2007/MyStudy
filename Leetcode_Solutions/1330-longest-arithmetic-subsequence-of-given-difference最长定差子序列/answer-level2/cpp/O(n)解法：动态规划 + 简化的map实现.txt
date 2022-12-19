1，定义状态f[i]表示以arr[i]结尾的等差子序列的长度，那么可以从0开始对f[i]进行递推；
2，递推过程中维护一个从arr[i]到i的映射关系m，这样计算f[i]时，m[arr[i] - difference]便是所有相关的早期子序列；
3，映射关系中arr[i]重复出现时，只需保留f[i]最大的i，所以映射关系是一对一的，不需要维护相同arr[i]的所有i的列表，也就是说，对于任何f[i]，相关的早期子序列最多有一个；
4，因为arr[i]的数值范围很小，所以可以用简化的数组来实现映射关系，无需复杂的哈希表。


```
class Solution {
public:
    static const int N = 20001; // because -10^4 <= arr[i], difference <= 10^4
    static const int D = 10000;
    static const int ARRAY_MAX_LEN = 100000;
    int m[N];
    int f[ARRAY_MAX_LEN];

    int longestSubsequence(vector<int>& arr, int difference) {
        if (arr.empty())
            return 0;

        for (int i = 0; i < N; i++)
            m[i] = -1;

        int res = 1;
        for (int i = 0; i < arr.size(); i++) {
            f[i] = 1;
            int prev_mi = arr[i] - difference + D;
            if (prev_mi >= 0 && prev_mi < N) {
                int prev_fi = m[prev_mi];
                if (prev_fi >= 0)
                    f[i] = f[prev_fi] + 1;
            }

            int cur_mi = arr[i] + D;
            auto &cur_fi = m[cur_mi];
            if (cur_fi < 0 || f[i] > f[cur_fi])
                cur_fi = i;
            
            res = max(res, f[i]);
        }

        return res;
    }
};
```
