### 解题思路
通过map存储time数组模60的余数，遍历一次map即可，时间复杂度O(n)

### 代码

```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res=0;
        map<int,int> mp;
        for(int i=0;i<time.size();i++)
            mp[time[i]%60]++;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
            if(it->first<=30)
                if(it->first==30||it->first==0)
                    res+=it->second*(it->second-1)/2;
                else
                    res+=it->second*mp[60-it->first];
        return res;
    }
};
```