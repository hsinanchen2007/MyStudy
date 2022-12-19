### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int jump(int[] nums) {
        if(nums.length < 2){
            return 0;
        }
        int cur_max = nums[0];
        int pre_max = nums[0];
        int jump = 1;
        for(int i = 1; i < nums.length; i++){
            if(i > cur_max){
                cur_max = pre_max;
                jump++;
            }
            if(pre_max < nums[i] + i){
                pre_max = nums[i] + i;
            }
        }
        return jump;
    }
}
```