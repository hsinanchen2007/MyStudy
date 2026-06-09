双映射的解法，其实还是挺麻烦的。
这里可以用单映射的方法，最后把映射表排序，然后检查相邻的元素有没有冲突的。
```
class Solution {
public:
    vector<string>& findAndReplacePattern(vector<string>& words, string pattern) {
        static std::vector<string> ans;
        ans.clear();
        vector<char> mp(26,'0'); //use vec for mapping
        for(auto &&word : words)
        {
            mp.clear();
            mp.resize(26,'0');
            if(word.size()!=pattern.size())
                continue;
            int isok=1;
            for(int i=0;i<word.size();++i)
            {
                auto &p = mp[word[i]-'a'];
                if(p=='0')
                {   
                    p=pattern[i];
                    continue;
                }
                if(p!=pattern[i])
                {
                    isok=0;
                }
            }
            if(!isok)
                continue;
            std::sort(mp.begin(),mp.end());//Sort the vector, If Element is same, They will be neighbors
            for(int i=1;i<mp.size();++i)
            {
                if(mp[i]==mp[i-1]&&mp[i]!='0')//take care of '0'
                    {
                        isok=0;
                        break;
                    }
            }
            if(isok)
                ans.push_back(word);       
        }
        return ans;
    }
};
```