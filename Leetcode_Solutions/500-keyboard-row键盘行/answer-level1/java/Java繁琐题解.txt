```
class Solution {
    public int judge(char ch) {
        char[][] chs = {{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'},
                {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},
                {'Z', 'X', 'C', 'V', 'B', 'N', 'M'}};
        for (int i1 = 0; i1 < chs.length; i1++) {
            for (int i2 = 0; i2 < chs[i1].length; i2++) {
                if (ch == chs[i1][i2]) {
                    return i1;
                }
            }
        }

        return 0;
    }

    public boolean f(String word) {
        word = word.toUpperCase();

        int a = judge(word.charAt(0));
        int b;
        for (int i = 1; i < word.length(); i++) {
            b = b = judge(word.charAt(i));;
            if (a != b) {
                return false;
            }
        }

        return true;
    }

    public String[] findWords(String[] words) {
        List<String> list = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            if (f(words[i])) {
                list.add(words[i]);
            }
        }

        return list.toArray(new String[]{});

    }
}
```
