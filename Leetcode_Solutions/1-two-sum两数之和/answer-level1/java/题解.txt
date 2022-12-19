### 解题思路
枚举一下, 效率惨不忍睹.

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int [] index=new int[2];
        int i=0,j=0;
        for(i=0;i<nums.length-1;i++){
            for(j=i+1;j<nums.length;j++){
                if(nums[i]+nums[j]==target){
                    index[0]=i;index[1]=j;
                }
            }
        }
        return index;
    }
}
```