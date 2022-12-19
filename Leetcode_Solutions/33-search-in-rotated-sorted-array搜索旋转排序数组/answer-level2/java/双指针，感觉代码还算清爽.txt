### 解题思路
双指针

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int i=0;
        int j=nums.length-1;
        while(i<j-2){
            if(nums[i]>target&&nums[j]<target){
                return -1;
            }
            if(nums[i]==target){
                    return i;
            }
            if(nums[j]==target){
                return j;
            }
            i++;
            j--;
        }
        for(int k=i;k<j+1;k++){
                if(nums[k]==target){
                    return k;
                }
            }
        return -1;
    }
}
```