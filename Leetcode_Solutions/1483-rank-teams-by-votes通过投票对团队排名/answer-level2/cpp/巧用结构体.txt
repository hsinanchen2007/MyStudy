### 解题思路


### 代码

```cpp
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string ans = "";
        if(votes.size() == 0)
            return ans;
        if(votes[0].size() == 0)
            return ans;
        vector<team> v;
        int hashTable[126] = {0};
        for(int i = 0 ; i < votes[0].size() ; ++i)
        {
            team t;
            t.name = votes[0][i];
            t.vote.resize(votes[0].size());
            v.push_back(t);
            hashTable[votes[0][i]] = i;
        }
        for(int i = 0 ; i < votes[0].size() ; ++i)
        {
            for(int j = 0 ; j < votes.size() ; ++j)
            {
                int ind = hashTable[votes[j][i]];
                v[ind].vote[i]++;
            }
        }
        sort(v.begin(), v.end());
        for(auto i : v)
        {
            ans += i.name;
        }
        return ans;
    }
private:
    struct team{
        string name;
        vector<int> vote;
        friend bool operator <(team a, team b)
        {
            if(a.vote == b.vote)
                return a.name < b.name;
            else
            {
                int index = 0;
                while(a.vote[index] == b.vote[index])
                {
                    index++;
                }
                return a.vote[index] > b.vote[index];
            }
        }
    };

};
```