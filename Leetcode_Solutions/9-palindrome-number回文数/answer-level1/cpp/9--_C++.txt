

### 代码

```cpp
class Solution{
public:
    bool isPalindrome(int x){
        if(x<0) return false;
        int rev=0;
        int tmp=x;
        while(x!=0){
            int pop=x%10;
            x/=10;
            if(rev>INT_MAX/10||(rev==INT_MAX/10 && pop>7)) return false;
            rev=rev*10+pop;
        }
        if(rev==tmp) return true;
        else return false;
    }
};
```