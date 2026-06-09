```
class Solution {
    public int calculateTime(String keyboard, String word) {
        int result = 0;
        int index = 0;
        for (int i = 0; i < word.length(); i++) {
            int tmp = keyboard.indexOf(word.substring(i, i + 1));
            result += Math.abs(tmp - index);
            index = tmp;
        }
        return result;
    }
}
```
