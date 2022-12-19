class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
      int len1 = text1.length();
      int len2 = text2.length();
      int[][] count = new int[len1 + 1][len2 + 1];
      for (int i = 0; i <= len1; ++i) {
        count[i][0] = 0;
      }
      for (int j = 0; j <= len2; ++j) {
        count[0][j] = 0;
      }

      for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
           if (text1.charAt(i) == text2.charAt(j)) {
             count[i + 1][j + 1] = count[i][j] + 1;
           } else {
             count[i + 1][j + 1] = Math.max(count[i + 1][j], count[i][j + 1]);
           }
        }
      }
      return count[len1][len2];        
    }
}