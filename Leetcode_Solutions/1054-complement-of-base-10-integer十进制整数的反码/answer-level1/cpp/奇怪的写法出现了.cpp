### 解题思路
快乐就完事了
### 代码

```cpp
class Solution {
public:
    int bitwiseComplement(int N,int p=1) {
        return p>=N? p^N:bitwiseComplement(N,1+p*2);
    }
};
```