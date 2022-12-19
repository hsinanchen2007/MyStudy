看到时间复杂度要是log(n)，就把需要排序的算法都舍弃了。

第一时间考虑新建一个索引数组，若数 x 出现，就在索引的第x位置做个mark，然后遍历索引即可得到缺失的第一个正整数。但是发现一个问题，索引空间的大小是多少？必须是最大的数的大小吗？
其实不必，索引空间大小和nums.size()一样即可，原因如下：

算法需要找缺失的第一个正整数，假设nums中一共有n个数，那么以下两个条件必然成立：
1. 缺失的数在 1 - n 之间；
2. 缺失的数为 n + 1；

那么，我们只需要新建一个大小为 n 的空间，然后遍历nums；
若`nums[i] > 0 && nums[i] <= nums.size()`, 则将索引空间中nums[i]处的值做一个mark；
最后遍历索引空间，得到的未作mark的位置，即为缺失的第一个整数；
若都做了mark，则缺失的为 n + 1；

```cpp
int firstMissingPositive(vector<int>& nums) {
    vector<bool> dict(nums.size(), true);
    for (auto x : nums)
        if (x > 0 && x <= nums.size() ) dict[x - 1] = false;
    for (int i = 0; i < nums.size(); ++i)
        if (dict[i]) return i + 1;
    return nums.size() + 1;
}

```

但是上述算法空间复杂度为O(n)，可以利用原数组空间做一些优化：

假设 x 为 nums中的一个元素，若 `x > 0 && x <= n` 且 `nums[x - 1] != x` 时，
持续的将x交换到 nums[x - 1]位置上，这样最后遍历nums即可。

```cpp
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (auto x : nums)
        while (x > 0 && x <= n && nums[x - 1] != x) swap(x, nums[x - 1]);
    for (int i = 0; i < n; ++i)
        if (nums[i] != i + 1) return i + 1;
    return n + 1;
}
```

上述程序可以通过测试，但是可能会有些问题，可以将C++11的新特性换成正常的循环，即可保证无误；

```cpp
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) 
    {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) 
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < n; ++i)
        if (nums[i] != i + 1) return i + 1;
        
    return n + 1;
}
```

