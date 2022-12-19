### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {

        vector<int> s(num_people,0);
        int n =0;
        int m = 1;
        for(int i = 0 ;  candies>0 ; )
        {
            int temp = m++ + n * num_people ;
            if(candies > temp)
            {
                s[i] += temp;
                candies -= temp;
            }
            else
            {
                s[i] += candies;
                break;
            }
            if(i == num_people-1)
            {
                n++;
                m=1;
            }
            i++;
            i = i % num_people;
        }
        return s;
    }
};
```