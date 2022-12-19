### 解题思路


### 代码

```cpp
class Solution {
public:
    int multiply(int A, int B) {
        int ans=0;
        for(int i=0;i<32&&B!=0;i++){
            //判断B的最后一位是0还是1来决定结果是加上A<<i还是加0；
            ans=(B&1)==1?ans+(A<<i):ans;
            B=B>>1;
        }
        return ans;
    }
};
```