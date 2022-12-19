### 解题思路
1、先查找该数组的有序范围。
2、在有序范围内用二分法进行查找。

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        //查找有序范围  
        while (left <= right && nums[left] > nums[right]){
            if (nums[left] == target){
                return left;
            }
            if (nums[right] == target){
                return right;
            }
            left++;
            right--;
        }

        //在有序范围内用二分法查找目标元素
        while (left <= right){
            int mid = (left + right)/2;
            if (nums[mid] == target){
                return mid;
            }else if (nums[mid] < target){
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return -1;
    }
}
```