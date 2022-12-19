### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        if(nums.length==0) return 1;
        Arrays.sort(nums);
        int j=1;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]>0){
                if(nums[i]!=nums[i+1]){
                    if(nums[i]==j){
                        j++;
                    }else{
                        return j; 
                    }
                }
            }
        }
        return j==nums[nums.length-1]?j+1:j;
    }
}
```