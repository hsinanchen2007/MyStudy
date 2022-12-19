### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> list(num_people,0);
        int i=0,j=1;
        while(candies>=j)
        {
            if(i>num_people-1)i=0;
            list[i]+=j;
            i++;
            candies-=j;
            j++;
            if(candies<j&&i<num_people)list[i]+=candies;
            if(candies<j&&i==num_people)list[0]+=candies;
        }
        return list;
    }
};
```