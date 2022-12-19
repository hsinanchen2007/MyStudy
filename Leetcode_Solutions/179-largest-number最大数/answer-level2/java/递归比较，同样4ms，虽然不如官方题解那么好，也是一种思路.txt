```java
class Solution {
    private static class SC implements Comparator<String> {
        public int compare(String a, String b) {
            // 首先比较两者前缀的字典序大小
            int prefixLen = Math.min(a.length(), b.length());
            String apre = a.substring(0, prefixLen);
            String bpre = b.substring(0, prefixLen);
            int preComRes = apre.compareTo(bpre);

            // 若前缀不相等，则字典序大的应该放前面
            if (preComRes != 0) return -preComRes;
            
            // 若前缀相等，递归比较长字符串的后缀和短字符串
            if (a.length() < b.length()) {
                return this.compare(a, b.substring(prefixLen));
            } else if (a.length() > b.length()) {
                return this.compare(a.substring(prefixLen), b);
            } else {
                return 0;
            }
        }
    }

    public String largestNumber(int[] nums) {
        int n = nums.length;
        if (n == 0) return "0";
        if (n == 1) return Integer.toString(nums[0]);
        String[] numStrings = new String[n];
        for (int i = 0; i < n; i++) numStrings[i] = Integer.toString(nums[i]);
        Arrays.sort(numStrings, new SC());
        if (numStrings[0].equals("0")) return "0";
        StringBuilder sb = new StringBuilder();
        for (String s : numStrings) sb.append(s);
        return sb.toString();
    }
}
```
