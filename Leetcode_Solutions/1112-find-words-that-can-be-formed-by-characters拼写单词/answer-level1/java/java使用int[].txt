```
public int countCharacters(String[] words, String chars) {
        // 使用数组作为容器，26个字母按照顺序分别用数组的0-25号索引表示
        int[] chararr = new int[26];
        for (char c : chars.toCharArray()) {
            chararr[c - 'a'] = chararr[c - 'a'] + 1;
        }
        int total = 0;
        for (String word : words) {
            boolean flag = true;
            int[] used = new int[26];
            for (char c : word.toCharArray()) {
                // chars中没有该字母
                if (chararr[c - 'a'] == 0) {
                    flag = false;
                    break;
                }
                // 已经使用完所有的字母
                if (used[c - 'a'] >= chararr[c - 'a']) {
                    flag = false;
                    break;
                }
                // 已使用字母+1
                used[c - 'a'] = used[c - 'a'] + 1;
            }
            if (flag) {
                total += word.length();
            }
        }
        return total;
    }
```
