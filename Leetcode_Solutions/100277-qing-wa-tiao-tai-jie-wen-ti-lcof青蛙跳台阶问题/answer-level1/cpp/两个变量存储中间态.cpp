### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        int result = 0;
        if(n==1 || n==0) return 1;
        if(n==2) return 2;
        
        int pre = 1;
        int next = 2;
        for(int i=0;i<n-2;i++){
            result = (pre+next)% 1000000007;
            pre = (next)% 1000000007;
            next = result;
        }
        return result ;
    }
};
```