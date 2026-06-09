```
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        vector<int> ans;
        vector<int> rest;
        unordered_map<int,int> count1;
        unordered_map<int,int> count2;
        
        for(auto e : arr2){
            count2[e]++;
        }
        for(auto e : arr1){
            count1[e]++;
            if(!count2[e]){
                rest.push_back(e);
            }
        }
        sort(rest.begin(),rest.end());
        for(int i = 0;i < arr2.size(); ++i){
            for(int j = 0;j < count1[arr2[i]]; ++j){
                ans.push_back(arr2[i]);
            }
        }
        for(int i = 0;i < rest.size(); ++i){
            ans.push_back(rest[i]);
        }
        
        return ans;
    }
};
```