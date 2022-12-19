执行用时 :4 ms, 在所有 C++ 提交中击败了99.42% 的用户
内存消耗 :5.9 MB, 在所有 C++ 提交中击败了100.00%的用户

相当老的套路，很快就ac了

```
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long save=x,a=0;
        while(save!=0){
            a*=10;
            a+=save%10;
            save/=10;
        }
        if(a==x)
            return true;
        else
            return false;
    }
};
```
