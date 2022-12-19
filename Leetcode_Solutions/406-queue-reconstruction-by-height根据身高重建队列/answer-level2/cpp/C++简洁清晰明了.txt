```
class Solution 
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        //身高降序排列，人数升序排列
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b)
        {
            if(a[0] > b[0]) 
                return true;
            if(a[0] == b[0] && a[1] <b[1])
                return true;
            return false;
        });

        vector<vector<int>> res;
        for(int i = 0; i < people.size(); i++)
        {
            res.insert(res.begin() + people[i][1], people[i]);
        }
        /*for(auto& e : people)
        {
            res.insert(res.begin() + e[1], e);
        }
        */
        return res;
    }
};

```
