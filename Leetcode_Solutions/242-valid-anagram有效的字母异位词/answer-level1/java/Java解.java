```
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        HashMap<Character, Integer> map1 = new HashMap<>();
        HashMap<Character, Integer> map2 = new HashMap<>();

        char[] arr2 = t.toCharArray();
        char[] arr1 = s.toCharArray();
        Boolean flag1 = true;

        for (char ch : arr1) {
            if (!t.contains(String.valueOf(ch))) {
                flag1 = false;
            }
            if (!map1.containsKey(ch)) {
                map1.put(ch, 1);
            } else if (map1.containsKey(ch)) {
                map1.put(ch, map1.get(ch) + 1);
            }
        }
        System.out.println("flag1: " + flag1);
        for (char ch : arr2) {
            if (!map2.containsKey(ch)) {
                map2.put(ch, 1);
            } else if (map2.containsKey(ch)) {
                map2.put(ch, map2.get(ch) + 1);
            }
        }
        System.out.println(map1);
        System.out.println(map2);

        Boolean flag2 = true;
        Set<Map.Entry<Character, Integer>> set = map1.entrySet();
        for (Map.Entry<Character, Integer> entry : set) {
            if (!entry.getValue().equals(map2.get(entry.getKey()))) {
                flag2 = false;
            }
        }
        System.out.println(flag1);
        System.out.println(flag2);
        return flag1 && flag2;
    }
}
```
