注释 ：
- 你可以认为数组中所有元素的值互不相同。
- 数组元素的值域是 [-9999, 9999]。

因此我们认为，数组最大长度为 2 万。

```java
public int search(ArrayReader reader, int target) {
    int left = 0, right = 20000;
    while (left <= right) {
        int mid = (left + right) >> 1;
        int midVal = reader.get(mid);
        if (midVal == 2147483647 || midVal > target) { // 越界或者非越界情况下，继续二分查找左半部分
            right = mid - 1;
        } else if (midVal == target) { // 相等返回
            return mid;
        } else { // 当前值大于目标值，继续二分查找右半部分
            left = mid + 1;
        }
    }
    return -1;
}
```