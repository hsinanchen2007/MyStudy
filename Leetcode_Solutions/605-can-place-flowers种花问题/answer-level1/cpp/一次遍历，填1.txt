``` C++
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.empty()) return false;
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i]==0                              //当前位置为0
              &&(i-1==-1||flowerbed[i-1]==0)                //前一位置为0，或索引为-1
              &&(i+1==flowerbed.size()||flowerbed[i+1]==0)) //后一位置为0，或索引为flowerbed.size()
            {
                n--;
                flowerbed[i]=1;                
            }        
        }
        return n<=0?true:false;
    }
};
```