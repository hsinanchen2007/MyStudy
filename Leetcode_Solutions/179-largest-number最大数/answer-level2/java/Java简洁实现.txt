执行用时 :6 ms, 在所有 java 提交中击败了91.24% 的用户
内存消耗 :36.2 MB, 在所有 java 提交中击败了97.80%的用户
```
class Solution {
    public String largestNumber(int[] nums) {
        
        String[] s = new String[nums.length];
        for(int i = 0; i < nums.length; i++)
            s[i] = String.valueOf(nums[i]);
        
        Arrays.sort(s,(a,b)->(b+a).compareTo((a+b)));
        if(s[0].equals("0"))return "0";
        StringBuilder builder = new StringBuilder();
        for(int i = 0; i < nums.length; i++)
            builder.append(s[i]);
                     
        return builder.toString();
    }
}
```
