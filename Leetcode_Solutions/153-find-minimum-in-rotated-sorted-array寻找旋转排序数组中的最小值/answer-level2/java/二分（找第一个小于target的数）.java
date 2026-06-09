### 解题思路
1. 数组旋转，则以第一个为target进行查找，查找第一个小于target的数
2. 最后需要对于未进行选择的情况进行额外判断
    left==nums.length-1&&nums[0]<nums[left]  则为未进行选择的情况，返回nums[0]，否则返回nums[left]

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        if(nums==null||nums.length==0){
            return 0;
        }
        int target = nums[0];
        int left = 0;
        int right = nums.length-1;
        while(left<right){
            int mid = left + (right-left)/2;
            // nums[mid]<target 则 [left,mid]
            // nums[mid]>target 则 [mid+1,right]
            if(nums[mid]<target){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        // 如果数组没有旋转，且为升序，按照上面代码逻辑，最后结果为left==nums.length-1,所以对这一情况进行额外判断
        return left==nums.length-1&&nums[0]<nums[left]?nums[0]:nums[left];
    }
}
```