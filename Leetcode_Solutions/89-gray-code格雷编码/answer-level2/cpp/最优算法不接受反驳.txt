### 解题思路

不断和最低位异或

### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        int tot=1<<n;
        vector<int> ret(tot);
        ret[0]=0;
        for(int i=1;i<tot;i++){
            ret[i]=ret[i-1]^(i&-i);
        }
        return ret;
    }
};
```