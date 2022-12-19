## 魔术索引

> CC189 第 08.03 题
>
> 难度：
>
> - `简单`
>
> tags：
>
> - `二分查找变形`

## 题目描述

魔术索引。 在数组`A[0...n-1]`中，有所谓的魔术索引，满足条件`A[i] = i`。给定一个有序整数数组，编写一种方法找出魔术索引，若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。

**示例1:**

```
 输入：nums = [0, 2, 3, 4, 5]
 输出：0
 说明: 0下标的元素为0
```

**示例2:**

```
 输入：nums = [1, 1, 1]
 输出：1
```

**提示:**

nums长度在[1, 1000000]之间

------

## 思路

和普通的二分查找不一样~~

千万注意哦，找到了不代表就是答案，因为答案要求的是最小的魔术索引！

根据 mid 将待搜索范围分成三份：

1. `nums[mid] == mid`：此时虽然找到了一个魔术索引，但可能不是最小的，所以再在左边继续查找，找到了就替换成更小的，没找到就用 mid 作为答案返回；
2. `nums[mid] != mid`：由于需要查找最小的魔术索引，所以先在左边查找，没找到才去右边

```cpp
class Solution {
public:
  int findMagicIndex(vector<int>& nums) {
    if (nums.empty()) return -1;
    return findMagicIndex(nums, 0, nums.size()-1);
  }
  int findMagicIndex(vector<int>& nums, int left, int right) {
    if (left > right) return -1;
    if (left == right) {
      return nums[left] == left ? left : -1;
    }
    int mid = left + (right - left) / 2;
    if (nums[mid] == mid) {
      int t = findMagicIndex(nums, left, mid - 1);
      return t == -1 ? mid : t;
    } else {
      int t = findMagicIndex(nums, left, mid - 1);
      if (t == -1) return findMagicIndex(nums, mid + 1, right);
      else return t;
    }
  }
};
```

