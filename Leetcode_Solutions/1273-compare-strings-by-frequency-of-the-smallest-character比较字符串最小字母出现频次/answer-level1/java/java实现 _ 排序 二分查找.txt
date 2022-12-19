执行用时 :12 ms, 在所有 Java 提交中击败了91.46%的用户
内存消耗 :39.7 MB, 在所有 Java 提交中击败了100.00%的用户
参考下这位朋友[https://leetcode-cn.com/u/stevefrank/](https://leetcode-cn.com/u/stevefrank/)的[https://leetcode-cn.com/problems/compare-strings-by-frequency-of-the-smallest-character/solution/java-by-stevefrank/](https://leetcode-cn.com/problems/compare-strings-by-frequency-of-the-smallest-character/solution/java-by-stevefrank/) 的解答
```
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int[] result = new int[queries.length];
        int wordsLen = words.length, index;
        Integer[] wordsCount = new Integer[wordsLen];
        for (int i = 0; i < words.length; i++) {
            wordsCount[i] = countMinCode(words[i]);
        }
        Arrays.sort(wordsCount);
        for (int i = 0; i < queries.length; i++) {
            int countMinQuery = countMinCode(queries[i]);
            result[i] = wordsLen - 1 - BinSearch(wordsCount, countMinQuery);
        }
        return result;
    }

    public static int countMinCode(String s) {
        char min = s.charAt(0);
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < min) {
                min = s.charAt(i);
                count = 0;
            }
            if (s.charAt(i) == min) {
                count++;
            }
        }
        return count;
    }
    
    public static int BinSearch(Integer[] a, int value) {
        int low = 0;
        int n = a.length;
        int high = n - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (a[mid] > value) {
                high = mid - 1;
            } else {
                if ((mid == n - 1) || (a[mid + 1] > value)) return mid;
                else low = mid + 1;
            }
        }
        return -1;
    }
}
```
