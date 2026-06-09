### 解题思路
数组存数，之后从数组两端一起遍历对比

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        int num[20]={0},i,j;
        if(x<0)return false;
        for(i = 0;x;i++){
            num[i] = x%10;
            x/=10;
        }
        for(j = 0,i--;j<=i;j++,i--)
            if(num[i]!=num[j])return false;
        return true;
    }
};
```