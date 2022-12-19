旋转的数组有一个特点，旋转点之后的数都比最左端的小，根据这个特点可以通过二分法找到旋转点，需要处理的特殊情况是没有旋转，通过判断最左端是否大于最右端可以解决这一情况，如果没有旋转，就直接进入二分查找找到target；找到旋转点后判断target是否小于最左端可以知道target在旋转点的左侧还是右侧，再通过二分法查找找到target。
        
```java
class Solution {
    public int search(int[] nums, int target) {
        if (nums.length == 0) {
            return -1;
        }
        int left = 0;
        int right = nums.length - 1;
        //判断是否旋转了，如有，进入if语块，找到旋转点
        if (nums[left] > nums[right]) {
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < nums[0]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            //判断在旋转点的左侧还是右侧
            if (target < nums[0]) {
                right = nums.length - 1;
            } else {
                right = left - 1;
                left = 0;
            }
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
}```

