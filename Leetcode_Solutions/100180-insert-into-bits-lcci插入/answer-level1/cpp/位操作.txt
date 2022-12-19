### 解题思路
此处撰写解题思路
将N的第i到j位置零，将M移至第i到j位，与N相加即可

### 代码

```cpp
class Solution {
public:
    int insertBits(int N, int M, int i, int j) {

    unsigned int n = 0xffffffff;
        if(j<31)
        {
            n = n<<j+1;
        }
        else
        {
            n = 0;
        }

        for(int t = 0;t<i;t++)
        {
            n+=pow(2,t);
        }
        unsigned int res = N & n;
        M = M<<i;
        res+=M;

        return res;

    }
};
```