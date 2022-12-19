- 双指针比较长度，最后是1的情况要判断


```
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int j = 0;
        int len = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 1){
                len = len > (i - j) ? len : (i - j);
                j = i + 1;
            } else if ((i == nums.length - 1) && (nums[nums.length-1] == 1)){
                len = len > (i+1 - j) ? len : (i+1 - j);
            }
        }
        return len;
    }
}
```


用时 3ms