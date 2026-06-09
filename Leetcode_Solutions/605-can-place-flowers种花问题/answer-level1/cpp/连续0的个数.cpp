### 解题思路
先处理头尾连续0的个数，假设头或尾有连续x个0，则可以重x/朵花
中间连续y个0可以种(y+1)/2-1朵
算出来一共可以种多少和n比较
O(n)

### 代码

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n>(flowerbed.size()+1)/2) return false;
        int flowers=0,first=flowerbed.size(),last=-1;
        for(int i=0;i<flowerbed.size();i++)
            if(flowerbed[i] == 1) {first=i;break;}
        if(first == flowerbed.size()) return true;//空花坛
        for(int i=flowerbed.size()-1;i>=0;i--)
            if(flowerbed[i] == 1) {last=i;break;}
        for(int i=first;i<last;i++)
        {
            int zerocount=1;
            if(flowerbed[i] == 0)
            {
                int j=i;
                while(flowerbed[j] == 0 && j<last) {zerocount++;j++;}
                flowers+=zerocount/2-1;
                i=j;
            }
            
        }
        return (flowers+first/2+(flowerbed.size()-1-last)/2)>=n?true:false;

    }
};
```