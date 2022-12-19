```
class Solution {
    public int findRepeatNumber(int[] nums) {
        int[] tmps = new int[nums.length];
        for (int num : nums) {
            tmps[num]++;
        }
        for (int i = 0; i < tmps.length; i++) {
            if(tmps[i] > 1){
                return i;
            }
        }
        return -1;
    }
}
```
额外空间还是bitmap好用