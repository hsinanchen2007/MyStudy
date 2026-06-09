### 解题思路


### 代码

```cpp
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ans = 0;
        bool hash[light.size() + 1] = {false};
        int maxx = 0;
        int index = 1;
        for(int i = 0 ; i < light.size() ; ++i)
        {
            hash[light[i]] = true;
            maxx = max(maxx, light[i]);
            bool flag = true;
            while(index < maxx)
            {
                if(hash[index] == false)
                {
                    flag = false;
                    break;
                }
                index++;
            }
            if(flag)
                ans++;
        }
        return ans;
    }
};
```