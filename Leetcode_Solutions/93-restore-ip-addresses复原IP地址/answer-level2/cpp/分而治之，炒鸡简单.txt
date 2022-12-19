### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> v;
    void dfs(string &s,int index,int anc,string ss){
       if(index>4)
          return;
       if(index==4&&anc>=s.size())
       {
             v.push_back(ss.substr(0,ss.size()-1));
             return;
       }
       if(s[anc]=='0')
       {
            ss+="0.";
            dfs(s,index+1,anc+1,ss);
       }
       else
       {
           int sum=0;
           for(int i=anc;i<s.size();++i){
              sum=sum*10+s[i]-'0';
              if(sum>0&&sum<=255){
                  string temp=ss+to_string(sum)+".";
                  dfs(s,index+1,i+1,temp);
              }else
                  break;
           }
       }
    }
    vector<string> restoreIpAddresses(string s) {
        string ss;
        dfs(s,0,0,ss);
        return v;
    }
};
```