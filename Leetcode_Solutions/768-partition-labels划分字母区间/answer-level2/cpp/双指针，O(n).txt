
```
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int ind[26]={0};
        // 记录26个字母最后出现的位置
        for(int i=1;i<s.size();i++){
            ind[s[i]-'a']=i;
        }
        int mins=0, maxe=ind[s[0]-'a'];
        
        for(int i=0;i<s.size();i++){
            maxe = max(maxe, ind[s[i]-'a']);
            // 当遍历到最短的首位相接位置时，加入vector
            if(i==maxe){
                ans.push_back(maxe-mins+1);
                mins=i+1;
                maxe=i;
                continue;
            }
        }
        return ans;
    }
};
```
