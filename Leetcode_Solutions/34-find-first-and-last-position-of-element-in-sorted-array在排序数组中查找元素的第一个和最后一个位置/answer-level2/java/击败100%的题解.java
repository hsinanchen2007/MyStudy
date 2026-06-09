```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
      int[] positions = { -1, -1};
      positions[0] = binarySearch(nums, 0, nums.length - 1, target, true);
      positions[1] = binarySearch(nums, 0, nums.length - 1, target, false);
      return positions;
    }

    private int binarySearch(int[] nums, int first, int last, int target, boolean isLeft) {
        int position = -1;  
        while(first <= last) {
            int mid = (first + last) / 2;
            if (nums[mid] == target) {
                position = mid;
                if (isLeft) {
                    last = mid - 1;
                } else {
                    first = mid + 1;
                }
            } else if (nums[mid] < target) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }
        return position;
    }
}
```
话说这个函数签名不是很好，返回一个Pair<Integer, Integer>是不是好一点？