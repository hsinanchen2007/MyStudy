### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        if (words == null || words.length <= 0 || chars == null) {
            return 0;
        }
        int len = 0;
        Map<Character, Integer> m = new HashMap<>();
        Map<Character, Integer> mTemp = new HashMap<>();
        for (int i = 0; i < chars.length(); i++) {
            if (m.get(chars.charAt(i)) == null) {
                mTemp.put(chars.charAt(i), 1);
                m.put(chars.charAt(i), 1);
            } else {
                mTemp.put(chars.charAt(i), mTemp.get(chars.charAt(i)) + 1);
                m.put(chars.charAt(i), m.get(chars.charAt(i)) + 1);
            }
        }
        for (String s : words) {
            if (masterWord(s, m, mTemp)) {
                len += s.length();
            }
        }
        return len;
    }

    private boolean masterWord(String s, Map<Character, Integer> m, Map<Character, Integer> mTemp) {
        for (int i = 0; i < s.length(); i++) {
            if (mTemp.get(s.charAt(i)) == null || mTemp.get(s.charAt(i)) < 1) {
                recoverMap(m, mTemp);
                return false;
            } else {
                mTemp.put(s.charAt(i), mTemp.get(s.charAt(i)) - 1);
            }
        }
        recoverMap(m, mTemp);
        return true;
    }

    private void recoverMap(Map<Character, Integer> m, Map<Character, Integer> mTemp) {
        for (Character key : m.keySet()) {
            mTemp.put(key, m.get(key));
        }
        return;
    }
}
```