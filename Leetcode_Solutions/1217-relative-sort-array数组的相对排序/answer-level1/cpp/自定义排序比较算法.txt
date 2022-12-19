```
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for(int i=0; i<arr2.size(); i++)
        {
            mp[arr2[i]] = i;
        }
        auto cmp = [&](int i, int j){
            int ii = -1;
            int ji = -1;
            if(mp.count(i)>0)
            {
                ii = mp.find(i)->second;
            }
            if(mp.count(j)>0)
            {
                ji = mp.find(j)->second;
            }
            if(ii != -1 && ji != -1)
            {
                return ii<ji;
            }
            else if(ii != -1)
            {
                return true;
            }
            else if(ji != -1)
            {
                return false;
            }
            else
            {
                return i<j;
            }
        };
        sort(arr1.begin(), arr1.end(), cmp);
        return arr1;
    }
};
```
