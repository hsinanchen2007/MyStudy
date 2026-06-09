```
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int[] counts = new int[2000];
        int max = 0;
        for (int i = 0; i < words.length; i++) {
            int count = count(words[i]);
            counts[count]++;
            max = Math.max(max, count);
        }
        int[] answers = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int count = count(queries[i]);
            if (count >= max) {
                answers[i] = 0;
            } else {
                for (int j = count + 1; j <= max; j++) {
                    answers[i] += counts[j];
                }
            }
        }
        return answers;
    }

    private int count(String word) {
        int[] counts = new int[27];
        int min = word.charAt(0) - 96;
        for (char c : word.toCharArray()) {
            counts[c - 96]++;
            min = Math.min(min, c - 96);
        }
        return counts[min];
    }
}
```
