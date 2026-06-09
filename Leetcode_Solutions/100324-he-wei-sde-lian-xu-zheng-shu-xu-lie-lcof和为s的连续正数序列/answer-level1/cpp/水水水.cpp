### 解题思路
数学加暴力美学
等差数列求和 + 暴力求解

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int> > ans;
        vector<int > tmp;
        for(int i=(target-1)/2; i>=1; i--)
        {
            double aa = (2.0*target-1.0*i*i-1.0*i)/(2.0*(i+1));
            if(aa<=0) continue;
            int iaa = (int)aa;
            //printf("%lf %d\n",aa,iaa);
            if(iaa == aa)
            {
                tmp.clear();
                for(int j=0; j<=i; j++)
                {
                    tmp.emplace_back(iaa+j);
                }
                ans.emplace_back(tmp);
            }
        }
        return ans;
    }
};
```