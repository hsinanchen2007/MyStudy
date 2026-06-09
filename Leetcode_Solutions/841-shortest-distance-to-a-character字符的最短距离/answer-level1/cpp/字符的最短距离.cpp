```
class Solution {
public:
    int distance(vector<int> nums,int pos)
    {
        int min_distance=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int distance=abs(pos-nums[i]);
            min_distance=min(distance,min_distance);
        }
        return min_distance;
    }
    
    vector<int> shortestToChar(string S, char C) 
    {
        vector<int> pos;
        vector<int> res;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]==C)
                pos.push_back(i);
        }
        for(int i=0;i<S.size();i++)
        {
            int dist=distance(pos,i);
            res.push_back(dist);
        }
        return res;
    }
};
```
