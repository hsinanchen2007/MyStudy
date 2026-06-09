### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        int len=nums.length;
        int ans=0;
        if(len<3)
            return 0;
        Arrays.sort(nums);
        for(int i=0;i<=len-3;i++){
            int resume=target-nums[i];
            int left=i+1;
            int right=len-1;
            while(left<right){
                int sum=nums[left]+nums[right];
                if(sum<resume)
                {
                    ans+=(right-left);
                    left++;
                }
                else
                    right--;
            }
        }
        return ans;
    }
}
```