### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        if(A.size()==0)return true;
        sort(A.begin(),A.end());
        map<int,int> mp;
        for(int i=0;i<A.size();i++){
            if(mp.count(A[i]*2)!=0&&mp[A[i]*2]>0){
                mp[A[i]*2]--;
            }
            else if(A[i]%2==0&&mp.count(A[i]/2)!=0&&mp[A[i]/2]>0){
                mp[A[i]/2]--;
            }
            else{
                if(mp.count(A[i])==0){
                    mp[A[i]]=1;
                }
                else{
                    mp[A[i]]++;
                }
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second!=0)return false;
        }
        return true;
    }
};
```