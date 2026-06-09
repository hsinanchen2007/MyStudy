### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int fib(int N) {
        if(N==0) return 0;
         else if(N==1) return 1;
         int first=0;
         int second=1;
         int res=0;
         for(int i=2;i<=N;i++)
         {
             res=first+second;
             first=second;
             second=res;
         }
         return res;
        
    }
};
```