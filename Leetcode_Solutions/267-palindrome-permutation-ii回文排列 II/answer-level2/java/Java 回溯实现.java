```
class Solution {
    public List<String> generatePalindromes(String s) {
        List<String> ans = new ArrayList();
        if (s == null) {
            return ans;
        }
        Map<Character, Integer> ch2Count = new HashMap();
        for (char ch : s.toCharArray()) {
            if (!ch2Count.containsKey(ch)) {
                ch2Count.put(ch, 0);
            }
            ch2Count.put(ch, ch2Count.get(ch) + 1);
        }
        if (!canPermutePalindrome(ch2Count)) {
            return ans;
        }
        String midCh = "";
        if (s.length() % 2 == 1) {
          for (char ch : ch2Count.keySet()) {
                if (ch2Count.get(ch) % 2 == 1) {
                    midCh = String.valueOf(ch);
                    break;
                }
            }          
        }
        Set<String> subSet = new HashSet();
        backTrack("", ch2Count, subSet, s.length());
        for (String sub : subSet) {
            ans.add(toResult(sub, midCh));
        }
        return ans;
    }

    public void backTrack(String str, Map<Character, Integer> ch2Count, Set<String> subSet, int size) {
        if (str.length() == size / 2) {
            subSet.add(str);
            return;
        }
        for (char ch : ch2Count.keySet()) {
            int count = ch2Count.get(ch);
            if (count >= 2) {
                ch2Count.put(ch, count - 2);
                backTrack(str + ch, ch2Count, subSet, size);
                // back track.
                ch2Count.put(ch, count);
            }
        }
    }

    public String toResult(String sub, String midCh) {
        String result = sub + midCh;
        for (int i = sub.length() - 1; i >= 0; i --) {
            result += sub.charAt(i);
        }
        return result;
    }
    
    public boolean canPermutePalindrome( Map<Character, Integer> ch2Count) {
        int evenCount = 0;
        for (Integer v : ch2Count.values()) {
            if (v % 2 == 1) {
                evenCount ++;
            }
            if (evenCount > 1) {
                return false;
            }
        }
        return true;
    }
}
```
