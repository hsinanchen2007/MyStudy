假设数组$arr$中小于$x$的元素组成的数组为$left(x)$，大于等于$x$的元素组成的数组为$right(x)$，则截断前缀和可写为：
$S(x) = sum(left(x)) + x * len(right(x))$
可见，求解本问题的算法必须基于数组的元素的序。

### 解法一：排序+二分查找
对数组进行预排序，然后计算数组的截断前缀和数组$S$，然后找出$target$在截断前缀和数组$S$中的位置即可。
假设数组$arr$的长度为$n$，算法的时间复杂度为：$O(n \log n)$、 空间复杂度： $O(n)$。
```python
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        n = len(arr)
        # special case #1
        if min(arr) * n >= target:
            q, r = divmod(target, n)
            return q + 1 if r > n // 2 else q
        # special case #2
        if sum(arr) <= target:
            return max(arr)
        # main case 
        arr.sort()
        S = arr[:] # S is refered to truncated sum
        for i in range(1, n):
            S[i] += S[i - 1]
        for i in range(n):
            S[i] += arr[i] * (n - 1 - i)
        def lower_bound(nums, target):     
            left, right = 0, len(nums) - 1
            while left < right:
                mid = (left + right) >> 1
                if nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid
            return left
        i = lower_bound(S, target)
        if S[i] == target: return arr[i]
        q, r = divmod(target - S[i - 1], n - i)
        return q + 1 + arr[i - 1] if r > (n - i) // 2 else q + arr[i - 1]
```

### 解法二：二分查找
利用截断前缀和$S(x)$关于$x$的单调非减特性，在闭区间$[\min(arr), \max(arr)]$内对$x$进行二分查找。
假设数组$arr$的长度为$n$，算法的时间复杂度为：$O(n \log (\max(arr) - \min(arr)))$、 空间复杂度： $O(1)$。
可见，本解法中空间复杂度得到了优化。

```python []
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        n = len(arr)
        # special case #1
        if min(arr) * n >= target:
            q, r = divmod(target, n)
            return q + 1 if r > n // 2 else q
        # special case #2
        if sum(arr) <= target:
            return max(arr)
        # main case 
        truncated_sum = lambda x: sum(min(a, x) for a in arr)
        # bisect search
        def lower_bound(target):     
            left, right = min(arr), max(arr)
            while left < right:
                mid = (left + right) >> 1
                if truncated_sum(mid) < target:
                    left = mid + 1
                else:
                    right = mid
            return left
        x = lower_bound(target)
        S1 = abs(truncated_sum(x - 1) - target)
        S2 = abs(truncated_sum(x) - target)
        return x if S1 > S2 else x - 1
```
```c++ []
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int Min(vector<int>& arr){
    int ans = INT_MAX;
    for (auto a: arr) ans = min(ans, a);
    return ans;
}

int Max(vector<int>& arr){
    int ans = 0;
    for (auto a: arr) ans = max(ans, a);
    return ans;
}

int Sum(vector<int>& arr){
    int s = 0;
    for (auto a: arr) s += a;
    return s;
}

int Truncated_Sum(vector<int>& arr, int x){
    int s = 0;
    for (auto a: arr) s += min(a, x);
    return s;
}

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int left = Min(arr);
        int right = Max(arr);
        // special case #1
        if (left * n >= target){
            int q = target / n;
            int r = target % n;
            return r > n / 2? q + 1: q;
        }
        // special case #2
        if (Sum(arr) <= target) return right;
        // main case 
        while (left < right) {
            int mid = (left + right) >> 1;
            if (Truncated_Sum(arr, mid) < target)
                left = mid + 1;
            else
                right = mid;
        }
        int S1 = abs(Truncated_Sum(arr, left - 1) - target);
        int S2 = abs(Truncated_Sum(arr, left) - target);
        return S1 > S2? left: left - 1;
    }
};
```


注： 感谢[@Magic](/u/magic/)的提醒。经过验证，[@xlz](/u/xlz/)的解法是有瑕疵的。之所以有瑕疵，除了没有考虑边界情况以外，还没有注意到截断和是基于排序的求和，[@xlz](/u/xlz/)的解法中直接把$\lfloor target / n \rfloor$作为数组的截断点是不正确的。建议[@LeetCode](/u/leetcode/)官方增加更多的测试用例。
