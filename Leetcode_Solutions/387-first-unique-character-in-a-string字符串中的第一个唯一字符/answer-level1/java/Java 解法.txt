```
class Solution {
    public static void main(String[] args) {
        firstUniqChar("leetcode");
    }
    public static int firstUniqChar(String s) {
        Map<Character, Integer> map = new LinkedHashMap<>();
        char[] c1 = s.toCharArray();
        for (int i = 0; i < c1.length; i++) {
            if (map.containsKey(c1[i])) {
                int counter = map.get(c1[i]);
                map.put(c1[i], ++counter);
            } else {
                map.put(c1[i], 1);
            }
        }

        char firstChar = '\u0000';
        int index = -1;

        for (Map.Entry entry : map.entrySet()) {
            int count = (int) entry.getValue();
            if (count == 1) {
                firstChar = (char) entry.getKey();
                break;
            }
        }

        for (int i = 0; i < c1.length; i++) {
            if (c1[i] == firstChar) index = i;
        }
        return index;

    }
}
```
