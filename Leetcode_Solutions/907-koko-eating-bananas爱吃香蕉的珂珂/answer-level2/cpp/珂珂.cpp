### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool  keke(int m,vector<int>& piles, int H){
        int res=0;
        for(int i=0;i<piles.size();i++){
            res=res+1+(piles[i]-1)/m;
            if(res>H)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
         int r=0,l=1,mid;
         for(int i=0;i<piles.size();i++){
             r=max(r,piles[i]);
         }
         while(l<r){
             
             mid=(l+r)/2;
             if(keke(mid,piles,H))r=mid;
             else l=mid+1;
             cout<<l<<"-"<<r<<endl;
         }
         return l;
    }
};
```