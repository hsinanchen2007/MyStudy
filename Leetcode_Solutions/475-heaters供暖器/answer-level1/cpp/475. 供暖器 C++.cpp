### 解题思路
1.先将房屋与供暖器排序，找到房屋离最近供暖气的距离，再取所有距离中的最大值。

### 代码

```cpp
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
         const int h1 = houses.size(), h2 = heaters.size();
        if(!is_sorted(houses.begin(),houses.end())){
            sort(houses.begin(),houses.end());
        }

        if(!is_sorted(heaters.begin(),heaters.end())){
            sort(heaters.begin(),heaters.end());
        }

        heaters.push_back(2000000000);
        int r = 0,i = 0;
        if(houses[0]<heaters[0]){
            r = heaters[0] - houses[0];
            if(houses[h1 - 1] <= heaters[0])
                return r;
            while(houses[++i] < heaters[0]);
        }
        for(int R,j = 0;i < h1 && j < h2;i++){
            while(houses[i]<heaters[j]||houses[i]>heaters[j+1]){
                j++;
            }
            r = max(r,min(houses[i]-heaters[j],heaters[j+1]-houses[i]));
        }
        return r;
    }
};
```