### 解题思路
此处撰写解题思路
emm，看着和我打牌的不大一样，这个顺子肯定不是我***时候用的那种。
这道题主要是判断0的数量是否大于或者等于，数字之差的和
### 代码

```java
class Solution {
    public boolean isStraight(int[] nums) {
        Arrays.sort(nums);
        int count = 0, diff = 0;
        for(int i = 0; i < nums.length-1; i++){
            if(nums[i] == 0)
                count++;
            else{
                if(nums[i] == nums[i+1])
                    return false;
                if(nums[i]+1 != nums[i+1])
                    diff += nums[i+1] - nums[i]-1;
            }
        }
        return count >= diff;
    }
}
```