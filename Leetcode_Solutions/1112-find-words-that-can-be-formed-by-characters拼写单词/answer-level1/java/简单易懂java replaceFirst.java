利用replaceFirst替换掉遇到的第一个字符为空。剩下的字符继续这样的操作。
```
    public int countCharacters(String[] words, String chars) {
        if (words == null || words.length == 0 || chars == null || chars.isEmpty()) {
            return 0;
        }
        String tmp = chars;

        int sum = 0;
        for (String word : words) {
            boolean flag = false; //是否能形成单词
            chars = tmp; // 每次开始新的单词时chars复原
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                // chars没有单词中的字符直接break
                if (!chars.contains(c + "")) {
                    flag = false;
                    break;
                }
                // 替换掉遇到的第一个字符为空
                chars = chars.replaceFirst(c + "", "");
                flag = true;
            }
            if (flag) {
                sum += word.length();
            }
        }
        return sum;
    }
```
