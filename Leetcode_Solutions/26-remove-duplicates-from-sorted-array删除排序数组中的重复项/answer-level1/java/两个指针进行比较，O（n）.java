### 解题思路
两个指针所指元素进行比较。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int n=nums.length;
        int sum=1;
        int l=0;
        int r=1;
        while(r<n){
            if(nums[r]==nums[l]){
                ++r;
            }
            else{
                ++sum;
                nums[l+1]=nums[r];
                ++r;
                ++l;
            }
        }
        return sum;
    }
}
```