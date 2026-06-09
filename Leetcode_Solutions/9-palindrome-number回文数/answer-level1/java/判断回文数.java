// ### 解题思路
// *菜🐔本鸡，刚开始看一题一题不会，看过题解之后才知道了正确的做法之一*
//     当x大于0时一直判断首位数字与末尾数字是否相等，假如不相等就返回错误，否则将待监测的数掐头去尾，再进行判断。
// ### 代码

// ```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)
        return false;
        int dev=1;
        while(x/dev>=10){dev *= 10;}
        while(x>0){
            int left = x/dev;
            int right = x%10;
            if(left!=right) return false;
            x = (x % dev) / 10;
            dev /= 100;
        }
        return true;
    }
}
// ```