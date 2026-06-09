### 解题思路

### 代码

```cpp
class Solution 
{
public:
    vector<int> divingBoard(int shorter, int longer, int k) 
    {
        vector<int> res; 

        if(k==0) return res;

        for(int i=0;i<=k;i++)
        {
            int sum=i*longer+(k-i)*shorter;

            if(res.empty() || sum!=res.back())
                res.push_back(sum);
        }

        return res;
    }
};
```