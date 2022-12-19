### 解题思路
这种涉及到几个元素相加的都可以先求一下前缀和，就像本题，先求出整个数组的前缀和之后，通过前i-1项乘二加i项的值是否等于整个数组的前缀和就行。当然要时刻考虑一下特俗情况
### 代码

```java
class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0,start = 0;
        if(nums.length==0)
            return -1;
        for (int i=0;i<nums.length;i++){
            sum+=nums[i];
        }
        for (int i=0;i<nums.length;i++){
            if(i!=0)
                start+=nums[i-1];
            if(start*2+nums[i]==sum)
                return i;           
        }
        return -1;
    }
}
```