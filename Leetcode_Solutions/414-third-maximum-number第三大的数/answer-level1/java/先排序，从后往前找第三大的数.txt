### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int thirdMax(int[] nums) {
        int third = 1;
        Arrays.sort(nums);
        for(int i = nums.length-2;i >=0 ;i--){
            if(nums[i] < nums[i+1] ){
                third++;
            }
            if(third == 3){
                return nums[i];
            }
        }
        return nums[nums.length-1];
    }
}
```