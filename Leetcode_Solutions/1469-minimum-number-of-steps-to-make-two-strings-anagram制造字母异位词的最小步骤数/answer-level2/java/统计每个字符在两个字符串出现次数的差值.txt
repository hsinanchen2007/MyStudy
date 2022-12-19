```
class Solution {
    public int minSteps(String s, String t) {
        Map<Character, Integer> mapS = new HashMap<>();
        Map<Character, Integer> mapT = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            mapS.merge(s.charAt(i), 1, Integer::sum);
        }
        for (int i = 0; i < t.length(); i++) {
            mapT.merge(t.charAt(i), 1, Integer::sum);
        }

        Set<Character> set = new HashSet<>();
        set.addAll(mapS.keySet());
        set.addAll(mapT.keySet());

        int diff = 0;
        for (char key : set) {
            diff += Math.abs(mapS.getOrDefault(key, 0)
                    - mapT.getOrDefault(key, 0));
        }
        return diff % 2 == 0 ? diff / 2 : diff / 2 + 1;
    }
}
```
