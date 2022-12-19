## 快慢指针
像这种**死循环**的问题，**不知道什么时候结束循环**，首先想到的就应该是**快慢指针**
```cpp
class Solution {
public:
    int fun(int n){
        int ans=0, x;
        while(n){
            x = n%10;
            ans += x*x;
            n /= 10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        int slow, fast;
        slow = n;
        fast = fun(n);
        while(slow!=fast){
            slow = fun(slow);
            if(fast==1) return true;
            fast = fun(fast);
            fast = fun(fast);
        }
        if(fast==1) return true;
        else return false;
    }
};
```