

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n>0){
            res+=(n&1);  //与运算
            n=n>>1;  //每次都忘n=，直接n>>1,傻了
            // res+=(n%2);
            // n/=2;
        }
        return res;
    }
};
```