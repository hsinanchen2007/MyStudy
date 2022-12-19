执行结果：
通过
显示详情
执行用时 :
3 ms
, 在所有 Java 提交中击败了
95.29%
的用户
内存消耗 :
42.7 MB
, 在所有 Java 提交中击败了
59.86%
的用户
```
class Solution {
    public int jump(int[] nums) {
        if(nums.length==0||nums.length==1)return 0;
        int count = 0;
        int i=0;
        int j = nums[0];
        if(j>=nums.length-1)return 1;
        count++;
        while(true){
            int max=0;
            for(int k=i+1;k<=j;k++){
                if((k+nums[k])>max)max = k+nums[k];
            }
            i = j;
            j = max;
            count++;
            if(j>=nums.length-1){
                return count;
            }
        }
    
    }
  
}
```
