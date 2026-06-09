```
class Solution {
    public String reverseVowels(String s) {

        HashMap<Character, Void> map = initMap();
        char[] newString = new char[s.length()];
        int begin = 0, end = s.length() - 1;
        while (begin <= end) {
            while (!map.containsKey(s.charAt(begin))) {
                newString[begin] = s.charAt(begin);
                begin++;
                if (begin>end)
                    return new String(newString);
            }

            while (!map.containsKey(s.charAt(end))) {
                newString[end] = s.charAt(end);
                end--;
                if (end<begin)
                    return new String(newString);
            }
            newString[begin] = s.charAt(end);
            newString[end] = s.charAt(begin);
            begin++;
            end--;
        }
        return new String(newString);
        
    }
     private static HashMap<Character, Void> initMap() {
        HashMap<Character, Void> map = new HashMap<>();
        map.put('a', null);
        map.put('e', null);
        map.put('i', null);
        map.put('o', null);
        map.put('u', null);
        map.put('A', null);
        map.put('E', null);
        map.put('I', null);
        map.put('O', null);
        map.put('U', null);
        return map;
    }
}
```
