### 解题思路
两点要注意
第一点在于对j的理解，假设M的二级制宽度为L（M>=0时，M>>L=0，M<0时，L取最大值31）
所以要插入二进制宽度为M的话，起点为i，终点最小应为i+L。
所以这里取终点 = j < i+L ? i+L : j 
第二点就是负数不能左移，但可以右移，做<<左移位操作时要小心。

### 代码

```cpp
class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        
        if(i<0)
            i=0;
        for(int index=31; index>=0; index--){
            if(M & 1<<index){
                if(j < i+index)
                    j = i+index;
                break;
            }
        }
        if(j>31)
            j=31;

        unsigned int base = 0x1;

        for(int index=0; index<=j; index++){
            
            if(index >= i){
                N &= ~base;
                N |= (0x1 & M) << index;
                M >>= 1;
            }
            base = base << 1;
        }
        return N;
    }
};
```