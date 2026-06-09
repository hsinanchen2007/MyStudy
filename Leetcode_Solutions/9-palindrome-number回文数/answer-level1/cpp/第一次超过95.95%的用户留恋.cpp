### 解题思路
先排除一半，然后直接将数反过来比较

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        //queue<int>a;
        int copy=x;
        long temp=0;
        while(copy!=0){
            temp=temp*10+copy%10;
            copy/=10;
        }
        if(temp==x)
            return true;
        return false;
    }
};
```