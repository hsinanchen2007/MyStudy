### 解题思路
覆盖每一个房子的最短半径肯定是离他最近的取暖器，将所有最近距离的最大值为最小半径

### 代码

```cpp
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int len1=houses.size();
        int len2=heaters.size();
        /*int Min=(heaters[0]>=houses[0])?(heaters[0]-houses[0]):INT_MIN;
        if(heaters[len2-1]<=houses[len1-1]){
            Min=max(houses[len1-1]-heaters[len2-1],Min);
        }
        if(len2==1)return Min;
        for(int i=1;i<len2;i++){
            Min=max((heaters[i]-heaters[i-1])/2,Min);
        }
        */
        int j=0;
        int Min=INT_MIN;
        for(int i=0;i<len1;i++){
            int min_d=abs(houses[i]-heaters[j]);
            while(j<len2 && houses[i]>=heaters[j]){
                min_d=min(min_d,houses[i]-heaters[j]);
                j++;
            }
            if(j==len2){
                Min=max(houses[len1-1]-heaters[len2-1],Min);
                return Min;
            }
            min_d=min(min_d,heaters[j]-houses[i]);
            if(j>0)j--;
            Min=max(Min,min_d);
            
        }
        return Min;
    }
};
```