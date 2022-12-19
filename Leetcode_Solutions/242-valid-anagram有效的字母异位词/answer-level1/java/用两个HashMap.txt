```
class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap <Character, Integer> hm = new HashMap ();
        HashMap <Character, Integer> hm1 = new HashMap ();
        for(int i = 0; i < s.length(); i++){
            hm.put(s.charAt(i), hm.getOrDefault(s.charAt(i), 0) + 1);
        }
        for(int i = 0; i < t.length(); i++){
            hm1.put(t.charAt(i), hm1.getOrDefault(t.charAt(i), 0) + 1);
        }
        if(hm.equals(hm1)){
            return true;
        }
        else return false;
    }
}
```
