### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> tmp(num_people,0);
        int i=1;
        while(candies>0)
        {
            if(candies>i)
            {
                tmp[(i-1)%num_people]+=i;
                candies-=i;
            }
            else
            {
                tmp[(i-1)%num_people]+=candies;
                break;
            }
            ++i;
        }
        return tmp;
    }
};
```