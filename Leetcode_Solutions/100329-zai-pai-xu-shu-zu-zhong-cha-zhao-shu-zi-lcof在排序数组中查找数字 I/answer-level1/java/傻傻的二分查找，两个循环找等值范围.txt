### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        int result = 0;
        int current = -1;
        while (low <= high) {
            int mid = (low+high)/2;
            if(nums[mid]>target){
                high=mid-1;
            }else if(nums[mid]<target ){
                low=mid+1;
            }else{
                result++;
                current = mid;
                break;
            }
        }

        if(current!=-1) {
            for (int i = 1; current + i < nums.length; i++) {
                if (nums[current + i] == nums[current]) {
                    result++;
                } else {
                    break;
                }
            }

            for (int i = 1; current - i >= 0; i++) {
                if (nums[current - i] == nums[current]) {
                    result++;
                } else {
                    break;
                }
            }
        }
        return result;
    }
}
```