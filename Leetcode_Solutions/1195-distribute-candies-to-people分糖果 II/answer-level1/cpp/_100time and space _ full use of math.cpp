### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int num=sqrt(2*candies);
        int left=candies-(num+1)*num/2;
        if(left<0)
        {
            num--;
            left=candies-(num+1)*num/2;
        }
        int roud=num/num_people;
        int le=num-roud*num_people;

        vector<int> fin(num_people);
        for(int i=0;i<num_people;i++)
        {
            fin[i]=(i+1+i+1+(roud-1)*num_people)*roud/2;
        }

        int j=0;
        for(;j<le;j++)
            fin[j]+=j+1+roud*num_people;
        fin[j]+=left;
        return fin;
    }
};
```