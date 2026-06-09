

```java
class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int i = 0;
        int j = 0;
        int res = 0;
        int[] count = new int[128];
        HashSet<Integer> set = new HashSet<Integer>();

        while(j < s.length()) {
            int c = (int)s.charAt(j)-' ';
            count[c]++;
            set.add(c);
            j++;
            while(set.size()>2) {
                count[s.charAt(i)-' ']--;
                if (count[s.charAt(i)-' ']==0) {
                    set.remove((int)s.charAt(i)-' ');
                }
                i++;
                if (set.size() <= 2) break;
            }
            res = Math.max(j-i, res);
        }
        return res;
    }
}
```