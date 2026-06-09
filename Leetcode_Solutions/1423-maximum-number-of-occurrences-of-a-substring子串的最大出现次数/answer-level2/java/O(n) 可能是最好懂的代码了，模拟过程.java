注意就是maxSize可以省略，因为超过minSize的字符传的数量一定被符合minSize的要少。
```
class Solution {
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        int dnum = 0;
        int[] arr = new int[26];
        
        for(int i = 0; i < minSize; i++) {
            char c = s.charAt(i);
            if (arr[c - 'a'] == 0) {
                dnum++;
            }
            
            arr[c - 'a']++;
        }
        
        int res = 0;
        Map<String, Integer> map = new HashMap();
        if (dnum <= maxLetters) {
            String str = s.substring(0, minSize);
            int c = map.getOrDefault(str, 0);
            map.put(str, c + 1);
            if (c + 1 > res) {
                res = c + 1;
            }
        }
        
        int len = s.length();
        for(int i = 1; i <= len - minSize; i++) {
            char cdel = s.charAt(i-1);
            char cadd = s.charAt(i + minSize - 1);
            arr[cdel - 'a']--;
            if (arr[cdel - 'a'] == 0) {
                dnum--;
            }
            
            if (arr[cadd - 'a'] == 0) {
                dnum++;
            }
            
            arr[cadd - 'a']++;
            
            if (dnum <= maxLetters) {
                String str = s.substring(i, i + minSize);
                int c = map.getOrDefault(str, 0);
                map.put(str, c + 1);
                if (c + 1 > res) {
                    res = c + 1;
                }
            }
        }
        
        return res;
    }
}
```
