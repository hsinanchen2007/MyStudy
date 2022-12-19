```
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    int r = n;
    while (left <= right) {
        int mid = left + (right-left)/2;
        if (isBadVersion(mid)) {
            if (mid == 1 || !isBadVersion(mid-1)) {
                return mid;
            }
            r = mid;
            right = mid-1;
        }else {
            left = mid+1;
        }
    }
    return r;
}
```
