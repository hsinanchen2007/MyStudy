### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        int k=0;
        for(int i=0;;i++)
        {
            if(i==num_people)
            {
                i=0;
                k++;
            }
            if(candies>i+1+k*num_people)
            {
                ans[i]+=i+1+k*num_people;
                candies=candies-(i+1+k*num_people);
            }
            else
            {
                ans[i]+=candies;
                break;
            }
        }
        return ans;
    }
};
```