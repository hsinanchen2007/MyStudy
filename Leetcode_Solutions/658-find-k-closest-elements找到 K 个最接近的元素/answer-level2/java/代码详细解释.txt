本题的解法是利用二分法找到一个区间，对于一个区间来说，我们只需要确定其左边界，即可确定区间。所以可以将本题转化成求左区间在哪。

那么首先来确定左区间的范围为：[0,len(nums)-k]，比如数组为`1，2，3，4，5`，k=4的话，那么构成的区间只能是`[1，2，3，4]`和`2，3，4，5`，再往后长度就比k要小了。

所以现在要做的就是在这个范围里面，找到一个最合适的点，也就是我们的解了，这个就比较类似我们在一个有序数组里使用二分法寻找一个目标数了。

我们做的第一步是设定两个指针，`left`和`right`，分别指向`[0,len(nums)-k]`，可以看出来$left \le right$，然后按照二分法的正常思路，求解`中心点`的坐标：

```java
int mid = (left + right) >>> 1;
```

那么第一个问题来了，为什么可以二分？因为这是一个有序的数组，假设例子`1，2，3，4，5`，如果目标数字是个负数，那么如果`3`这个数字对应的位置是不可以的，它右边的一定全都不可以了，所以可以用二分的思想，代码如下：

```
int left = 0;
int right = arr.length - k;
while (left < right) {
    int mid = (left + right) >>> 1;
    if (Math.abs(x - arr[mid]) > Math.abs(x - arr[mid + k])) {
        left = mid + 1;
    } else {
        right = mid;
    }

}
```
对这段代码的解读如下：
1. 看到第三行while循环的判断条件部分，有一些疑问，`left < right`而在前面我们判断的是`left <= right`，这里没有等于号的原因是在以前的二分法里，`right=mid - 1`，而此处的是`right=mid`，所以如果又等于号，会陷入死循环。
2. `Math.abs(x - arr[mid]) > Math.abs(x - arr[mid + k])`这个比较是干什么的？首先需要明确`mid+k`位置是什么，我们的区间长度为k，所以区间对应的范围是`[mid, mid+k-1]`，所以`mid+k`是下一个区间`[mid+1, mid+k]`的右边界。比较这两个区间，实质就是比较`arr[mid]`和`arr[mid+k]`，因为这两个区间就这两个元素不一样，其余的是重合的。所以当`Math.abs(x - arr[mid]) > Math.abs(x - arr[mid + k])`成立时，也就是说左边的离目标值远一点，右边的近一点，所以右边的更好一点，所以我们进一步向右寻找，因为最佳的区间必然在右边，也就是`left=mid+1`，反之自然是向左寻找，`right=mid`。
3. 为什么是`right=mid`，不是`right=mid-1`，因为同二分搜索不同，我们并不能确定`mid`位置到底是不是最佳的位置，所以不能减一，而常见的二分搜索是能够判断`mid`位置是不是目标值的，所以是`mid-1`


到这里我们可以写出最终的答案了：
```java
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int left = 0;
        int right = arr.length - k;
        while (left < right) {
            int mid = (left + right) >>> 1;

            if (Math.abs(x - arr[mid]) > Math.abs(x - arr[mid + k])) {
                left = mid + 1;
            } else {
                right = mid;
            }

        }
        List<Integer> ans = new ArrayList<>();
        for (int i = left; i < left + k; i++) {
            ans.add(arr[i]);
        }
        return ans;
    }
}
```