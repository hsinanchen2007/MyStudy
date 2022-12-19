### 解题思路
可以观察出来：如果要求n位格雷码，那么可以把n位格雷码分成两部分，前一部分为n-1位格雷码的集合在最后加一个0，后一部分为n-1位格雷码的集合逆序之后在最后加1。

### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        int cnt = pow(2, n);
        createGray(n, cnt);
        vector<int> ans;
        for(int i = 0 ; i < cnt ; ++i)
        {
            int sum = 0;
            for(int j = 0 ; j < n ; ++j)
            {
                sum += a[i][j] * pow(2, j);
            }
            ans.push_back(sum);
        }
        return ans;
    }
    void createGray(int n, int cnt)
    {
        if(n == 0)
            return ;
        for(int i = 0 ; i < cnt / 2 ; ++i)
        {
            a[i][n - 1] = 0;    //第n位补0
            a[cnt - i - 1][n - 1] = 1;  //第n位补1
        }
        createGray(n - 1, cnt / 2);
        for(int i = cnt / 2 ; i < cnt ; ++i)
        {
            for(int j = 0 ; j < n - 1 ; ++j)
            {
                a[i][j] = a[cnt - i - 1][j];    //逆序
            }
        }
    }
private:
    int a[3000][50];
};
```