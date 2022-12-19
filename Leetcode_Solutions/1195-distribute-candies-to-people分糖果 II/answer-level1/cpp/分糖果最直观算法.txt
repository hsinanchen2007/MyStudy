### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>res(num_people,0);
        int count=0;
        while(candies>0)
        {
            if(candies>count)
                res[count%num_people]+=count+1;
            else
                res[count%num_people]+=candies;
            count++;
            candies-=count;
        }
        return res;
    }
};
```