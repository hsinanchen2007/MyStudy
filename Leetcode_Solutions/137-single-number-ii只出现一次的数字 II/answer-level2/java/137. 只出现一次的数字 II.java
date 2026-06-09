### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        if(nums.length==1)return nums[0];
        Arrays.sort(nums);
        int i=0,j=1,k=2;
        while(k<nums.length){
            if(nums[i]==nums[j]&&nums[i]==nums[k]){
                i+=3;
                j+=3;
                k+=3;
            }else{
                return nums[i];
            }
        }
        return nums[nums.length-1];
    }
}
```