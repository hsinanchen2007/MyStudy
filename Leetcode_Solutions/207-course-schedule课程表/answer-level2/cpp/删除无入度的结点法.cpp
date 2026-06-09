### 解题思路
用集合存储已经删除的结点，所以只有当关系的前者不在这个集合
内时才判断这个关系，如果这个关系还需要判断，则标记关系的后者
有入度，所有关系处理完后，寻找第一个没有入度的点，加入集合，
如果找不到，则返回false，如果全部删除，则返回true

### 代码

```cpp
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        int i,j,m=pre.size(),a[n];
        set<int>q;
        while(q.size()<n){
            memset(a,0,sizeof(a));
            for(i=0;i<m;i++){
                if(pre[i][0]==pre[i][1])return false;
                if(!q.count(pre[i][0])){
                    a[pre[i][1]]=1;
                }
            }
            for(i=0;i<n;i++){
                if(!q.count(i)&&a[i]==0){
                    q.insert(i);break;
                }
            }
            if(i>=n)return false;
        }
        return true;
    }
};
```