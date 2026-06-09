### 解题思路
此处撰写解题思路

### 代码

```java

/*
*问题的是使用快慢指针，问题的关键在于首先知道是排好序的，其次判断是否出现两次，在慢指针对应数组中找即可，而非快指针（被覆盖）

*/
class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length,res=2;
        if(len<=2)return len;
        for(int i=2;i<len;i++){
            if(nums[res-2] != nums[i]){
                nums[res++] = nums[i];
            }
        }
        return res;
    }
}
```