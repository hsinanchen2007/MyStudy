### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int f1=0;
        int f2=1;
        int result=0;
        while(--n){
            result=(f1+f2)%1000000007;
            f1=f2;
            f2=result;
        }
        return result;
    }
};
```