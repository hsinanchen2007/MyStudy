```
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size=flowerbed.size();
        if(n==0)return true;
        for(int i=0;i<size;++i)
        {
            if(flowerbed[i]==0)
            {
                if(i==0||flowerbed[i-1]==0)
                {
                    if(i==size-1||flowerbed[i+1]==0)
                    {
                        --n;
                        if(n==0)return true;
                        flowerbed[i]=1;
                    }
                }
            }
        }
        return false;
    }
};
```
