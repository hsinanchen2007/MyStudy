### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        if(nums.length==0)
            return -1;
        int count = 1;
        int major = nums[0];
        for(int i=1;i<nums.length;i++){
            if(nums[i] == major)
                count++;
            else{
                count--;
                if(count==0){
                    major = nums[i];
                    count = 1;
                }

            }
        }
        //为了判断找出来的元素出现的次数是否是超过一半
        if(count<=0)
            return -1;
        else
            return major;

    }
}
```