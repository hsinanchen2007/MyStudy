### 解题思路
观察34567812、78123456发现总有一半是升序的，用二分法一趟搞定。O（lgn）

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;
        int mid = left + (right-left)/2;

        while(left <= right){
            if(nums[mid] == target){
                return mid;
            }

            if(nums[left] <= nums[mid]){  //左边升序
                if(target >= nums[left] && target < nums[mid]){//在左边范围内
                    right = mid-1;
                }else{//只能从右边找
                    left = mid+1;
                }

            }else{ //右边升序
                if(target > nums[mid] && target <= nums[right]){
                    left = mid +1;
                }else{
                    right = mid-1;
                }

            }
            mid = left + (right-left)/2;
        }

        return -1;
    }
}
```