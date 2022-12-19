### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int translateNum(int num) {
        int dp0=1;
        if(num<10)return 1;
        int a=num%10;
        int dp1=1,dp2;
        while(num>=10){
            num/=10;
            int b=num%10;
            if(b==1 || b==2&&a<=5){
                dp2=dp0+dp1;
            }
            else{
                dp2=dp1;
            }
            dp0=dp1;
            dp1=dp2;
            a=b;
        }
        return dp2;
    }
};
```