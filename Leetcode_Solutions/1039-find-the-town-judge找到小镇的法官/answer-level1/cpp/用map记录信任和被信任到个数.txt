```
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int, int> mp1;
        map<int, int> mp2;
        if(trust.size() == 0 && N == 1)
        {
            return 1;
        }
        for(int i=0; i<trust.size(); i++)
        {
            mp1[trust[i][0]] = trust[i][1];
            mp2[trust[i][1]]++;
        }
        for(auto m:mp2)
        {
            if(m.second == N-1 && mp1.count(m.first) == 0)
                return m.first;
        }
        return -1;
    }
};
```
