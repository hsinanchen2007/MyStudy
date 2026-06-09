### 解题思路
在生成dp数组时，因为状态只与前两项有关，可以复用变量，只保存两项，做到空间复杂度O(1)

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums==null||nums.length==0){
            return 0;
        }
        int n=nums.length;
        if(n==1){
            return nums[0];
        }
        return Math.max(rob(nums,0,n-1),rob(nums,1,n));

    }
    public int rob(int nums[],int first,int last){
        int pre2=0,pre1=0;
        for(int i=first;i<last;i++){
            int cur=Math.max(pre1,pre2+nums[i]);
            pre2=pre1;
            pre1=cur;
        }
        return pre1;
    }
}
```