class Solution {
    public int strStr(String haystack, String needle) {
        if ("".equals(needle)) return 0;
        int[] next = next(needle);
        for (int i = 0, j = -1; i < haystack.length(); i++){
            while (j >= 0 && haystack.charAt(i) != needle.charAt(j + 1)) j = next[j];
            if (haystack.charAt(i) == needle.charAt(j + 1)) j++;
            if (j == needle.length() -1) return i - j;//匹配上了， 如果要求所有的在这修改
        }
        return -1;
    }
    //求next数组
    private int[] next(String needle){
        int[] next = new int[needle.length()];
        Arrays.fill(next, -1);
        for (int i = 1, j = -1; i <  needle.length(); i++){
            while (j >=0 && needle.charAt(i) != needle.charAt(j + 1)) j = next[j];//后退一步
            if(needle.charAt(i) == needle.charAt(j + 1)) j++;
            next[i] = j;
        }
        return next;
    }
}