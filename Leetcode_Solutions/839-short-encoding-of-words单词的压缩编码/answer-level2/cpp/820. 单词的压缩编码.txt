### 解题思路
set存字符串的后缀，要先按长度排个序，要不然会wa，比如输入me time就会出错 答案就是不是任何在set中找到的字符串长度+个数

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a,const string &b){return a.size()>b.size()||(a.size()==b.size()&&a>b);});
        //reverse(words.begin(),words.end());
        for(auto it:words)cout<<it<<endl;
        unordered_set<string>t;
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            if(t.find(words[i])==t.end())ans+=words[i].size()+1;
            for(int j=1;j<=words[i].size();j++)
            {
                t.insert(words[i].substr(words[i].size()-j,j));
            }
        }
        return ans;
    }
};
```