二分法模板代码。使用**左 mid**。如果猜测的数字在 mid 右侧，则 lo = mid + 1，否则 hi = mid;

```cpp
int guessNumber(int n) {
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo >> 1);
        if (guess(mid) == 1) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}
```
