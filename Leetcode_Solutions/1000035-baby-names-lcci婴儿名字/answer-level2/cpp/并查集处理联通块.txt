每个名字看做一个点，把相同的名字用一条边相连，这样能构成若干个联通块，输出每个块的频率总和以及块中字典序最小的名字。
ps：这字符串处理才比较烦好吧。。。。以及不知道为啥跑这么慢，难道是STL常数巨大
```cpp
class Solution {
    vector<int> Fa;
    vector<int> Size;
    vector<string> Name;
    unordered_map<string,int> pos;
    int getFa(int x) {return x==Fa[x]?x:Fa[x]=getFa(Fa[x]);}
    void link(int x,int y)
    {
        x=getFa(x);
        y=getFa(y);
        if (x==y) return ;
        Fa[x]=y;
        Size[y]+=Size[x];
        if (Name[y]>Name[x]) Name[y]=Name[x];
    }
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& e) {
        int n=names.size();
        Fa=vector<int>(n);
        Size=vector<int>(n);
        Name=vector<string>(n);
        for (int i=0;i<n;++i)
        {
            Fa[i]=i;
            string s;
            int v=0;
            int len=names[i].size();
            int p=0;
            while (names[i][p]!='(') s.push_back(names[i][p]),++p;
            ++p;
            while (names[i][p]!=')') v=v*10+names[i][p]-'0',++p;
            Size[i]=v;
            Name[i]=s;
            pos[s]=i;
        }
        int m=e.size();
        for (int i=0;i<m;++i)
        {
            string s;
            int a,b;
            int len=e[i].size();
            int p=1;
            while (e[i][p]!=',') s.push_back(e[i][p]),++p;
            ++p;
            a=pos[s];
            s.clear();
            while (e[i][p]!=')') s.push_back(e[i][p]),++p;
            b=pos[s];
            link(a,b);
        }
        vector<string> Ans;
        vector<bool> Mark(n,0);
        for (int i=0;i<n;++i)
        {
            int x=getFa(i);
            if (!Mark[x])
            {
                Name[x].push_back('(');
                string s;
                int v=Size[x];
                while (v) s.push_back(v%10+'0'),v/=10;
                for (int i=0,j=s.size()-1;i<j;++i,--j) swap(s[i],s[j]);
                Name[x]+=s;
                Name[x].push_back(')');
                Ans.push_back(Name[x]);
                Mark[x]=true;
            }
        }
        return Ans;
    }
};
```