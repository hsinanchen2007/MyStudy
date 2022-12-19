### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        int ans=0;
        for(int i=2;i<=n;i++){
            int t=n/i;
            int d=n%i;
            int w=pow(t,(i-d))*pow((t+1),d);
            ans=max(ans,w);
            if(ans>w)break;
        }
        return ans;
    }
};
```