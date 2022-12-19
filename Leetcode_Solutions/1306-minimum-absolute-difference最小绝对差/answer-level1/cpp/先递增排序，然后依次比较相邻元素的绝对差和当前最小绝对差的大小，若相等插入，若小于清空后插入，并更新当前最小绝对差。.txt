```
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        
        sort(arr.begin(),arr.end());
        
        int minDist = 0, dist = 0;
        
        for(int i=0;i<arr.size()-1;i++)
        {
            dist = arr[i+1] - arr[i];
            
            if(minDist == 0 || dist < minDist)
            {
                minDist = dist;
                res.clear();
                vector<int> tmp;
                tmp.push_back(arr[i]);
                tmp.push_back(arr[i+1]);
                res.push_back(tmp);
            }
            else if(dist == minDist)
            {
                vector<int> tmp;
                tmp.push_back(arr[i]);
                tmp.push_back(arr[i+1]);
                res.push_back(tmp);
            }
            
        }
        
        return res;
    }
};
```