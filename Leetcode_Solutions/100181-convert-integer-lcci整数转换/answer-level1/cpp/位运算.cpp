### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int convertInteger(int A, int B) {
        int c=A^B;
        int cnt=0;
        for(int i=0;i<32;i++){
            if((c>>i)&1){
                cnt+=1;
            }
        }
        return cnt;
    }
};
```