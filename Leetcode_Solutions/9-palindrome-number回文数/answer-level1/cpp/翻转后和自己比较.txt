```
class Solution {
public:
    bool isPalindrome(int x) {// 反转后与原先的数比较，一样的话就是回文数
        if(x<0){
            return false;
        }
        long reverse = 0;
        int xx = x;//暂存原始的数
        while(x!=0){
            // int rem = x%10;
            reverse = reverse*10 + x%10;
            x = x/10;
        }
        return xx == reverse;
    }
};
```
