### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> v;
    vector<int> hashtable;
    int count=0; 
    void dfs(int n,int index){
       if(index==n+1)
       {
            count++;
            return;
       }
       for(int i=1;i<=n;++i){
           if(hashtable[i]==false){
               v[index]=i;
               if(index%i!=0&&i%index!=0)
                  continue;
               hashtable[i]=true;
               dfs(n,index+1);
               hashtable[i]=false;
           }
       }
    }
    int countArrangement(int N) {
         v.resize(N+1);
         hashtable.resize(N+1);
         dfs(N,1);
         return count;
    }
};
```