### 解题思路
最开始分好每一个块，然后套模板去区间查询，线段树，应该也可以过。

### 代码

```cpp
const int maxn=3e4+50;
#define FOR(i,x,n) for(register int i=x;i<=n;++i)
class Solution {
public:
    int blo[maxn],bsz,sz,tag[maxn];
    void init(const vector<int>&arr){
        memset(tag,0,sizeof tag);
        sz=arr.size();
        bsz=sqrt(sz);
        FOR(i,1,sz)blo[i]=(i-1)/bsz+1;
        FOR(i,1,sz)tag[(i-1)/bsz+1]^=arr[i-1];
    }
    int query(int l,int r,const vector<int>&arr){
        l++,r++;
        int rev=0;
        FOR(i,l,min(r,blo[l]*bsz))rev^=arr[i-1];
        if(blo[l]!=blo[r])
            FOR(i,(blo[r]-1)*bsz+1,r)rev^=arr[i-1];
        FOR(i,blo[l]+1,blo[r]-1)rev^=tag[i];
        return rev;
    }
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>xorAns;
        init(arr);
        for(auto iter:queries){
            xorAns.push_back(query(iter[0],iter[1],arr));
        }
        return xorAns;
    }
};
```