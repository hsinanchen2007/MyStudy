![image.png](https://pic.leetcode-cn.com/a28a8dda4b30243996d631b3fc756325b59a31b20d0ba4a936cf8576749c7d0c-image.png)
代码：

class Solution {
    public int game(int[] guess, int[] answer) {
        int count = 0;
       for(int i=0;i<guess.length;i++){
           if(guess[i] == answer[i]){
               count++;
           }
       } 
       return count;
    }
}