### 解题思路

总结规律

### 代码

```cpp
class Solution {
public:
    int digitsCount(int d, int low, int high) {
        return helper(d,high)-helper(d,low-1);
    }
    int helper(int d,int a){
        int ind=1;
        int ret=0,tmp;
        while(ind<=a){
            ret+=ind*(a/(10*ind));
            if(d==0)ret-=ind;
            tmp=(a/ind)%10;
            if(tmp>d)ret+=ind;
            else if(tmp==d)ret+=(a%ind)+1;
            ind*=10;
        }
        return ret;
    }
};
```