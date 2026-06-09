### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        else if(n==1)return 1;
        else{
            int first=0,second=1;
            for(int i=2;i<=n;i++){
                int c=(first+second)%1000000007;
                first=second;
                second=c;
            }
            return second;
        }
    }
};
```