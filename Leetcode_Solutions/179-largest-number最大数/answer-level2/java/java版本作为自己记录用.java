```
class Solution {
    private class largestNumberComparator implements Comparator<String> {
        @Override
        public int compare(String a, String b) {
            String order1 = a + b;
            // System.out.println(order1);
            String order2 = b + a;
            // System.out.println(order2);
            return order2.compareTo(order1);
        }
    }
    // java比较函数的写法
    public String largestNumber(int[] nums) {
        if(nums == null || nums.length == 0) return "";
        String[] ansStr = new String[nums.length];
        for(int i = 0; i < nums.length; i++) {
            ansStr[i] = String.valueOf(nums[i]);
            //System.out.println(ansStr[i]);
        }
        Arrays.sort(ansStr, new largestNumberComparator());
        if(ansStr[0].equals("0")) {
            return "0";
        }

        StringBuilder sb = new StringBuilder();
        for(String str : ansStr) {
            sb.append(str);
        }
        return sb.toString();
    }
}
```
