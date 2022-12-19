```
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int n = candies.size()>>1;
        map<int,int> v;
        int temp=0;
        for(int i=0;i<candies.size();i++){
           if(v[candies[i]]==0){
               v[candies[i]]++;
               temp++;
           }
        }
        if(temp>=n) return n;
        return temp;
    }
};
```
