这道题的解法思路都是相同的：每次找到最大的饼，将其上部分翻转，以至于最大的饼换到最上面。然后从最下面翻转，让最大的到达最下面。

假设整个饼堆刚开始是<a, b, c, d, e, f>，其中d位置为最大饼，那么我们就先要将d以上翻转，形成<d, c, b, a, e, f>；再将整个饼堆翻转, 形成<f, e, a, b, c, d>。我们可以注意到，<a, b, c, d>共经过两轮翻转，彼此之间顺序不变; <e, f>只经过一次翻转，并且放到最上面。

至此，我们可以简单的以最大饼所在位置为切割点，将饼堆分为上下两部分计算。假设一共有`max_v`个饼，每个饼初始位置记作`ind`, 最大饼位置为 `max_ind`, 那么位置在最大饼之上的饼，即`ind < max_ind`，两轮翻转之后新位置变为 `max_v - max_ind + ind`；位置在最大饼之下的饼，即 `ind > max_ind`一轮翻转的新位置为 `max_v - ind + 1`。

因为每次都要寻找最大值的所在位置，我们可以直接用数组 `a[i]` 表示值为i的饼的位置，则每次最大饼位置 `max_ind = a[max_v]`。根据上面的过程，将其他饼的所在位置更新。每轮之后，`max_v--`即可。

```
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int len = A.size();
        if (!len || len==1)
            return {};
        int a[105];
        for (int i = 0; i < len; ++i)
            a[A[i]] = i+1; //初始化饼的位置
        int max_v = len;
        vector<int> ans;
        while (max_v) {
            int max_ind = a[max_v];
            ans.push_back(max_ind); //从最大饼位置翻转一次
            ans.push_back(max_v); //从底部翻转一次
            for (int i = 0; i < len; ++i) {
                if (A[i] > max_v)
                    continue; //这些饼已经在底部排好，不用管
                if (a[A[i]] > max_ind)
                    a[A[i]] = max_v-a[A[i]]+1; //最大饼下面的饼位置更新
                else
                    a[A[i]] = max_v-max_ind+a[A[i]]; //最大饼上面的饼位置更新
            }    
            max_v--;
        }
        return ans;
    }
};
```

