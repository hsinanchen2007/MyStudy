执行结果：
通过
显示详情
执行用时 :
6 ms
, 在所有 java 提交中击败了
80.61%
的用户
内存消耗 :
36.1 MB
, 在所有 java 提交中击败了
97.80%
的用户
```
class Solution {
    public String largestNumber(int[] nums) {
        int len = nums.length;
        if(len==0)return "";

        List<String> strs = new ArrayList<>(len);
        int max = 0;
        for(int i = 0; i < len ; i++) {
            if(nums[i] > max) max = nums[i];
            strs.add(String.valueOf(nums[i]));
        }
        if(max==0)return "0";
        StringBuffer sb = new StringBuffer();
        Collections.sort(strs,new Comparator<String> () {
            @Override
            public int compare(String s, String t1) {
                String a = s + t1;
                String b = t1 + s;
                return b.compareTo(a);
            }
        });
        strs.forEach(sb::append);
        return sb.toString();
    }
    
}
```
