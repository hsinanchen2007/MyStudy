![image.png](https://pic.leetcode-cn.com/a9adebdad0db88495943146742184956d1aab3a0b1aa83d471ddc48bab5dc651-image.png)

### 解题思路
用bitset记录石头是否为石头，bitset<128>仅占用4个int的空间

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res=0;
        bitset<128>mp;
        for(auto x:J)
            mp[x]=1;
        for(auto x:S)
            if(mp[x])
                res++;
        return res;
    }
};
```