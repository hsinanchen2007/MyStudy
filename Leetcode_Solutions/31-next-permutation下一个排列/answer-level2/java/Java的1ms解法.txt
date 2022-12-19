
执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :36.3 MB, 在所有 java 提交中击败了91.50%的用户

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        boolean sign = false;
        for(int i=nums.length-1;i>-1;i--){
            int r = 0, min = Integer.MAX_VALUE;
            for(int j=i+1;j<nums.length;j++){
                if(nums[j]>nums[i] && nums[j]<min){
                    min = nums[j];
                    r = j;
                    sign = true;
                }
            }
            if(sign){
                nums[r] = nums[i];
                nums[i] = min;
                Arrays.sort(nums,i+1,nums.length);
                break;
            }
        }
        if(!sign){Arrays.sort(nums);}
    }
}
```