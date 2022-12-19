
```java 
class Solution {
    public int scoreOfParentheses(String S) {
        int score[] = new int[S.length() + 1];
        if (S.length() == 0)
            return 0;
        int left = 0;
        for (int i = 0; i < S.length(); i++) {
            if(S.charAt(i) == '('){
                left++;                             //深度
            }else {
                if(score[left + 1] !=0){
                    score[left] += score[left + 1] * 2;
                    score[left + 1] = 0;
                }else {
                    score[left]++;
                }

                left--;
            }
        }
        return score[1];
    }
}
```
