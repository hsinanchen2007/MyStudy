```cpp []
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        for (int i = 0; i < J.length(); i++)
            for (int j = 0; j < S.length(); j++)
                if (S[j] == J[i])
                    res++;
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/ad8806f7f5a268b3dff0c014192aab751f336b211b8833fadc8a1a51c4dbd98e-image.png)
