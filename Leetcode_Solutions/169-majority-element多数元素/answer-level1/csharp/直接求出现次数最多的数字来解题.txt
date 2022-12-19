```
public class Solution {
    public int MajorityElement(int[] nums) {
        Array.Sort(nums);
        int temp=nums[0];
        int answer=nums[0];
        int now=1;
        int max=0;
        for(int i=1;i<nums.Length;i++){
            if(nums[i]==temp){
                now++;
                if(now>=max){
                    max=now;
                    answer=temp;
                }
            }
            if(nums[i]!=temp){
                temp=nums[i];
                now=0;
            }
        }
        return answer;
    }
}
```
