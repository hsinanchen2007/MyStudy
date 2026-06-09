### 解题思路
运用快速排序partition思想

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        if(nums.length == 1){return nums;}
        int left = -1;
        int cur = 0;
        while(cur < nums.length){
           if((nums[cur]&1) == 1){
               swap(nums,++left,cur++); //如果nums[i] 是奇数，就把cur和left的后一个位置交换，再把left++
           }else{
               cur++;
           } 
        }
        return nums;
    }
    public static void swap(int[] nums,int i,int j){
        if(i == j){return;}
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    } 
}
```