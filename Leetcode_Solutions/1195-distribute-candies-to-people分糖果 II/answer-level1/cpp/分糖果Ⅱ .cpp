### 解题思路
简单的遍历，做的一般，希望大佬多多指导
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> distributeCandies(num_people,0);
        for(int distribute=0;;distribute++)
        {
            if(candies>=distribute+1)
            {
                distributeCandies[distribute%num_people]+=distribute+1;
                candies-=distribute+1;
            }
            else
            {
                distributeCandies[distribute%num_people]+=candies;
                break;
            }
        }
        return distributeCandies;
    }
};
```