### 解题思路
重要的求得输入的mask，用于消除掉取反后高位的连续的1，变得到结果

### 代码

```cpp
class Solution {
public:
    int findComplement(int num) {
        int mask=0;
        int tmp=num;
        while(num)
        {
            num=num>>1;
            mask=mask<<1;
            mask=mask|1;
        }
        return (~tmp)&mask;
    }
};
```