### 解题思路
此处撰写解题思路
找第一个等于target的位置，然后把数组分成两个，分别找左右边界，这就把问题分成了简单地二分法。
### 代码

```java
class Solution {
    public static int[] searchRange(int[] nums, int target) {
        int left=0;
        int right=nums.length-1;
        int mid = 0;
        int[] p = new int[2];
        while(left<=right){
            mid = left+(right-left)/2;
            if(nums[mid]>target) right = mid-1;
            else if(nums[mid]<target) left = mid+1;
            else if(nums[mid]==target){
                break;//找到了第一个等于target的位置
            }
        }
//这里判断上面的循环是break结束的，还是没有找到等于target结束的
        if(left<=right){//这是break结束的
            int right1 = right;
            int left1 = left;
            while(left<=right){//找左边界
                mid = left+(right-left)/2;
                if(nums[mid]>target) right = mid-1;
                else if(nums[mid]<target) left = mid+1;
                else if(nums[mid]==target) right = mid-1;
            }
            p[0] = left;
            left = left1;
            right = right1;
            while(left<=right){//找右边界
                mid = left+(right-left)/2;
                if(nums[mid]>target) right = mid-1;
                else if(nums[mid]<target) left = mid+1;
                else if(nums[mid]==target) left = mid+1;
            }
            p[1] = right;
        }
        else{//这是没有找到等于target的点结束的
            p[0] = -1;
            p[1] = -1;
        }
       return p;
    }
}
```