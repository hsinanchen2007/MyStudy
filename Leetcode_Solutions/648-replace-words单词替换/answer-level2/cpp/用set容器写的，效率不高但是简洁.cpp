思路很简单，先构建一个词典set，然后对sentence中的每个单词init，判断是否存在词根在set中
```
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        set<string> s;
        for(auto& a:dict)
            s.insert(a);
        stringstream ss(sentence);
        string ret;
        string init;
        if(sentence.empty())
            return ret;
        while(ss>>init)
        {
            for(int i = 0; i<init.size(); i++)
            {
                if(s.find(init.substr(0,i))!=s.end())
                {
                    init = init.substr(0,i);
                }
            }
            ret = ret+init+' ';
        }
        ret.erase(ret.end()-1);
        return ret;
    }
};
```
