```
 public int countCharacters(String[] words, String chars) {
        int ans = 0;
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            int[] b = new int[26];
            for (int i1 = 0; i1 < chars.length(); i1++) {
                b[chars.charAt(i1)-97]++;
            }
            for (int j = 0; j < word.length(); j++) {
                b[word.charAt(j)-97]--;
            }
            if (BTrue(b)) {
                ans += word.length();
            }
        }
        return ans;
    }

    private boolean BTrue(int[] b) {
        for (int i = 0; i < b.length; i++) {
            if (b[i] < 0) {
                return false;
            }
        }
        return true;
    }
```
