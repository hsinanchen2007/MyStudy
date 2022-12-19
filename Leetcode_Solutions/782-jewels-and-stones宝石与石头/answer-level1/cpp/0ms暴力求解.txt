### 解题思路
我也不知道暴力法怎么这么快

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int num=0;
        for(int i=0;i<S.size();i++)
            for(int j=0;j<J.size();j++)
                if(S[i]==J[j])
                    num++;
        return num;
    }
};
```