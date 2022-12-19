### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.insert(flowerbed.end(),0);
        int count = 0;
        for(int i = 1; i < flowerbed.size() - 1; i++){
            if(flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0){
                flowerbed[i++] = 1;
                count ++;
            }
        }
        return n <= count;
    }
};
```