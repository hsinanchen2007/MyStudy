### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> cc;
        map<int,int> ::iterator it;
        int result(0);
        for(int i=0;i<time.size();i++)
        {
            cc[time[i]%60]++;
        }
        for(it=cc.begin();it!=cc.end();it++)
        {
            if(it->first==0)
            {
                result+=it->second*(it->second-1)/2;
            }
            else if(it->first==30)
            {
                result+=it->second*(it->second-1)/2;
            }
            else if(it->first>30)
            {
                continue;
            }
            else
            {
                result+=it->second*cc[60-it->first];
            }
        }
        return result;
    }
};
```