```
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)return true;
        if(flowerbed.size()==0)return false;
        int num2=flowerbed[0]==1?0:1;//新增的1
        flowerbed[0]=1;
        for(int i=1;i<flowerbed.size();++i){
            if(flowerbed[i]==1&&flowerbed[i-1]==1){
                --num2;
                
            }
            else if(flowerbed[i]==0&&flowerbed[i-1]==0){
                flowerbed[i]=1;
                ++num2;
            }
            
        }
        return n<=num2;
    }
};
```
