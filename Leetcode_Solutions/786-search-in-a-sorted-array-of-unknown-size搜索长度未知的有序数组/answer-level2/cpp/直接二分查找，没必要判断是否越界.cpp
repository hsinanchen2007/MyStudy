right 设置为不可能达到的值，越界的情况包含在 midValue > target 的情况下。
```C++
int search(const ArrayReader& reader, int target) {
    int left = 0, right = 20000;
    while(left <= right){
        int mid = (left + right)/2;
        int midValue = reader.get(mid);
        if (midValue == target)
            return mid;
        else if (midValue < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
```
