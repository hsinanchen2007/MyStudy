```
class Solution {
    public int validSubarrays(int[] nums) {
        Stack<Integer> s=new Stack<>();
        int result=0;
        int right=0;

        while (right<nums.length){
            if (s.isEmpty() || nums[right]>=nums[s.peek()]){
                s.push(right);
                right++;
            }
            else{
                while (!s.isEmpty() && nums[right]<nums[s.peek()]){
                    int index=s.pop();
                    result+=(right-index);
                }
                s.push(right);
                right++;
            }
        }
        while (!s.isEmpty()){
            result+=(nums.length-s.pop());
        }
        return result;
    }
}
```
