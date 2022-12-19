```
class Solution {
    public int[] decompressRLElist(int[] nums) {
        // understand the question first
        List<Integer> li = new ArrayList<>();
        for(int i = 0; i < nums.length / 2; ++ i) {
            int a = nums[2 * i];
            int b = nums[2 * i + 1];
            while(a > 0) {
                -- a;
                li.add(b);
            }
        }
        int[] rs = new int[li.size()];
        for(int i = 0 ; i < rs.length; ++ i)
            rs[i] = li.get(i);
        return rs;
    }
}
```
