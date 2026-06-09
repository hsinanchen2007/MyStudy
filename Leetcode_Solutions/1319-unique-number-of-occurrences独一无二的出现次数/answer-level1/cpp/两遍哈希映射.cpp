```
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> dict;
        map<int,int> dict2;
        for(auto num : arr)
        {
            if(dict.find(num) != dict.end())
            {
                dict[num]+=1;
            }
            else
            {
                dict[num]=1;
            }
        }
        
        for(auto d : dict)
        {
            int key = d.first;
            int value = d.second;
            if(dict2.find(value)!=dict2.end())
            {
                dict2[value]++;
                if(dict2[value] > 1)
                    return false;
            }
            else
            {
                dict2[value]=1;
            }
        }
        
        return true;
    }
};
```