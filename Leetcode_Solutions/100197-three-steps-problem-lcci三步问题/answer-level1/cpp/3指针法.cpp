### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int waysToStep(int n) {
        int p=1;
        if(n==1)return 1;
        if(n==2)return 2;
        int q=1;
        int r=2;
        int ans=0;
        for(int i=3;i<=n;i++){
            ans=0;
            ans=(ans+r)%1000000007;
            ans=(ans+p)%1000000007;
            ans=(ans+q)%1000000007;
            p=q;
            q=r;
            r=ans;
        }
        return ans;
    }
};
```