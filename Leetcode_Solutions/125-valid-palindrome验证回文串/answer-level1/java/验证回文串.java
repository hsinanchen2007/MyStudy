1. 将字符串转成数组，小写转大写；
2. 同时从数组头部向后遍历，从数组尾部向前遍历, 遇到其它字符则跳过，相同则继续，不同则return false；
```
class Solution {
    public boolean isPalindrome(String s) {
        char[] sarr = s.toLowerCase().toCharArray();
        int i = 0, j = sarr.length - 1;
        while(i < j){
            if(sarr[i] == sarr[j] && ((sarr[i] >= 'a' && sarr[i] <= 'z' )||(sarr[i] >= '0' && sarr[i] <= '9' ))){
                i++; j--;
            }else if((sarr[i] < 'a' || sarr[i] > 'z' ) && (sarr[i] < '0' || sarr[i] > '9' )){
                i++;
            }else if((sarr[j] < 'a' || sarr[j] > 'z' ) && (sarr[j] < '0' || sarr[j] > '9' )){
                j--;
            }else
                return false;                                
        }
        
        return true;
    }
}
```