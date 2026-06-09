### 解题思路

循环

### 代码

```cpp
class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        long index = 0;
        vector<int> res(num_people, 0);
        while (candies >= index + 1)
        {
            res[index % num_people] += index + 1;
            index++;
            candies -= index;
        }

        res[index % num_people] += candies;
        return res;
    }
};
```