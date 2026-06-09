### 解题思路


### 代码

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        if(piles.size() == 0)
            return 0;
        int maxx = -1;
        for(auto pile : piles)
            maxx = max(maxx, pile);
        int left = 1, right = maxx;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(int i = 0 ; i < piles.size() ; ++i)
            {
                if(piles[i] < mid)
                    cnt += 1;
                else
                {
                    if(piles[i] % mid == 0)
                        cnt += piles[i] / mid;
                    else
                        cnt += piles[i] / mid + 1;
                }
            }
            if(cnt <= H)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }   
};
```