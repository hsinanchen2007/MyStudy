### 解题思路
这种思路的话，最多需要执行循环31次
简明扼要地讲就是：从最低位开始判断，如果不同时为1或者不同时为0，那么++

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int Hamdis=0;
        while(x!=0||y!=0){
            if(((x&1)&&!(y&1))||!(x&1)&&(y&1))  {
                ++Hamdis;
            }
             x=x>>1;
             y=y>>1;
        }
        return Hamdis;
    }
};
```