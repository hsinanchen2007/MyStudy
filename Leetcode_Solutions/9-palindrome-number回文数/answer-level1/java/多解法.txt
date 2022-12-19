大学生的入门练手题。很多解法。
1.将int转换为String类型，之后进行匹配。
```
class Solution {
    public boolean isPalindrome(int x) {
        String str=String.valueOf(x);
        int lo=0,hi=str.length()-1;
        while(lo<hi){
            if(str.charAt(lo)==str.charAt(hi)){
                lo++;
                hi--;
            }
            else{
                return false;
            }
        }
        return true;
    }
}
```
2.参考上一题，将整数反转。如果反转后与原数相等，为回文串。
```
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)
            return false;
        int temp=x;
        int y=0;
        while(x>0)
        {
            y*=10;
            y+=x%10;
            x/=10;
        }
        return temp==y;
    }
}
```
