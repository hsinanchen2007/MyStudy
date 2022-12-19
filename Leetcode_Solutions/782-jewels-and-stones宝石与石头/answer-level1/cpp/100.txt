### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        for(int i=0;i<J.size();i++){
            for (int j=0;j<S.size();j++){
                if(J[i]==S[j]){
                    count +=1;
                }
            }
        }
        return count;
    }
};
```