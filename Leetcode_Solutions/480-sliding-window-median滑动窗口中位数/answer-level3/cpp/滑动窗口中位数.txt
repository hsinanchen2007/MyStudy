#### 方法一：堆

本题和 [295. 数据流的中位数](https://leetcode-cn.com/problems/find-median-from-data-stream/) 非常相似，唯一区别是本题中的滑动窗口在向右移动时，会导致一些数被移出滑动窗口。因此，如果我们使用堆来维护这个滑动窗口，那么在当数被移出时，想要在堆中删除一个元素变得非常复杂。由于不同语言提供的 API 不同，在本题中，我们默认所有的堆与优先队列（Priority Queue）等价，即我们只能访问堆顶的元素（即堆中的最值）。

要想实现堆中的元素删除，我们可以使用 “延迟删除” 的方法。在 295 题中，我们使用两个堆寻找中位数，如果两个堆是平衡的，那么我们可以从堆顶元素得到中位数。在本题中，这个性质同样成立，即使堆中有多余的元素（即应当被移除的元素），但只要两个堆是平衡的，我们仍然可以从堆顶得到中位数。

我们可以使用哈希表来标记所有被移除的无效元素，如果某个堆的堆顶是一个无效元素，我们才会把它删除。下面给出了我们的算法：

- 我们维护两个堆：

    - 一个大根堆 `lo`，用来存放较小的那一半的元素；

    - 一个小根堆 `hi`，用来存放较大的那一半的元素。

- 使用哈希集合（HashSet）或者哈希映射（HashMap），记为 `hash_table`，标记所有被移除的无效元素，哈希表的大小等于在堆中无效元素的数量；

- 大根堆 `lo` 最多允许比小根堆 `hi` 存放多一个元素，当我们已经处理了 `k` 个元素时：

    - 如果 `k = 2n + 1` 为奇数，那么 `lo` 中存储 `k + 1` 个元素，`hi` 中存储 `k` 个元素；

    - 如果 `k = 2n` 为偶数，那么 `lo` 和 `hi` 中都存储 `k` 个元素；

    - 根据这样的性质，我们就可以从堆顶元素得到中位数。

- 注意：当我们考虑堆中的元素个数时，我们指的是堆中有效的元素个数，无效的元素并不会被计入，它们只是暂时地被存放在堆中；

- 使用变量 `balance` 表示两个堆是否平衡：

    - 如果 `balance == 0`，那么两个堆平衡；

    - 如果 `balance < 0`，那么 `lo` 中的元素较少，需要从 `hi` 中取出若干个元素放入 `lo`；
    
    - 如果 `balance > 0`，那么 `hi` 中的元素较少，需要从 `lo` 中取出若干个元素放入 `hi`。

- 此时我们需要插入一个新的元素 `in_num`：

    - 如果 `in_num` 小于等于 `lo` 的堆顶元素，那么它可以被放入 `lo` 中，此时需要增加 `balance` 的值；

    - 否则，`in_num` 可以被放入 `hi` 中，此时需要减少 `balance` 的值。

- 延迟删除被移出窗口的元素 `out_num`：

    - 如果 `out_num` 在 `lo` 中，那么需要减少 `balance` 的值；

    - 如果 `out_num` 在 `hi` 中，那么需要增加 `balance` 的值；

    - 我们将 `out_num` 放入哈希表中；

    - 每当无效的元素出现在堆顶，我们就将其从堆中删除，同时从哈希表中删除。

```C++ [sol1]
vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
    vector<double> medians;
    unordered_map<int, int> hash_table;
    priority_queue<int> lo;                                 // max heap
    priority_queue<int, vector<int>, greater<int> > hi;     // min heap

    int i = 0;      // index of current incoming element being processed

    // initialize the heaps
    while (i < k)
        lo.push(nums[i++]);
    for (int j = 0; j < k / 2; j++) {
        hi.push(lo.top());
        lo.pop();
    }

    while (true) {
        // get median of current window
        medians.push_back(k & 1 ? lo.top() : ((double)lo.top() + (double)hi.top()) * 0.5);

        if (i >= nums.size())
            break;                          // break if all elements processed

        int out_num = nums[i - k],          // outgoing element
            in_num = nums[i++],             // incoming element
            balance = 0;                    // balance factor

        // number `out_num` exits window
        balance += (out_num <= lo.top() ? -1 : 1);
        hash_table[out_num]++;

        // number `in_num` enters window
        if (!lo.empty() && in_num <= lo.top()) {
            balance++;
            lo.push(in_num);
        }
        else {
            balance--;
            hi.push(in_num);
        }

        // re-balance heaps
        if (balance < 0) {                  // `lo` needs more valid elements
            lo.push(hi.top());
            hi.pop();
            balance++;
        }
        if (balance > 0) {                  // `hi` needs more valid elements
            hi.push(lo.top());
            lo.pop();
            balance--;
        }

        // remove invalid numbers that should be discarded from heap tops
        while (hash_table[lo.top()]) {
            hash_table[lo.top()]--;
            lo.pop();
        }
        while (!hi.empty() && hash_table[hi.top()]) {
            hash_table[hi.top()]--;
            hi.pop();
        }
    }

    return medians;
}
```

**复杂度分析**

* 时间复杂度：$O(N \log k)$，其中 $N$ 是数组的长度。

* 空间复杂度：$O(N)$。

#### 方法二：多重集合 + 迭代器

这种方法基于特定的语言，即 C++ 中的 `multiset`（多重集合）数据结构。

我们使用一个多重集合和一个迭代器（iterator），其中迭代器指向集合中的中位数。当我们添加或删除元素时，我们修改迭代器的指向，保证其仍然指向中位数。下面给出了我们的算法：

- 我们维护多重集合 `window` 的迭代器 `mid`；

- 首先我们在 `window` 中加入前 `k` 个元素，并让 `mid` 指向 `window` 中的第 $\lfloor k/2 \rfloor$ 个元素（从 `0` 开始计数）；

- 当我们在 `window` 中加入数 `num` 时：

    - 如果 `num < *mid`，那么我们需要将 `mid` 往前移；

    - 如果 `num >= mid`，我们不需要对 `mid` 进行任何操作。

- 当我们在 `windows` 中删除数 `num` 时：

    - 如果 `num < *mid`，我们需要将 `mid` 先往后移，再删除 `num`；

    - 如果 `num > *mid`，我们不需要对 `mid` 进行任何操作；

    - 如果 `num == *mid`，我们需要找到 `num` 第一次出现的位置对应的迭代器（使用 `lower_bound()`）并删除，而不是删除 `mid` 对应的数。随后和 `num < *mid` 的处理方式相同。

```C++ [sol2]
vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
    vector<double> medians;
    multiset<int> window(nums.begin(), nums.begin() + k);

    auto mid = next(window.begin(), k / 2);

    for (int i = k;; i++) {

        // Push the current median
        medians.push_back(((double)(*mid) + *next(mid, k % 2 - 1)) * 0.5);

        // If all done, break
        if (i == nums.size())
            break;

        // Insert incoming element
        window.insert(nums[i]);
        if (nums[i] < *mid)
            mid--;                  // same as mid = prev(mid)

        // Remove outgoing element
        if (nums[i - k] <= *mid)
            mid++;                  // same as mid = next(mid)

        window.erase(window.lower_bound(nums[i - k]));
    }

    return medians;
}
```

**复杂度分析**

* 时间复杂度：$O(N \log k)$，其中 $N$ 是数组的长度。

* 空间复杂度：$O(N)$。