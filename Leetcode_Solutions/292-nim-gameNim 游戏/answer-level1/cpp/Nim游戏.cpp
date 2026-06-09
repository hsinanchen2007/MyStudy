当之无愧入门题

如果是4的倍数，则false，否则，true

但是3以下要特别判断

规律写个表找规律就行了

```cpp
class Solution {
public:
    bool canWinNim(int n) {
        if(n<=3)
            return true;
        if(n%4==0)
            return false;
        else
            return true;
    }
};
```