### 解题思路
比较每个数，加入新数组中，感觉好像是最简单的吧

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] result=new int[nums.length];
        for(int y=0;y<nums.length;y++){
            int count=0;
            for(int x=0;x<nums.length;x++){
                if(nums[y]>nums[x]){
                    count++;
                }
            }
            result[y]=count;
        }
        return result;
    }
}
```