### 解题思路


### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if(words.size()==0||chars.length()==0)
        return 0;
        map<char,int> mp;
         map<char,int> mp2;
        map<char,int>::iterator it;
        for(int i=0;i<chars.length();i++)
        {
            it=mp.find(chars[i]);
            if(it!=mp.end())
            {
                it->second++;
            }
            else
           {
                mp.insert(pair<char,int>(chars[i],1));
           }
            
        }
        mp2=mp;
        int resnum=0;
        for(int i=0;i<words.size();i++)
        {
            bool flag=false;
            string s=words[i];
           // cout<<"s: "<<s<<endl;
          
            int j;
           
            for(j=0;j<s.length();j++)
            {
              //  cout<<"s[j]: "<<s[j]<<endl;
                it=mp.find(s[j]);
                if(it==mp.end())
               {
                   flag=true;
                    break;
               }
               else
              {
        
                 it->second--;
             
                 //cout<<it->second<<"  "<<wordnum<<endl;
                 if(it->second<0)
                 {
                     flag=true;
                  
                     break;
                 }
              }
            }
               
        
            for(it=mp2.begin();it!=mp2.end();it++)  //恢复初始情况
            {
                mp[it->first]=it->second;

               // cout<<"huifu: "<<it->first<<"  "<<it->second<<endl;
            }
           // cout<<"j:"<<j<<endl;
          //  cout<<s.length()<<endl;
            if(!flag)
            resnum+=s.length();
           // cout<<resnum<<endl;

        }
        return resnum;


    }
};
```