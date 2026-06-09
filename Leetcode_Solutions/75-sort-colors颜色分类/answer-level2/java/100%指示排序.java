### 解题思路
指示牌排序，击败100%的人
### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        int Max=2;
        int[] distrub=new int[Max+1];
        int[] tmp=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            distrub[nums[i]]++;
        }
        for(int i=1;i<distrub.length;i++){
            distrub[i]+=distrub[i-1];
        }
        for(int i=nums.length-1;i>=0;i--){
            tmp[distrub[nums[i]]-1]=nums[i];
            distrub[nums[i]]--;
        }
        System.arraycopy(tmp,0,nums,0,nums.length);
    }
}
```