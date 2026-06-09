### 解题思路
执行用时 :992 ms, 在所有 Java 提交中击败了5.62%的用户
内存消耗 :50.9 MB, 在所有 Java 提交中击败了5.16%的用户

### 代码

```java
class Solution {
    public int findLHS(int[] nums) {
        int ans = 0;
        for(int i=0;i<nums.length;i++){
            int pivot = nums[i];
            int tmp=0;
            boolean allSame = true;
            for (int j=0;j<nums.length;j++){
                
                if(nums[j]==pivot+1 || nums[j]==pivot){
                    tmp++;
                    if(nums[j]!=pivot){
                        allSame=false;
                    }
                }
            }
            if(!allSame){
                ans = Math.max(ans, tmp);
            }
        }
        return ans;
    }
}
```