### 解题思路
使用 char 节省内存

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        char lenJ = J.size();
        char lenS = S.size();
        int ans = 0;
        for (char i=0;i<lenS;i++){
            for (char j=0;j<lenJ;j++){
                if (S[i] == J[j]){
                    ans ++;
                    break;
                }
            }
        }
        return ans;
    }
};
```