虽然我的解法时间上击败了100#的用户，但我感觉解法蛮暴力的
先写一个常规的二分查找函数`search`
```java
private int search(int nums[], int target, int left, int right) {
    while (left <= right) {
        int pivot = (left + right) / 2;
        if (nums[pivot] == target) {
            return pivot;
        } else if (nums[pivot] < target) {
            left = pivot + 1;
        } else {
            right = pivot - 1;
        }
    }
    return -1;
}
```
接着初次查找`pivot`，如果返回`-1`，直接`return`

设置两个标识`start`和`end`

令`start = end = pivot`

然后，分两部分查找

`start`和`end`分别作为接下来查找的右、左边界

- 对左部分右边界`start`递减进行二分查找
- 对右部分左边界`end`递增进行二分查找

完整代码如下
```java
private int search(int nums[], int target, int left, int right) {
    while (left <= right) {
        int pivot = (left + right) / 2;
        if (nums[pivot] == target) {
            return pivot;
        } else if (nums[pivot] < target) {
            left = pivot + 1;
        } else {
            right = pivot - 1;
        }
    }
    return -1;
}

public int[] searchRange(int[] nums, int target) {
    int[] result = {-1, -1};
    if (nums.length == 0) {
        return result;
    }
    int left = 0;
    int right = nums.length - 1;
    int pivot = search(nums, target, left, right);
    if (pivot == -1) {
        return result;
    }
    int start, end;
    start = end = pivot;
    while (true) {
        start = search(nums, target, left, start);
        if (start == -1) {
            break;
        }
        result[0] = start;
        start--;
    }
    while (true) {
        end = search(nums, target, end, right);
        if (end == -1) {
            break;
        }
        result[1] = end;
        end++;
    }
    return result;
}
```