
### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        sort(J.begin(), J.end());
        sort(S.begin(), S.end());
        int i = 0, j = 0, count = 0;
        while(j < S.size() && i < J.size()){
            if(J[i] == S[j]){
                count++;
                j++;
            }else if(J[i] < S[j]){
                i++;
            }else{
                j++;
            }
        }
        return count;
    }
};
```