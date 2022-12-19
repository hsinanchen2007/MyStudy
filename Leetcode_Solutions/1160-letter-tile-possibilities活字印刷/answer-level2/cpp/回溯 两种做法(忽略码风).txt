- 写了两个版本的，一个使用hash去重,一个用check判重

1. hash去重这个思路很容易想到,但效率不高且占很多空间。
 ```c++
class Solution {
public:
    int res,n;
    unordered_map<string,int>hash;
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        if(!n)return 0;
        string temp="";
        for(int i=1;i<=n;i++)dfs(tiles,temp,0,i);   //根据串长度来递归
        return res;
    }
    void dfs(string &s,string &current, int vis, int remain){   //vis标记该位置是否用过(因为最多7个元素，所以用一个int足够表示了)
        if(remain==0 && hash[current]==0){
            res++;
            hash[current]=1;
            //cout<<current<<" ";
            return ;
        }
        for(int i=0;i<n;i++){
            if(vis & 1<<i)continue;
            vis|=1<<i;
            current+=s[i];
            dfs(s,current,vis,remain-1);
            vis -= 1<<i;
            current.pop_back();
        }
    }
};
```

2. 剪枝回溯
- 可以稍微分析一下,遍历到下标为index的元素时,如果index之前的元素0~index-1中存在s[k]==s[index]说明
- 当前方案在使用下标为k的方案里已经考虑过了直接判断下一个状态即可。此方案效率高,且使用的空间为常数。
```cpp
class Solution {
public:
    int res,n,vis;
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        if(!n)return 0;
        for(int i=1;i<=n;i++)dfs(tiles,vis,i);
        return res;
    }
    void dfs(string &s, int &vis, int remain){
        if(remain==0){
            res++;
            return ;
        }
        for(int i=0;i<n;++i){
            if(vis & 1<<i)continue;
            if(check(s,vis,i))continue; //去重复
            vis|=1<<i;
            dfs(s,vis,remain-1);
            vis -= 1<<i;
        }
    }
    bool check(string &s,int &vis,int &end){
            for(int i=0;i<end;++i){
                if(s[i]==s[end] && !(vis & (1<<i)))return true; //如果之前有相同的元素且没用过则说明在这之前已经当前方案在之前已被计算过
            }
            return false;
        }
};
```

3. 剪枝回溯debug版本。。。
```c++
class Solution {
public:
    int res,n;
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        if(!n)return 0;
        string temp="";
        for(int i=1;i<=n;i++)dfs(tiles,temp,0,i);
        return res;
    }
    void dfs(string &s,string &current, int vis, int remain){
        if(remain==0){
            res++;
            cout<<current<<" ";
            return ;
        }
        for(int i=0;i<n;i++){
            if(vis & 1<<i)continue;
            if(check(s,vis,i))continue;
            vis|=1<<i;
            current+=s[i];
            dfs(s,current,vis,remain-1);
            vis -= 1<<i;
            current.pop_back();
        }
    }
    bool check(string &s,int vis,int end){
            for(int i=0;i<end;i++){
                if(s[i]==s[end] && !(vis & (1<<i)))return true;
            }
            return false;
    }
};
```