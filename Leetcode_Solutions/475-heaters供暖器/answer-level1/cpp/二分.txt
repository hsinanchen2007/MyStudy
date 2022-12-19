### 解题思路
先将供暖期位置的数组排序，然后遍历房屋位置数组
- 对每个房屋通过二分法找到离之最近的供暖器并计算距离len
- 如果len比之前求出的最大半径res大则更新res

### 代码

```cpp
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res=0;
        sort(heaters.begin(),heaters.end());
        for(int h : houses){
            int l=0,r=heaters.size()-1;
            while(l<r){
                int mid=l+r>>1;
                if(heaters[mid]>=h) r=mid;
                else l=mid+1;
            }
            res=max(res,min(abs(h-heaters[l]),l-1>=0?abs(h-heaters[l-1]):INT_MAX));
        }
        return res;
    }
};
```