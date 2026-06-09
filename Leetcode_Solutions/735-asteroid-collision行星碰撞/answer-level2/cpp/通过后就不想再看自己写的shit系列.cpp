### 解题思路
一个个push进去再判断一下

### 代码

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int i=0;i<asteroids.size();++i)
        {
            ans.push_back(asteroids[i]);
            while(true)
            {
                if(ans.empty()||ans.back()>0)
                break;
                else
                {
                    int last=ans.back();
                    ans.pop_back();
                    if(ans.empty()||ans.back()<0)
                    {
                        ans.push_back(last);
                        break;
                    }
                    else
                    {
                        int last1=ans.back();
                        ans.pop_back();
                        if(abs(last1)!=abs(last))
                        ans.push_back(abs(last1)>abs(last)?last1:last);
                    }
                }
            }
        }
        return ans;
    }
};
```