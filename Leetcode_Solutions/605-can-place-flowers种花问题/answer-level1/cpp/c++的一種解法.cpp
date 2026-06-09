### 解题思路
查看前後花壇位置是否為0，單獨討論首尾花壇位置。
注意使用固定數組時考慮數組大小，前提爲size()大於2才可使用flowerbad[1]

### 代码

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        if(flowerbed.size()==1)
        {
         if(n==1&&flowerbed[0]==0)    return true;
         else return false;
        }

        if(flowerbed[0]==0&&flowerbed[1]==0)
        {
            flowerbed[0]=1;
            n--;
            if(n==0) return true;
        }
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i-1]==0&&flowerbed[i+1]==0&&flowerbed[i]==0)
            {
                flowerbed[i]=1;
                i++;//跳過後面相鄰的一位
                n--;
                if(n==0) return true;
            }
        }
        if(flowerbed[flowerbed.size()-1]==0&&flowerbed[flowerbed.size()-2]==0&&n==1) return true;
        return false;
    }
};
```