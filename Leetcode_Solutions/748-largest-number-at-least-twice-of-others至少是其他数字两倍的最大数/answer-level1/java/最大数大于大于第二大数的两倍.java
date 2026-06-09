### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int dominantIndex(int[] nums) {
        if(nums.length==1)
        return 0;
        int number=0,max=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>max){
            max=nums[i];
            number=i;
            }
        }
        Arrays.sort(nums);
        if(max>=2*nums[nums.length-2])
        return number;
        return -1;
    }
}
```