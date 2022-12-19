1.首先计算出中间位置mid对应的值；
2.如果中间值小于右边界的值，则表示mid处于有序状态，继续缩小边界搜索；
3.如果mid值大于右边界值，说明mid处于反转后值大的一端，所以继续增大边界
```java
public int findMin(int[] nums) {

    if (nums.length < 1) return -1;
    int left = 0;
    int right = nums.length-1;
    while (left < right) {
      int mid = left + ((right - left) >> 1);
      if (nums[mid] < nums[right]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return nums[left];
  }
```


