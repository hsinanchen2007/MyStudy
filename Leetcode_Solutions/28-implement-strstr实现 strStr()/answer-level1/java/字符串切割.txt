class Solution {
    public int strStr(String haystack, String needle) {
       if (needle.equals("") || needle.equals(haystack)){
            return 0;
        }
        int n = needle.length();
        Map<Integer,String> map = new HashMap<>();
        for (int i = 0; i <= haystack.length()-n; i++){
            map.put(i,haystack.substring(i,i+n));
        }
        for (Map.Entry<Integer,String> e : map.entrySet()){
            if (e.getValue().equals(needle)){
                return e.getKey();
            }
        }
        return -1;
    }
}
直接看代码，切割然后map保存，与needle匹配。2ms，37mb