### 解题思路
深度优先搜索。使用map来记录某个数在某个位置是否已经被使用过，若未使用，则对其进一步判断，若已使用，则跳过。
![image.png](https://pic.leetcode-cn.com/ffcadecd90c8fbf4f318cfe0edb16641e0c17bbf92069b9a570458863b4d7c10-image.png)

### 代码

```cpp
class Solution {
public:
struct node
{
    int val;
    vector<int>next;
}nodes[12];
map<int,int>mp[13];
long long res=0;
bool access[12];
int leng;
void dfs(int curr,int pos){
    if(curr==leng){
        res++;
        return;
    }
    access[pos]=true;
    for(int i=0;i<nodes[pos].next.size();i++){
        if(access[nodes[pos].next[i]])
            continue;
        if(mp[curr].count(nodes[nodes[pos].next[i]].val)==0)
        mp[curr][nodes[nodes[pos].next[i]].val]=1;
        else continue;
            dfs(curr+1,nodes[pos].next[i]);
    }
     access[pos]=false;
     mp[curr].clear();
}
    int numSquarefulPerms(vector<int>& A) {
        if(A.size()==1)
        {
            return 1;
        }
        res=0;
        leng=A.size();
        for(int i=0;i<leng;i++)
        {
            for(int j=i+1;j<leng;j++)
            {
            if(i==j)
            continue;
            int sq=sqrt(A[i]+A[j]);
            if(sq*sq==A[i]+A[j])
            nodes[i].next.push_back(j),nodes[j].next.push_back(i);
            }
            nodes[i].val=A[i];
        }
        map<int,int>mp2;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A.size();j++)
                access[j]=false;
            if(mp2.count(nodes[i].val)==0)
                mp2[nodes[i].val]=1;
            else continue;
            dfs(1,i);
        }
        return res;
    }
};
```