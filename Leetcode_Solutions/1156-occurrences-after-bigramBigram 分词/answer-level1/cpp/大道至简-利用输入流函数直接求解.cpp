```
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        vector<string> a;
        int cnt=2;//cnt 作为标记
        string word;
        istringstream ss(text);
        
        while(ss>>word)
        {
            if(word==first&&cnt==2)
                cnt--;
            else if(word==first&&cnt==1)//a b a a b c
                cnt=1;
            else if(word==second&&cnt==1)
                cnt--;
            else if(cnt==0)
            {
                a.push_back(word);
                if(word==first)
                  cnt=1;
                else cnt=2;
            }
            else 
                cnt=2;
        }
        return a;
    }
};
```
