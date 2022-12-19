### 解题思路
此处撰写解题思路

### 代码

```cpp
int sum = 0;
int cnt = 0;
struct node{
    int data[27];
    void init(){
        for(int i = 0;i<26;i++){
            data[i]=-1;
        }
    }
}tree[140000+50];
void buildtree(string s){
    int p= 0;
    for(int i = s.length()-1 ; i>=0 ; i--){
        int x = s[i]-'a';
        if(tree[p].data[x]==-1){
            tree[p].data[x]=++cnt;
            tree[cnt].init();
        }
        p = tree[p].data[x];
    }
}
bool check(int n){
    for(int i = 0;i<26;i++){
        if(tree[n].data[i]!=-1){
            return false;
        }
    }
    return true;
}
void dfs(int n,int ans){
    if(check(n)){
        sum+=(ans+1);
        return ;
    }
    for(int i = 0;i<26;i++){
        if(tree[n].data[i]!=-1){
            dfs(tree[n].data[i],ans+1);
        }
    }
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        cnt = 0;
        sum = 0;
        tree[cnt].init();
        for(auto v:words){
            buildtree(v);
        }
        dfs(0,0);
        return sum;
    }
};
```