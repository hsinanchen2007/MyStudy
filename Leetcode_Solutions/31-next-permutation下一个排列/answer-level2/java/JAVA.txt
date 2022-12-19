### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        int i;
        for(i=nums.length-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                int min = nums[i];
                int min_index = i;
                for(int j=i;j<nums.length;j++){
                    if(nums[j]<min&&nums[j]>nums[i-1]){
                        min=nums[j];
                        min_index=j;
                    }
                }
                change(nums,i-1,min_index);
                break;
            }
        }
        if(i==0){
            Arrays.sort(nums);
        }
    }
    public void change(int[] nums, int start, int n){
        int temp = nums[start];
        nums[start] = nums[n];
        nums[n] = temp;
        Arrays.sort(nums,start+1,nums.length); 
    }
}
```