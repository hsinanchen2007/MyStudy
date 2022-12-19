```
class Solution {
    public int majorityElement(int[] nums) {
        int vote = 0;   int target = nums[0];
        for(int i =0;i<nums.length;i++){
            if(nums[i]==target) vote++;
            if(nums[i]!=target) vote--;
            if(vote==0&&(i+1)<nums.length) target=nums[i+1];
        }
        return target;
    }
}
```
从num[0]开始大混战,用target保存当前存活下来的数:
              1.当遇到不和它相等的数的时候,就开始碰瓷 vote--;
              2.当遇到和他相等的时候,,融入 vote++;
              3. 当vote==0 的时候两败俱伤,换下一个数继续碰瓷如果这个数为最后的数的时候那他就是PK完所有
              数所存活下来的数也就是众数。
**综上所述,最后存活下来的数一定是众数,因为他的数量大于一半。**
