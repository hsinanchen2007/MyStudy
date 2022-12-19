# 方法一：先用递归思路考虑这个问题

```c++ []
int recurse(vector<int>& nums, int low, int high, int target) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) return recurse(nums, mid + 1, high, target);
        else return recurse(nums, low, mid - 1, target);
    }
    else return -1;
}
int search(vector<int>& nums, int target) {
    return recurse(nums, 0, nums.size() - 1, target);
}
```

# 方法二：明白递归算法后，转化为迭代也非常简单

```c++ []
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

每个人思维习惯不一样，有人喜欢递归，有人喜欢迭代，见仁见智吧！
