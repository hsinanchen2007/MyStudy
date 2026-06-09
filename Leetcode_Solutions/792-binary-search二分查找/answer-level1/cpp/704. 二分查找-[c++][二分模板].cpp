## 题解

- 版本一

```cpp
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1; // <-
    while (lo <= hi) { // <-
        int mid = lo + (hi - lo >> 1); // <-
        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return -1;
}
```

- 版本二

```cpp
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo >> 1);
        if (target <= nums[mid]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return nums.empty() ? -1 : (target == nums[lo] ? lo : -1);
}
```

- 版本三

```
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1 >> 1);
        if (target >= nums[mid]) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return nums.empty() ? -1 : (target == nums[lo] ? lo : -1);
}
```

- 版本四

```
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo >> 1);
        if (target <= nums[mid]) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    
    if (nums.empty()) return -1;
    if (nums.size() == 1) return target == nums[0] ? 0 : -1;
    if (target == nums[lo]) return lo;
    if (target == nums[hi]) return hi;
    return -1;
}
```

## 二分的几个模板

打注释箭头的都需要你重点去关注的。

- 左 mid：对于偶数个元素的区间，计算出来的 mid 位于前一半元素的最后一个位置。如下：

```
[x, x, x, x, x, x]
 ^     ^        ^
 lo   mid       hi
```

它的计算方法是： `int mid = lo + (hi - lo >> 1)`，通常左 mid 需要搭配 lo = mid + 1, hi = mid 来使用，这样保证不会死循环。

- 右 mid: 对于偶数个元素的区间，计算出来的 mid 位于后一半元素的第一个位置 。如下：

```
[x, x, x, x, x, x]
 ^        ^     ^
 lo      mid    hi
```

它的计算方法是：`int mid = lo + (hi - lo + 1>> 1)`，通常右 mid 需要搭配 lo = mid, hi = mid - 1来使用，这样保证不会死循环。


- 区间开闭

```cpp
hi = nums.size(); // 开区间。
hi = nums.size() - 1; // 闭区间。
```

目前只有版本二中可能会使用开区间，其它版本不用。

- 循环条件

只有版本一是 `lo <= hi`，版本二、三都是 `lo < hi`，版本四的特殊性，保留两个候选，所以 `lo + 1 < hi`.

### 版本一：普通版

就是上面的题解。

### 版本二：高频版本（左 mid）

几乎可以求解任何二分类问题。

如果 hi = nums.size()，返回 target 应该插入的位置。你也可以把这个版本理解成左闭右开区间的查找。这样算出来的 mid 在实际数组中是个右 mid，但是这个 mid 对于左半部分来说是个右开区间，对于右半部分来说是个左闭区间。

如果 hi = nums.size() - 1，也是返回元素应该插入的位置，但是如果 target 比所有元素都大，只能返回最后一个位置。

```cpp
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size(); // <- or hi = nums.size() - 1
    while (lo < hi) {
        int mid = lo + (hi - lo >> 1); // <-
        if (target <= nums[mid]) {
            hi = mid; // <-
        } else {
            lo = mid + 1; // <-
        }
    }
    return lo;
}
```

上面这个模板可以直接拿去 AC [35-寻找插入位置](https://leetcode-cn.com/problems/search-insert-position/)

### 版本三：右 mid

语义是返回插入位置的前一个位置，这个模板用的非常少。能用它解决的，版本二几乎都能搞定。

比如 [3,6,9]

- 查询 3，插入位置是 a[1]（6 所在的位置）,实际返回 0
- 查询 2，插入位置是 a[0]，实际返回 -1 （如果 lo = -1，返回 -1，lo = 0 时则返回 0）
- 查询 10，插入位置是 a[3]，实际返回 2

```cpp
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1; // <- 甚至你可以有 lo = -1 的骚操作
    while (lo < hi) {
        int mid = lo + (hi - lo + 1 >> 1); // <-
        if (target >= nums[mid]) {
            lo = mid; // <-
        } else {
            hi = mid - 1; // <-
        }
    }
    return lo;
}
```

### 版本四：双候选

有时候，你无法确定某个元素是不是解，只能判断解可能在右侧或者左侧的时候，可以用这种方法。可以参考[658. 找到 K 个最接近的元素](https://leetcode-cn.com/problems/find-k-closest-elements/solution/658-zhao-dao-k-ge-zui-jie-jin-de-yuan-su-cer-fen-s) (版本4)

```cpp
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1; // <-
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo >> 1); // <-
        if (maybe_is_solution_or_in_right(nums[mid])) {
            lo = mid; // <-
        } else { // maybe_is_solution_or_in_left
            hi = mid; // <-
        }
    }
    
    // 最后剩余两个候选，再比较一次。
    return better_than(nums, lo, hi) ? lo : hi;
}
```
