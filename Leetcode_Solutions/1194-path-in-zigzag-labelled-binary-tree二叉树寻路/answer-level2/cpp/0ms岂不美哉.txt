```
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        while(label>0){
            ans.push_back(label);
            label/=2;
        }
        reverse(ans.begin(),ans.end());
        int t=2/(2-ans.size()%2);
        for(int i=ans.size()%2;i<ans.size();i+=2){
            ans[i]=t*3-1-ans[i];
            t*=4;
        }
        return ans;
    }
};
```
