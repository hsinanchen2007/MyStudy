### 解题思路
只需要求出花坛最多还能放多少花盆num>=n就成立。
遍历数组每个元素，如果元素为0，且两边都为零，那么num+1，该下标元素变为1，遍历下一元素。

### 代码

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int num=0;
        
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i]==0 && ((i-1>=0 && flowerbed[i-1]==0) || i==0) && ((i+1<flowerbed.size() && flowerbed[i+1]==0) || i==flowerbed.size()-1))
            {
                flowerbed[i]=1;
                num++;
            }
        }
        
        return num>=n;

    }
};
```