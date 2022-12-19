![每日一图：我老婆可爱不？](https://pic.leetcode-cn.com/5dfbe7593fe02d189ec15406aa2054077366fcbaca444ce8cdc0ad5b96888afa-1.jpg)

## 题解
首先虽然题目没说，但是实际运行下来数列是单调递增的，所以我们下面默认数列是递增的。

那么对于元素 `a[i]` 来说，如果它左边存在大于 `a[i]` 的元素，那么 `a[i]` 是一定要参与到排序里去的。或者说如果它右边存在小于 `a[i]` 的元素，那么 `a[i]` 也是要参与到排序里去的。

所以我们只需要寻找最靠右的那个数（满足左边存在大于它的数），和最靠左的那个数（满足右边存在小于它的数），那么这两个数之间就是要排序的区间了。

为什么最靠右的那个（满足左边存在大于它的数）数一定能保证右边没有更小的数了呢？因为如果右边还有更小的数，那么那个更小的数才是更靠右的啊，这就矛盾了。

所以我们只需要从左到右扫描一遍，用一个变量维护一下最大值就行了，然后反向再遍历一遍，维护一个最小值。

## 代码
### c++
```cpp
class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        int n = array.size();
        int maxx = INT_MIN, minn = INT_MAX;
        int l = -1, r = -1;
        for (int i = 0; i < n; ++i) {
            if (array[i] < maxx) r = i;
            else maxx = array[i];
        }
        for (int i = n-1; i >= 0; --i) {
            if (array[i] > minn) l = i;
            else minn = array[i];
        }
        return {l, r};
    }
};
```

### python
```python
class Solution:
    def subSort(self, array: List[int]) -> List[int]:
        n = len(array)
        maxx, minn = -10000000, 10000000
        l, r = -1, -1
        for i in range(n):
            if array[i] < maxx: r = i
            else: maxx = array[i]
        for i in range(n-1, -1, -1):
            if array[i] > minn: l = i
            else: minn = array[i]
        return [l, r]
```

---
> 关注公众号【算法码上来】，每日算法干货马上就来！
![宣传图片.jpg](https://pic.leetcode-cn.com/4f31ab1e06c2f8b8b301c6e45eee1ce39ebf96800c698bfca691e4a0b49ed474-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)
