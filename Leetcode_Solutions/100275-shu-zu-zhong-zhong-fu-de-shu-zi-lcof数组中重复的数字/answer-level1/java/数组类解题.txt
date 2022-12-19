### 解题思路
此处用一个新的数组来统计个数，下标为传入数组的值

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int[] numbs = new int[nums.length];
        for(int i=0 ; i< nums.length; i++){
            int numbb_tmp = numbs[nums[i]];
            numbs[nums[i]] = numbb_tmp+1; 
            if(numbb_tmp>0){
                return nums[i];
            }
        }
        return -1;
    }
}
```