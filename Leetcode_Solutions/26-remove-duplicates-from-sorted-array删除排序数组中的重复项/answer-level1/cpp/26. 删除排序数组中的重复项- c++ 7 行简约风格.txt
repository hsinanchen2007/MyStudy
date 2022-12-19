8 行版本：

```cpp
int removeDuplicates(vector<int>& nums) {
    int i = 0, j = 0;
    while (j < nums.size()) {
        auto e = nums[j++];
        if (i == 0 || nums[i-1] != e) nums[i++] = e;
    }
    return i;
}
```

可以再写成 7 行：

```cpp
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int j = 0; j < nums.size(); ++j) {
        if (i == 0 || nums[i-1] != nums[j]) nums[i++] = nums[j];
    }
    return i;
}
```

技巧是只使用一个循环，没必要内部再套一个循环去过滤重复元素了。

如果感觉打脑壳，不妨这样想：

首先：i 表示 dst 数组的大小。j 表示 src 数组尚未处理的元素的起始位置。初始化 i = 0, j = 0.

把其中一个数组 src 的内容复制到另一个数组 dst 中去。如果 dst[i-1] 和 src[j] 相同，则不用复制，跳过当前的 src[j] 就行了。由于复制的过程并不会破坏掉 src[j..n) 中的元素，因此 dst 和 src 只使用同一个数组 nums 就行了。