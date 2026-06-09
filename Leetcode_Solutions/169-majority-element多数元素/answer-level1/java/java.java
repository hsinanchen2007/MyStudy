### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int res=1,val=nums[0];
        for(int i=1;i<nums.length;i++){
            if(nums[i]!=val) res--;
            else res++;
            if(res<0){
                val=nums[i];
                res=1;
            }
        }
        return val;

    }
}
```