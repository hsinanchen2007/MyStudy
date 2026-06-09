
### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans;
        for(int i=0;i<T.size()-1;i++)
        {
            bool temp=true;
            for(int j=i+1;j<T.size();j++)
                if(T[j]>T[i])
                {
                    ans.push_back(j-i);
                    temp=false;
                    break;
                }
            if(temp) ans.push_back(0);
        }
        ans.push_back(0);
        return ans;
    }
};
```