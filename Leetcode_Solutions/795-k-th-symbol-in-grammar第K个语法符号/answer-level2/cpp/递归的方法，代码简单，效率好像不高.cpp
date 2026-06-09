### 解题思路
如果k为奇数，则和母数字相同，如果k为偶数则和母数字相同，采用递归的方法往上找直到找到第一层得到答案

### 代码

```cpp
class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N==1)
        {
            return 0;    
        }
        int j=K&1;
        K=(K>>1)+j;
        if(!j)
        {
            return !kthGrammar(N-1,K);
        }else{
            return kthGrammar(N-1,K);
        }
        
    }
};
```