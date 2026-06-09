### 解题思路
1. 首先对房间houses和取暖器heaters排序
2. 遍历房间，并用二分法计算各个房间与所有取暖器的最近的距离，距离房间最近的取暖器距离即为所需半径
3. 所有房间中所需半径最大的即为取暖器的最小半径

### 代码

```cpp
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size();
        int m = heaters.size();
        int max_n = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for(int i = 0; i < n; i++)
        {
            int left = 0;
            int right = m-1;
            int min_n = abs(heaters[m-1] - houses[i]);
            while(left<=right)
            {
                int mid = int((left+right)/2);
                if(heaters[mid] >= houses[i])
                {
                    int t = heaters[mid] - houses[i];
                    if(mid <= 0)
                    {
                        min_n = min_n<t?min_n:t;
                        break;
                    }
                    else if(heaters[mid-1] <= houses[i])
                    {
                        min_n = min_n<t?min_n:t;
                        t = houses[i] - heaters[mid-1];
                        min_n = min_n<t?min_n:t;
                        break;
                    }
                    else
                        right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            max_n = max_n>min_n?max_n:min_n;
        }
        return max_n;
    }
};
```