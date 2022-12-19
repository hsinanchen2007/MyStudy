### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        int a=0,b=1,s;
        if(n<=0) return 0;
        if(n==1) return 1;
        while(n-2>=0)
        {
            s=a+b;
            a=b;
            if(s>1000000007) s%=1000000007;
            b=s;
            n=n-1;
        }
        
    
        return s;

    

    }
};
```