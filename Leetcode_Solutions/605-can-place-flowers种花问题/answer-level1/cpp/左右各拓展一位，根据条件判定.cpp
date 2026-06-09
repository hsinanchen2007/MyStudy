### 解题思路
挖坑，埋萝卜

### 代码

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //算三个连续的0,给整个数组扩展一下。
        vector<int> index(flowerbed.size()+2,0);
        for(int i=1;i<index.size()-1;i++){
            index[i] = flowerbed[i-1];
        }
        for(int i=1;i<index.size()-1;i++){
            if(index[i-1] == 0 && index[i] == 0 && index[i+1] == 0){
                n--;
                index[i] = 1;
            } 
        }
        if(n > 0) return false;
        else return true; 

    }
};
```