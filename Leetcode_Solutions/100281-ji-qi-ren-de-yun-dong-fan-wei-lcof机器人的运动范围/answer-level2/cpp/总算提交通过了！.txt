### 解题思路
提交了9次，总算通过了所有用例，不容易啊！

### 代码

```cpp
class Solution {
public:
    int  getDigitSum(int i)
    {
        int  res = 0;
        while (i > 0)
        {
            res += (i % 10);
            i /= 10;
        }

        return res;
    }

    int movingCount(int m, int n, int k) 
    {
        char  tag[m+1][n+1];
        memset((void *)tag, 0, sizeof(tag));

        tag[1][1] = 1;
        int res = 0;
        int sum;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                sum = getDigitSum(i-1) + getDigitSum(j-1);
                if ((1 == tag[i][j]) ||
                    ((1 == tag[i-1][j] || 1 == tag[i][j-1]) && (sum <= k)) )
                {
                    tag[i][j] = 1;
                    res++;
                }
            }
        }

        return res;
    }
};
```