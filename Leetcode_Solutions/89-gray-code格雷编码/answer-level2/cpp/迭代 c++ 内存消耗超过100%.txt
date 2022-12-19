### 解题思路
n为0时 数组为 {0}
n为1时 数组为{0，1}
n为2时 数组为{00,01,11,10}
..................
n为k-1时 设数组为s
n为k时 数组为{s，2^n+s[2^(k-1)-1],2^n+s[2^(k-1)-2],...,2^n+s[0]}

数组长度以2倍速增长，前段为上一个数组的顺序，后段为上一个数组的倒叙再在最高位前加1

### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        if(!n)
        return {0};
        vector<vector<int>> vec;    
        vector<int> s={0,1};
        vec.push_back(s);
        for(int i=1;i<n;i++)
        {
            vector<int> p;
            for(int j=0;j<vec[i-1].size();j++)
            {
                p.push_back(vec[i-1][j]);
            }
             for(int j=vec[i-1].size()-1;j>=0;j--)
            {
                p.push_back(vec[i-1][j]+pow(2,i));
            }
            vec.push_back(p);
        }     
        return vec[n-1];
    }
};
```