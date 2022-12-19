### 解题思路
小于0的数排除；
大于等于0的数，求出反过来的数是否和原数一致即可。
```
        while(temp!=0){
            if(sum>INT_MAX/10||(sum==INT_MAX/10&&temp%10>INT_MAX%10)) return false;
            sum = sum*10 + temp%10;
            temp /= 10;
        }
```
例如传来的数为4596，则上面计算的sum=6954，与原数不同，说明不是回文数。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp = x;
        int sum = 0;
        while(temp!=0){
            if(sum>INT_MAX/10||(sum==INT_MAX/10&&temp%10>INT_MAX%10)) return false;
            sum = sum*10 + temp%10;
            temp /= 10;
        }
        if(sum==x) return true;
        else return false;
    }
};
```