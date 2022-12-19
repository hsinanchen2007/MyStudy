难点是查找子串，虽然串集合已经排序，但是查找子串的时候一定要找所有长度大于等于当前串的（因为这个错误提交了很多次），

```
class Solution {
public:

    bool findSubsequence(string& s1,string& s2){
        int i=0,j=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]!=s2[j])i++;
            else i++,j++;
        }
        return j==s2.size();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),[](const string& s1, const string& s2) { return s1.size()> s2.size();});
        // for(auto i:strs)cout<<i<<" ";
        for(int i=0;i<strs.size();i++){
            bool flag=false;
            for(int j=0; j<strs.size() && strs[j].size()>=strs[i].size();j++){//j<=i是不行的，因为你不知道接下来的串是否和当前相等，虽然你已经排序了
                if(i!=j  && findSubsequence(strs[j],strs[i])){flag=true;break;}
            }
            if(!flag)return strs[i].size();
        }
        return -1;
    }
};
```
