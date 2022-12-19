```
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int i, j;
        vector<vector<int>> c(26,vector<int>(26,0));
        for(i = 0; i < votes.size(); i++)
        {
            for(j = 0; j < votes[i].size(); j++)
                c[votes[i][j]-'A'][j]++;
        }
        sort(votes[0].begin(), votes[0].end(), [&](auto a, auto b){
        	for(int j = 0; j < 26; j++)
		    {
		        if(c[a-'A'][j] == c[b-'A'][j])
		            continue;
		        return c[a-'A'][j] > c[b-'A'][j];
		    }
		    return a < b;
        });
        return votes[0];
    }
};
```
