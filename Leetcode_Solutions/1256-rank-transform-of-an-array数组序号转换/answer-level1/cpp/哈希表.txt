### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)
        return {};
        vector<int>ans=arr;
        sort(ans.begin(),ans.end());
        map<int,int>res;
        int count=1;
        for(int i=0;i<ans.size();i++){
            if(i>0&&ans[i]==ans[i-1]) continue;
            res[ans[i]]=count++;
        }
        for(int j=0;j<ans.size();j++){
            ans[j]=res[arr[j]];
        }
        return ans;
    }
};
```