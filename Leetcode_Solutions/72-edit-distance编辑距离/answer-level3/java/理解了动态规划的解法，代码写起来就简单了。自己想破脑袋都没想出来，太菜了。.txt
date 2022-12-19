每日一题越来越硬核了，连续三天都是困难。

class Solution {
    public int minDistance(String word1, String word2) {
        int[][] step = new int[word1.length() + 1][word2.length() + 1];
        for(int i = 0; i < step.length; i++){
            step[i][0] = i;
            for(int j = 1; j < step[i].length; j++){
                if(i == 0){
                    step[0][j] = j;
                    continue;
                }

                if(word1.charAt(i - 1) == word2.charAt(j - 1)){
                    step[i][j] = Math.min(Math.min(step[i - 1][j], step[i][j-1]), step[i - 1][j - 1] - 1) + 1;
                }else{
                    step[i][j] = Math.min(Math.min(step[i - 1][j], step[i][j-1]), step[i - 1][j - 1]) + 1;
                }
            }
        }
        return step[word1.length()][word2.length()];
    }
}