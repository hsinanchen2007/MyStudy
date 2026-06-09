双指针算法，从两边往中间走，发现不一样的，要么删除左边，要么删除右边。
```
class Solution {
    public boolean validPalindrome(String s) {
        if(s == null || s.length() == 0){
            return true;
        }
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(s.charAt(left) != s.charAt(right)){
                break;
            }
            left++;
            right--;
        }
        if(left >= right) return true;
        
        return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
    }

    public boolean isPalindrome(String s, int left, int right) {
        while(left < right){
            if(s.charAt(left) != s.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
```
