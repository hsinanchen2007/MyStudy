```
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) return false;

        LinkedHashMap<Character, Integer> sMap = new LinkedHashMap<Character, Integer> ();
        LinkedHashMap<Character, Integer> tMap = new LinkedHashMap<Character, Integer> ();
        for (int i = 0; i < s.length(); i++) {
            if (!sMap.containsValue(s.charAt(i))) sMap.put(s.charAt(i), i);
            else if (sMap.containsValue(s.charAt(i))) sMap.put(s.charAt(i), sMap.get(s.charAt(i)) + i);
        }

        for (int i = 0; i < t.length(); i++) {
            if (!tMap.containsValue(t.charAt(i))) tMap.put(t.charAt(i), i);
            else if (tMap.containsValue(t.charAt(i))) tMap.put(t.charAt(i), tMap.get(t.charAt(i)) + i);
        }

        List<Integer> sList = new ArrayList<Integer>();
        for (Map.Entry<Character, Integer> entry : sMap.entrySet()) sList.add(entry.getValue());
        
        List<Integer> tList = new ArrayList<Integer>();
        for (Map.Entry<Character, Integer> entry : tMap.entrySet()) tList.add(entry.getValue());

        if (sList.equals(tList)) return true;
        return false;
    }
}
```
