```java
class Solution {
    public List<String> commonChars(String[] words) {
        int n = words.length;
        int[][] counts = new int[n][26];
        int i = 0;
        for (String word : words) {
            for (char c : word.toCharArray()) {
                int idx = c - 'a';
                counts[i][idx]++;
            }
            i++;
        }
        List<String> list = new ArrayList<>();
        for (i = 0; i < 26; i++) {
            int num = counts[0][i];
            for (int[] count : counts) {
                num = Math.min(num, count[i]);
            }
            String c = "" + (char) (i + 'a');
            
            for (int j = 0; j < num; j++) {
                list.add(c);
            }
        }
        return list;
    }

}
```
