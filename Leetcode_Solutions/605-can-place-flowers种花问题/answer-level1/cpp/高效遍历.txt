### 解题思路
根据下一个点是否为1 来提高遍历效率。

### 代码

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(m==1){
            if(!flowerbed[0])n--;
            return n<=0;
        }
        int i=0;
        if(!flowerbed[i+1]){
            if(!flowerbed[i])
                n--;
            if(n<=0)return true;
            i += 2;
        } else if(flowerbed[i+1]){
            i += 3;
        }
        for(;i<flowerbed.size()-1;){
            if(flowerbed[i+1]){
                i += 3;
            } else {
                if(!flowerbed[i-1] && !flowerbed[i]){
                    n--;
                    if(n<=0)return true;
                }
                i += 2;
            }
        }
        if(i == flowerbed.size()-1){
            if(!flowerbed[i-1] && !flowerbed[i]){
                n--;
                if(n<=0)return true;
            }
        }
        return n<=0;
    }
};
```