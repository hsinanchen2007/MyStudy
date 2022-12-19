### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int binaryGap(int N) {
        bitset<32> bit(N);
        int ans=0;
        for(int i=0;i<32;++i)
        {
            if(bit.test(i))
            {
                for(int j=i+1;j<32;++j)
                {
                    if(bit.test(j))
                    {ans=max(ans,j-i);
                    break;}
                }
            }
        }
        return ans;
    }
};
```