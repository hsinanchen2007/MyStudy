java 暴力破解
```
class Solution {
    public int countCharacters(String[] words, String chars) {
        int count = 0;

        for (String word : words) {
            List<String> list = new ArrayList<>(Arrays.asList(chars.split("")));
            for (int i=0; i<word.length(); i++) {
                if (!list.contains(String.valueOf(word.charAt(i)))) {
                    break;
                }
                list.remove(String.valueOf(word.charAt(i)));

                if (i == word.length()-1) {
                    count += word.length();
                }
            }
        }
        return count;
    }
}
```