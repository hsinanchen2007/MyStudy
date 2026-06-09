### 解题思路
申请一个辅助数组help，遍历第一次把奇数放进去，然后遍历第二遍把偶数放进去

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        if(nums==null||nums.length==0){
            return new int[]{};
        }
        int index=0;
        int[] help=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            if((nums[i]&1)==1){
                help[index++]=nums[i];
            }
        }
        for(int i=0;i<nums.length;i++){
            if((nums[i]&1)==0){
                help[index++]=nums[i];
            }
        }
        return help;
    }
}
```

### 复杂度分析
- 时间复杂度为O(N)
- 空间复杂度为O(N)