### 解题思路
先放入map，在遍历两次map比较。

### 代码

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        if(arr.size()<=1)return true;
        map<int,int> m;
        m.insert(make_pair(arr[0],1));
        for(int i = 1;i < arr.size();i++)
        {
            if(m.find(arr[i]) == m.end())
            {
                m.insert(make_pair(arr[i],1));
            }
            else
            {
                m[arr[i]]++;
            }
        }
        for(map<int,int>::iterator it = m.begin() ; it != m.end();it++)
        {
            for(map<int,int>::iterator it2 = m.begin() ; it2 != m.end();it2++)
            {
                if(it->first == it2->first)
                {
                    continue;
                }
                if(it->second == it2->second)
                {
                    return false;
                }
            }

        }
        return true;
    }
};
```