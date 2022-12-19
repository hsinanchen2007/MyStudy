```
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 0;
    int right = n;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(isBadVersion(mid) == true){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return left;
}
```
