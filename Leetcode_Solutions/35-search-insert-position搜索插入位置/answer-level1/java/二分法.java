### 解题思路
此处撰写解题思路
二分法：
用mid将判断区间分为两部分，如若mid小于target的话说明目标值在mid右边区间，反之同理
时间复杂度：O(longn)
空间复杂度：O(3),设定了min,mid,max三个变量


### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int min=0;
        int max=nums.length-1;
        if(nums[max]<target)
            return nums.length;

        while(min<max){
            int mid=min+(max-min)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
                min=mid+1;
            else
                max=mid;
        }
        return min;
        }
    }
```
暴力法：
当数组长度较大时，时间复杂度较高
时间复杂度：O(n),取决于数组的长度
空间复杂度：O(2)
```
class Solution {
    public int searchInsert(int[] nums, int target) {
        int s=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>=target){
                s=i;
                break;
            }
            if(nums[nums.length-1]<target)
                s=nums.length;
        }
        return s;
    }
}
```

