### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int char_map[128]={0};
        int count = 0;
        for(int i=0;i<S.length();i++)//字符哈希
        {
            char_map[S[i]]++;
        }
        for(int i=0;i<J.length();i++)
        {
            count+=char_map[J[i]];       
        }
        return count;
    }
};
```