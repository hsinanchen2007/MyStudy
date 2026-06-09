### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        int t=0;
        //构造t，使t的i到j之间为1，其余为0；0000...111...000
        for(int x=i;x<=j;x++){
            t=t|(1<<x);
        }
        t=~t;//将t求反,1111...000...111
        N=N&t;//N与t相与,就是将对应位清除。
        M=M<<i;
        return N|M;
    }
};
```