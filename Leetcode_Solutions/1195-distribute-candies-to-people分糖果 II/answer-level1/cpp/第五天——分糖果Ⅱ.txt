### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        if(candies == 0) return result;
        int m = 1, n = 0; //每次给m颗糖，每次给第(n+1)个人
        candies -= m;
        
        while(candies > 0){
            result[(n++)%num_people] += m;
            m = ((candies-m-1)>0?(m+1):candies);
            candies -= m;
        }
        result[n%num_people] += m;

        return result;
    }
};
```