统计words中的频率,因为题目中说最大长度为10, 放到数组中,然后计算freq小于等于i的cnt,每个queries直接取数组即可
```java
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int[] charCntNum = new int[11];
        for (String word : words) {
            int freq = getFrequency(word);
            charCntNum[freq]++;
        }
        for (int i = 1; i < charCntNum.length; i++) {
            charCntNum[i] = charCntNum[i - 1] + charCntNum[i];
        }
        
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int cnt = getFrequency(queries[i]);
            ans[i] = words.length - charCntNum[cnt];
        }
        return ans;
    }

    private int getFrequency(String word) {
        int cnt = 1;
        char smallest = '\255';
        for (char c : word.toCharArray()) {
            if (c < smallest) {
                cnt = 1;
                smallest = c;
            } else if (c == smallest) {
                cnt++;
            }
        }
        return cnt;
    }
}
```