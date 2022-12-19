### 解题思路
这个代码也够短了啊

### 代码

```cpp
class Solution {
public:
    int bitwiseComplement(int N)
    {
        int one = 1;
        int bit =N==0?1:log2(N)+1;
        N^=(int)(pow(2,bit)-1);
        return N;
    }
};

```