### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);

        for(int i=0,j=1;candies>0;i++,j++)
        {
            if(candies-j>=0)
            {
                ans[i%(num_people)]+=j;
                candies-=j;
            }
            else
            {
                ans[i%(num_people)]+=candies;
                candies-=candies;
            }    
        }

        return ans;
    }
};
```