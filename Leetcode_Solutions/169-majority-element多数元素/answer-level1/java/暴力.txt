### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }
        int len = nums.length / 2;
        Arrays.sort(nums);
        int cnt = 1;
        for(int i = 1; i < nums.length; i++){
            if(i - 1 > 0 && nums[i] == nums[i-1]){
                cnt++;
                if(cnt > len){
                    return nums[i];
                }
            }else{
                if(cnt > len){
                    return nums[i-1];
                }
                cnt = 1;
            }
        }
        return nums[0];
    }
}
```