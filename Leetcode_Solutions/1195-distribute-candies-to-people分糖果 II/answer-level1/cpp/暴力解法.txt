### 解题思路
暴力解法

### 代码

```cpp
class Solution 
{
public:
    vector<int> distributeCandies(int candies, int num_people) 
    {
        vector<int> res;
        for(int i = 0; i < num_people; i++)
        {
            res.push_back(0);
        }

        int candy_flag = 1;
        int num_wheel = 0;
        while(candy_flag)
        {
            for(int i = 1; i < res.size()+1; i++)
            {
                if(candies >= (num_wheel*num_people  + i))
                {
                    int sum_temp = res[i-1] + num_wheel*num_people  + i;
                    res[i-1] = sum_temp;
                    candies = candies - (num_wheel*num_people  + i);
                }
                else
                {
                    int sum_temp = res[i-1] + candies;
                    res[i-1] = sum_temp;
                    
                    candy_flag = 0;
                    break;
                }
            }
            
            num_wheel++;
        }
        return res;
    }
};
```