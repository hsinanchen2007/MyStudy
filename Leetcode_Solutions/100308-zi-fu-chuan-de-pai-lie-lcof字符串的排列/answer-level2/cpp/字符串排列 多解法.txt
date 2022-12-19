# 1.交换解法

没有办法解决重复的问题。
```
class Solution {
public:
    vector<string> str;
    vector<string> permutation(string s) {
        permu(s,0);
        D(str);//去重
        return str;
    }
    void D(vector<string> &str)
    {
        sort(str.begin(),str.end());
        str.erase(unique(str.begin(),str.end()),str.end());
    }
    void permu(string s,int j)
    {
        if(s.size()==j)
        {
            if(s.size())
                str.push_back(s);
        }else
        {
            for(int i=j;i<s.size();i++)
            {
                int t=s[i];
                s[i]=s[j];
                s[j]=t;

                permu(s,j+1);

                t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
        }
    }
};
```
# 2.STL
```
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> vec;
        sort(s.begin(),s.end());
        do{
            vec.push_back(s);
        }while(next_permutation(s.begin(),s.end()));
        return vec;
    }
};


```
# 3.回溯法
```
class Solution {
public:
    vector<string> vec;
    vector<string> permutation(string s) {
        sort(s.begin(),s.end());
        string x="";
        permu(s,x);
        return vec;
    }
    void permu(string s,string x)
    {
       if(0==s.size())
        vec.push_back(x);
        for(int i=0;i<s.size();i++)
        {
            if(i>=1&&s[i]==s[i-1])
                continue;
            char m=s[i];
            x.push_back(m);
            s.erase(s.begin()+i);
            permu(s,x);
            s.insert(s.begin()+i,m);
            x.pop_back();
        }
    }
};
```

