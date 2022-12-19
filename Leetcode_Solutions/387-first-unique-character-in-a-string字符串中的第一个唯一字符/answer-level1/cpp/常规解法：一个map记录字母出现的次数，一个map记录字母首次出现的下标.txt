```
class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> count,index;
        for(int i=0;i<s.length();i++)
        {
            if(count.find(s[i]) == count.end())
            {
                count[s[i]] = 1;
                index[s[i]] = i;
            }
            else
            {
                count[s[i]] += 1;
            }
        }

        int min = -1;
        for(auto it : count)
        {
            if(it.second == 1 && (min == -1 || min > index[it.first]))
                min = index[it.first];
        }

        return min;
    }
};

```