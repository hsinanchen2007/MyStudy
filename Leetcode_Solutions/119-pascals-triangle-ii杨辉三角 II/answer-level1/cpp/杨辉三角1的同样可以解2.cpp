```
`class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        vector<int> t;
        for(int i=0;i < rowIndex + 1;++i){
            t.push_back(1);
            for(int j=i-1;j>0;--j) t[j]+=t[j-1];
            ans.push_back(t);
        }
        return t;
        //return ans;
    }
};`
```