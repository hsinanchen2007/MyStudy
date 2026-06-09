#### 方法一：树状数组

首先我们需要明确我们需要如何统计翻转对的数量。我们可以逆序遍历数组 `nums`，对于第 `i` 个元素 `nums[i]`，我们希望知道有多少个已经遍历过的元素的两倍仍然小于 `nums[i]`。如果用某个数据结构存放了所有已经遍历过的元素的两倍，那么我们希望知道，该数据结构中有多少个元素小于 `nums[i]`。

即我们需要实现支持如下操作的数据结构：

- 对于一个数 `x`，我们希望找出当前有多少个数小于 `x`；

- 对于一个数 `x`，将它的两倍添加到数据结构中。

因此我们可以使用树状数组（Binary Indexed Tree，BIT）来实现这两个操作。基础的树状数组支持 “添加一个数” 和 “查询当前小于等于某个数的数量” 这两种操作。

下面是树状数组 “添加” 操作的伪代码：
```
update(BIT,index, val):
    while(index<0):
        BIT[index]+=val
        index-=(index&(-index))
```

下面是树状数组 “查询” 操作的伪代码：
```
query(BIT,index):
    sum=0
    while(index<BIT.size):
        sum+=BIT[index]
        index+=(index&(-index))
```

可以发现树状数组的实现非常简单。在本题中，对于第一个操作，我们只需要找出当前有多少个数小于等于 `x - 1` 即可；对于第二个操作，我们直接将 `x * 2` 添加到树状数组中即可。

```C++ [sol1]
void update(vector<int>& BIT, int index, int val)
{
    while (index > 0) {
        BIT[index] += val;
        index -= index & (-index);
    }
}

int query(vector<int>& BIT, int index)
{
    int sum = 0;
    while (index < BIT.size()) {
        sum += BIT[index];
        index += index & (-index);
    }
    return sum;
}
int reversePairs(vector<int>& nums)
{
    int n = nums.size();
    vector<int> nums_copy(nums);

    sort(nums_copy.begin(), nums_copy.end());

    vector<int> BITS(n + 1, 0);
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += query(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) - nums_copy.begin() + 1);
        update(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, 1);
    }
    return count;
}
```

**复杂度分析**

* 时间复杂度：$O(N \log N)$。

* 空间复杂度：$O(N)$。

#### 方法二：归并排序

当我们希望在数组中求出逆序对的数目时，我们可以使用归并排序的方法。这道题中 `i < j` 且 `nums[i] > 2 * nums[j]` 的要求与逆序对类似，因此我们也可以使用归并排序的方法求出翻转对的数目。

在归并排序中，当我们归并两个子数组 `nums[start .. mid]` 和 `nums[mid + 1 .. end]` 时，我们可以计算出对于前者中的每一个元素 `nums[i]`，后者中满足 `nums[i] > 2 * nums[j]` 的 `j` 的数目。由于两个子数组已经排好序，因此对于固定的 `i`，满足条件的 `j` 的区间一定是从后者的左端点开始，并且随着 `i` 的增加，`j` 区间的右端点不会减小。因此我们可以在 `nums[mid + 1 .. end]` 中维护一个指针 `pt`，表示对于当前的 `i`，`nums[mid + 1 .. pt]` 的两倍都小于 `nums[i]`。随着 `i` 的增加，我们尝试向右移动 `pt` 使得更多的数满足条件。

```C++ [sol1]
void merge(vector<int>& A, int start, int mid, int end)
{
    int n1 = (mid - start + 1);
    int n2 = (end - mid);
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = A[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];
    int i = 0, j = 0;
    for (int k = start; k <= end; k++) {
        if (j >= n2 || (i < n1 && L[i] <= R[j]))
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

int mergesort_and_count(vector<int>& A, int start, int end)
{
    if (start < end) {
        int mid = (start + end) / 2;
        int count = mergesort_and_count(A, start, mid) + mergesort_and_count(A, mid + 1, end);
        int j = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (j <= end && A[i] > A[j] * 2LL)
                j++;
            count += j - (mid + 1);
        }
        merge(A, start, mid, end);
        return count;
    }
    else
        return 0;
}

int reversePairs(vector<int>& nums)
{
    return mergesort_and_count(nums, 0, nums.size() - 1);
}
```

**复杂度分析**

* 时间复杂度：$O(N \log N)$。

* 空间复杂度：$O(N)$。