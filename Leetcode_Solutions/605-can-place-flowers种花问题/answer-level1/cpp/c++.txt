```
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
         flowerbed.insert(flowerbed.begin(),0);
         flowerbed.insert(flowerbed.end(),0);
         int count=0,ans=0;
         for(int i=0;i<flowerbed.size();i++){
              if(flowerbed[i]==0)
                  count++;
              else
                  count=0;
              if(count==3){
                  ans++;
                  count=1;
              }
         }
         return ans>=n?true:false;
    }
};
```