执行用时 : 311 ms, 击败了36.50% 的用户.
内存消耗 : 76.8 MB, 击败了71.41% 的用户.
```
class Solution {
    int[] origin, res;
    public Solution(int[] nums) {
        origin = nums;
        res = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            res[i] = nums[i];
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        for(int i = 0; i < origin.length; i++){
            res[i] = origin[i];
        }
        return res;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        List<Integer> list = new ArrayList<>();
        for(int i:res){
            list.add(i);
        }
        for(int i = 0; i < res.length; i++){
            int index = (int)(Math.random()*list.size());
            res[i] = list.remove(index);
        }
        return res;
    }
}
```