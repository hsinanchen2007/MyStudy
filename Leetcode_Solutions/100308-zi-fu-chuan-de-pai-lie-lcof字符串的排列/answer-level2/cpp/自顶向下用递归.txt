### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> v;
    bool hashtable[26];
    /*void permutate(string &s,int index){
        if(index>=s.size()){
            v.push_back(s);
        }
        for(int i=index;i<s.size();++i){
            if(i==index||i!=index&&s[i]!=s[index]){
               swap(s[i],s[index]);
               permutate(s,index+1);
               swap(s[i],s[index]);
            }
        }
    }*/
    string ss;
    void permutate(string &s,int index){
        if(index>=s.size())
        {
            v.push_back(ss);
            return;
        }
        for(int i=0;i<s.size();++i){
            if(hashtable[i]==false){
                if(i!=0&&hashtable[i-1]==false&&s[i]==s[i-1])
                   continue;
                ss+=s[i];
                hashtable[i]=true;
                permutate(s,index+1);
                ss=ss.substr(0,ss.size()-1);
                hashtable[i]=false;
            }
        }
    }
    vector<string> permutation(string s) {
        sort(s.begin(),s.end());
        permutate(s,0);
        return v;
    }
};
```