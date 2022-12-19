### 执行时间
![图片.png](https://pic.leetcode-cn.com/76b68100dd1496c85261d92de8b3c992386c01317423d26112b6d502a4d0ae42-%E5%9B%BE%E7%89%87.png)

### 思路
1. 使用堆，可以使用优先队列 `priority_queue`
2. 维护一个 k 大小的小顶堆，堆顶就是第 k 个最大的数
3. 注意：当堆的大小已经是 k 个的时候，需要注意直接与堆顶判断决定是否加入堆中，这样效率高
    > 因为加入堆中，就会对堆调整，然后容量超过了再取出来，又调整一遍

### 答题
```C++ []
int findKthLargest(vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& n : nums)
    {
        if (pq.size() >= k && pq.top() >= n) continue;
        pq.push(n);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}
```

### 自己实现堆的版本
1. 对于堆的调整，需要调整的节点只对自己的左右孩子节点中更大/小的一边进行交换
2. 然后再跳到那个节点继续调整，直到不需要调整为止
3. 建堆的时候从最后一个非叶子节点开始向上建堆，用迭代的方式写，就是 `for (int i = hp.size() / 2 - 1; i >= 0; i--)`
4. 自定义了比较函数，示范了大顶堆和小顶堆

```C++ []
void adjustHeap(vector<int>& hp, int idx, function<bool(const int& a, const int& b)> cmp)
{
    for (int i = idx; i * 2 + 1 < hp.size();)
    {
        int t = i * 2 + 1;
        t += (t + 1 < hp.size() && !cmp(hp[t + 1], hp[t]));
        if (!cmp(hp[i], hp[t])) break;
        swap(hp[i], hp[t]);
        i = t;
    }
}

void buildHeap(vector<int>& hp, function<bool(const int& a, const int& b)> cmp)
{
    for (int i = hp.size() / 2 - 1; i >= 0; i--)
    {
        adjustHeap(hp, i, cmp);
    }
}

int findKthLargest(vector<int>& nums, int k)
{
    if (k == 0) return {};
    vector<int> ans(nums.begin(), nums.begin() + k);
    auto cmp_less = [](const int& a, const int& b) { return a < b; };
    auto cmp_greater = [](const int& a, const int& b) { return a > b; };
    auto cmp = cmp_greater;
    buildHeap(ans, cmp);
    for (int i = k; i < nums.size(); i++)
    {
        if (!cmp(nums[i], ans[0])) continue;
        ans[0] = nums[i];
        adjustHeap(ans, 0, cmp);
    }
    return ans[0];
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

