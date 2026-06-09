每次记录上次出现的最大的数字
```
class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        Map<Integer,Integer> map = new HashMap<>();
        int ans = 1;
        for(int data : arr){
            Integer val = map.get(data - difference);
            if(val != null){
                val++;
                ans = Math.max(ans,val);
            }else
                val = 1;
            map.put(data,val);
            
        }
        return ans;
    }
}
```
