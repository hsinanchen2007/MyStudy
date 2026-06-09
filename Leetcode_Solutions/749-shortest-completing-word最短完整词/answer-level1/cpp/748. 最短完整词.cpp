```

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string initials;
// initial licensePlate with only lower chars
        for(char c:licensePlate)
        {
                if(c>='a' && c<='z')
                    initials+=c;
                else if(c>='A' && c<='Z')
                {
                    c+=32;
                    initials+=c;
                }
        }
//map for template
        unordered_map<char,int> temp;
        for(char c:initials)
            temp[c]++;
        vector<unordered_map<char,int>> wordslist;
//compare 
        for(string s:words)
        {
            unordered_map<char,int> tmp;
            for(char c:s)
                tmp[c]++;
            wordslist.push_back(tmp);
    
        }
      //  cout<<initials<<endl;
        // for(auto w:wordslist)
        //     cout<<w.size()<<endl;
        int len=16;
        string res;
        for(int i=0;i<words.size();i++)
        {
            int flag=1;
         for(char c: initials)
        {
       //     cout<<c<< " "<<temp[c]<<" "<< wordslist[i][c]<<endl;
         if(wordslist[i][c]<temp[c])
         {
             flag=0;
             break;
         }
         }
            // cout<<flag<<endl;
             
            if(flag &&words[i].length()<len)
            {
                    len=words[i].length();
                    res=words[i];
            }
       //     cout<<len<<endl;
        
            }
        return res;
    }
};

```