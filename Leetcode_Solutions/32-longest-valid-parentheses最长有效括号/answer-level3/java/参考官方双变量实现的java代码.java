一共扫描两次，一次从左到右，可以排除右括号多的时候错误的情况
一次从右到左，可以排除左括号多的情况，两种情况综合取最大数
```
class Solution {
    public int longestValidParentheses(String s) {
        if(s == null || s.equals("")) return 0;
        char[] sc = s.toCharArray();
        int len = sc.length;
        int left = 0;
        int right = 0;
        int max = 0;
        int i = 0;
        while(i<len){
            if(sc[i] == '(') left++;
            if(sc[i] == ')') right++;
            if(right > left) {
                left = 0;
                right = 0;
            }
            if(right == left){
                max = Math.max(max,right*2);
            }
            i++;      
        }

        i=len-1;
        left = 0;
        right = 0;
        while(i>=0){
            if(sc[i] == '(') left++;
            if(sc[i] == ')') right++;
            if(right < left) {
                left = 0;
                right = 0;
            }
            if(right == left){
                max = Math.max(max,right*2);
            }
            i--;      
        }

        return max;
    }
}
```
