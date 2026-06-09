### 解题思路
贪心思想
先按照收益最大排序,工作能力大的工人先干收益大的
比他能力小的工人只能和之前工人的收益相同甚至更小

### 代码

```cpp
class Solution {
public:
    struct node{
        int d;
        int p;
    };
    static bool cmp(const node &a,const node &b){
        if(a.p==b.p) return a.d<b.d;
        return a.p>b.p;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<node>mp;
        node tmp;
        for(int i=0;i<difficulty.size();i++){
            tmp.d=difficulty[i];
            tmp.p=profit[i];
            mp.push_back(tmp);
        }
        sort(mp.begin(),mp.end(),cmp);
        sort(worker.begin(),worker.end());
        int res=0,i,j=0;
        for(i=worker.size()-1;i>=0;i--){
            while(j<mp.size()){
                if(mp[j].d<=worker[i]){
                    res+=mp[j].p;break;
                }
                else j++; 
            }
        }
        return res;
    }
};
```