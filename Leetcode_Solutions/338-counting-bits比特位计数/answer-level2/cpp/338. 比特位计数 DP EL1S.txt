动态规划
有意思 奇数 = 偶数 + 1
偶数 = 偶数 * 2  （左移1）
```
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        for(int i = 1; i <= num; i++)
        {
            if(i & 1)
            {
                //奇数
                res[i] = res[i - 1] + 1;
            }
            else
            {
                //偶数
                res[i] = res[i >> 1];
            }
        }
        return res;
    }
};
```
