## 思路
如果当前位置为 0， 则考虑前后是否为 0，在判断前后时添加边界限制条件。（充分利用短路原理）

### 代码
```c++
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();        
        for (int i = 0; i < size; ++i) {
            if ((i == 0 || flowerbed[i-1] == 0) && flowerbed[i] == 0 && (i+1 == size || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                --n;                
                if (n == 0) {
                    break;
                }
            }
        }
        return n > 0 ? false : true;
    }
};
```
