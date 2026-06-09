### 解题思路

循环累加

### 代码

```cpp
class Solution {
public:
    int countLetters(string S) {
        int tmp=1;
        int ret=0;
        for(int i=1,n=S.size();i<n;i++){
            if(S[i]!=S[i-1]){
                ret+=(tmp*(tmp+1))/2;
                tmp=1;
            }else ++tmp;
        }
        ret+=(tmp*(tmp+1))/2;
        return ret;
    }
};
```