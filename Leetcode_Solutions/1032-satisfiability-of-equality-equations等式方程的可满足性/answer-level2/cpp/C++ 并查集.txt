### 解题思路
先处理等式，让它们合并，连成一个连通块。再处理不等号，若发现两端的字符在同一集合里，返回false。
所有方程处理完，返回true。
### 代码

```cpp
class Solution {
public:
    vector<int>fa;
    int find(int x)
    {
        while(x!=fa[x]) x = fa[x];
        return x;
    }
    bool Union(int x,int y)
    {
        int fa_x = find(x);
        int fa_y = find(y);
        if(fa_x!=fa_y)
        {
             fa[fa_x] = fa_y;
             return true;
        }
        return false;      
    }
    bool equationsPossible(vector<string>& equ) {
        if(equ.empty()) return false;
        unordered_map<char,int>mp;
        int n = 2*equ.size();
        int last = n-1;
        fa.resize(n);
        for(int i=0;i<n;++i) fa[i]=i;
        vector<string>tmp;
        for(int i=0;i<equ.size();++i)
        {
            if(equ[i][0]==equ[i][3] && equ[i][1]=='!') return false;
            if(equ[i][1]=='!')
            {
                tmp.push_back(equ[i]);
                continue;
            }
            char first = equ[i][0];
            char second = equ[i][3];
            char c = equ[i][1]; 
            
            if(mp.count(first)&&mp.count(second))
            {
               
                Union(mp[first],mp[second]);
               
            }
            else if(mp.count(first)&& !mp.count(second))
            {
                mp[second] = i;
                Union(mp[first],mp[second]);
            }
            else if(!mp.count(first)&& mp.count(second))
            {
                mp[first] = i;
                Union(mp[first],mp[second]);
            }
            else
            {
                
                    mp[first] = i;
                    mp[second] = i;
                    
            }
            
        }
        for(int i=0;i<tmp.size();++i)
        {
            string t = tmp[i];
            if(mp.count(t[0])&&mp.count(t[3]))
            {
                if(find(mp[t[0]])==find(mp[t[3]]))
                   return false;
            }
        }
        return true;

    }
};
```