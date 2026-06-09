### 解题思路
写二分查找代码总是掌握不了边界条件，最后发现原因是，if() 的判断条件里面有两个条件，其逆命题就很难else全面，
所以，从今以后，我的if条件只加一个判定条件。

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        // i:[0,x]
        int l=0,r=x;
        long long p;
        while(l<=r){
            p=l+(r-l)/2;
            if(p*p<=x){
                if((p+1)*(p+1)>x){
                    break;
                }else{
                    l=p+1;
                }
            }else{
                r=p-1;
            }
        }
        return p;
    }
};
```