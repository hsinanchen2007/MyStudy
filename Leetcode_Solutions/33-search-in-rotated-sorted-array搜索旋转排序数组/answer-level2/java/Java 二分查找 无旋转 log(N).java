对于left,mid,right三个指针的值，只有三种情况
|序号|left|mid|right|
|--|--|--|--|
|1|小|中|大|
|2|大|小|中|
|3|中|大|小|
**大中小只是相对三个指针，例如第三种情况，队列的最大值和最小值都在`[mid, right]`之间**
**例如，`[4, 5, 6, 7, 8, 2, 3]`**
我用`lm`和`mr`来表示`nums[left] < nums[mid]`或`nums[mid] < nums[right]`吗？
我用`changeLeft`来表示是否需要改变左边界，你也可以当做是否落在`mid`和`right`之间的标记。
- 情况1
按照正常的二分查找即可；
- 情况2
只有`> nums[mid]`且`<= nums[right]`的时候才落在右侧；
- 情况3
只有`< nums[mid]`且`>= nums[left]`的时候才落在**左侧**；  
你可以对上述整个取反，也可改成`> nums[mid]`**或**`< nums[right]`，
**我用了一个`nums[mid] == target`条件来排除相等的情况**
至于为什么只要对照表格很好理解。



```java
class Solution {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        if(right == -1) return -1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;

            boolean lm = nums[left] < nums[mid];
            boolean mr = nums[mid] < nums[right];
            boolean changeLeft;
            
            if(lm && mr) 
                changeLeft = target > nums[mid];
            else if(!lm && mr) 
                changeLeft = target > nums[mid] && target <= nums[right];
            else 
                changeLeft = target > nums[mid] || target <= nums[right];
            
            if(changeLeft) left = mid + 1;
            else right = mid - 1;
        }
        
        return - 1;
    }
}
```