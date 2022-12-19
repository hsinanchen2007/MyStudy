### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int sum=0;
        for(int i=0;i<S.size();i++){
            for(int j=0;j<J.size();j++){
                if(S[i]==J[j]){
                    sum++;
                }
            }
        }
        return sum;
        }
};
```