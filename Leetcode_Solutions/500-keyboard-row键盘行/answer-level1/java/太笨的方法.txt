### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String[] findWords(String[] words) {
        List<String> results = new ArrayList<>();
        Map<Integer, Set<Character>> map = new HashMap<>();
        initMap(map);
        for (int i = 0; i < words.length; i++) {
            if (isOK(words[i], map)) {
                results.add(words[i]);
            }
        }
        String[] strings = new String[results.size()];
        for (int i = 0; i < strings.length; i++) {
            strings[i] = results.get(i);
        }
        return strings;
    }

    private boolean isOK(String word, Map<Integer, Set<Character>> map) {
        int key = getKey(Character.toUpperCase(word.charAt(0)), map);
        for (int i = 1; i < word.length(); i++) {
            if (getKey(Character.toUpperCase(word.charAt(i)), map) != key) {
                return false;
            }
        }
        return true;
    }

    private int getKey(char charAt, Map<Integer, Set<Character>> map) {
        for (Map.Entry entry : map.entrySet()) {
            Set<Character> set = (Set<Character>) entry.getValue();
            if (set.contains(charAt)) {
                return (int) entry.getKey();
            }
        }
        return -1;
    }

    private void initMap(Map<Integer, Set<Character>> map) {
        Set<Character> set1 = new HashSet<>();
        set1.add('Q');
        set1.add('W');
        set1.add('E');
        set1.add('R');
        set1.add('T');
        set1.add('Y');
        set1.add('U');
        set1.add('I');
        set1.add('O');
        set1.add('P');
        map.put(1, set1);


        Set<Character> set2 = new HashSet<>();
        set2.add('A');
        set2.add('S');
        set2.add('D');
        set2.add('F');
        set2.add('G');
        set2.add('H');
        set2.add('J');
        set2.add('K');
        set2.add('L');
        map.put(2, set2);

        Set<Character> set3 = new HashSet<>();
        set3.add('Z');
        set3.add('X');
        set3.add('C');
        set3.add('V');
        set3.add('B');
        set3.add('N');
        set3.add('M');
        map.put(3, set3);
    }
}
```