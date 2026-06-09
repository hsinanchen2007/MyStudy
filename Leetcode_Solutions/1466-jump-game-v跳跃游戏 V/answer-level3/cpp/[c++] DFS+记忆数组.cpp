**关键在从小到大遍历**
```
class Solution {
public:
    int step = 1;
    int mem[1000];

    int maxJumps(vector<int> &arr, int d) {
        // 倒序从最小值向上遍历,想出来这个基本上就解决这道题了
        vector<pair<int, int >> smlToBig;
        for (int i = 0; i < arr.size(); i++)
            smlToBig.push_back({arr[i], i});
        sort(smlToBig.begin(), smlToBig.end());
        for (int i = 0; i < smlToBig.size(); i++)
            jump(arr, d, smlToBig[i].second);
        return step;
    }

    int jump(vector<int> &arr, int d, int idx) {
        if (mem[idx] != 0) return mem[idx];
        int l = 0, r = 0, h = arr[idx];
        // 右遍历
        for (int i = idx + 1; i < arr.size() && i <= idx + d && arr[i] < h; i++)
            r = max(r, jump(arr, d, i));
        // 左遍历
        for (int i = idx - 1; i >= 0 && i >= idx - d && arr[i] < h; i--)
            l = max(l, jump(arr, d, i));
        // 取左右两种可能最大值+1
        l = max(l, r) + 1;
        mem[idx] = l;
        step = max(l, step);
        return l;
    }
};
```
