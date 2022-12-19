用一个记录每个人通知所需的时间。对每一个员工寻找找他的主管，并更新其通知所需的时间，更新成功（时间更大）时继续往上找上级主管。

```
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> v(n,0);
        for(int i=0;i<n;++i){
            int m=i;
            int t=0;
            while((m=manager[m])!=-1){
                t+=informTime[m];
                if(t<=v[m]) break;
                v[m]=t;
            }
        }
        return *max_element(v.begin(),v.end());
    }
};
```
