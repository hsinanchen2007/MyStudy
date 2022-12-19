### 解题思路
二分查找法，找到对应的数，然后这个数左右找，就能把和target相同的数全部找出来。

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int count=0;//计数
        int left=0;
        int right=nums.length-1;
        if(nums.length==0)return 0;
        if(nums.length==1){
            if(nums[0]==target)return 1;
            else return 0;
        }
        while(left<=right){
            int minIndex=(left+right)/2;
            int minValue=nums[minIndex];
            if(minValue<target){
                left=minIndex+1;
            }else if(minValue>target){
                right=minIndex-1;
            }else{
                count++;
                int temp_left=minIndex-1;
                int temp_rigth=minIndex+1;
                while(temp_left>=0 && nums[temp_left]==target){
                    count++;
                    temp_left--;
                }
                while(temp_rigth<=nums.length-1 && nums[temp_rigth]==target){
                    count++;
                    temp_rigth++;
                }
                return count;
            }
        }
            return count;
    }
}
```