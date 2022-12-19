```
class Solution {
    public String largestNumber(int[] nums) {
        if(nums.length == 0) return "";
        List<Integer> res = new ArrayList<>();
        for(int n : nums) {
            res.add(n);
        }
        res.sort((a, b) -> (b+""+a).compareTo(a+""+b));//与数组排成最小数类似，重定义sort
        StringBuffer sb = new StringBuffer();
        for(int n : res) {
            sb.append(n);
        }
        String result = sb.toString();
        if(result.charAt(0) == '0') {
            return "0";
        }
        return result;
    } 
}
```
