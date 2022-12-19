思路参考官方贪心解法: `left`和`right`表示左括号的数量区间。
```
class Solution {
    public boolean checkValidString(String s) {
        int left = 0, right = 0;
        for(char c: s.toCharArray()){
            if(c == '('){
                left++; right++;
            } else if(c == ')'){
                left = Math.max(left - 1, 0);
                right--;
            } else {
                left = Math.max(left - 1, 0);
                right++;
            }
            if(left > right){
                return false;
            }
        }
        return left <= 0 && right >= 0;
    }
}
```