执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
95.04%
的用户
内存消耗 :
38.3 MB
, 在所有 Java 提交中击败了
85.44%
的用户
```
class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if(len==0)return 0;
        
        int j = len-2;
        int k = 1;
        for(int i=j; i>=0; i--){
            if(nums[i]==nums[i+1]){
                if(k==1){
                    k=0;
                    nums[j]=nums[i];
                    j--;
                }
            }else{
                nums[j]=nums[i];
                j--;
                k=1;
            }
        }
        for(int i = j+1; i<len; i++){
            nums[i-j-1]=nums[i];
        }
        return len-1-j;
    }
}
```
